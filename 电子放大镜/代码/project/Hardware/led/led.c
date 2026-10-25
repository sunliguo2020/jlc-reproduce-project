#include "led.h"
#include "pwm.h"
#include "stdbool.h"

/********************************************************************
 * 为保证不同色温下亮度统一，当前软件设置led亮度最大为16颗灯珠满载功率
 *******************************************************************/

// 整体亮度
static uint16_t led_brightness = 0;

// 整体色温
static uint16_t led_color_temperature = 5250;

// 输出状态
static bool led_output_state = false;

// LED亮度与色温更新
static void led_update(void)
{
    // 色温比例
    uint16_t ratio_6500k;
    uint16_t ratio_4000k;

    // 输出pwm值
    uint16_t pwm_6500k;
    uint16_t pwm_4000k;

    // 判断输出状态
    if (led_output_state == false)
    {
        led_pwm_set(0, 0);
        return;
    }

    // 计算色温比例
    ratio_6500k = (led_color_temperature - 4000) * 1000 / 2500;
    ratio_4000k = 1000 - ratio_6500k;

    // 计算输出pwm值
    pwm_6500k = led_brightness * ratio_6500k / 100;
    pwm_4000k = led_brightness * ratio_4000k / 100;

    led_pwm_set(pwm_6500k, pwm_4000k);
}

// LED初始化
void led_init(void)
{
    pwm_init();
    led_output_state = false;
    led_update();
}

// 亮度设置
void led_brightness_set(uint16_t brightness)
{
    if (brightness > 100)
    {
        brightness = 100;
    }

    led_brightness = brightness;

    led_update();
}

// 色温设置
void led_color_temperature_set(uint16_t color_temperature)
{
    // 色温限幅，范围 4000K~6500K
    if (color_temperature < 4000)
    {
        color_temperature = 4000;
    }
    if (color_temperature > 6500)
    {
        color_temperature = 6500;
    }

    led_color_temperature = color_temperature;

    led_update();
}

// 关闭LED输出
void led_output_off(void)
{
    led_output_state = false;
    led_pwm_set(0, 0);
}

// 恢复LED输出
void led_output_on(void)
{
    led_output_state = true;
    led_update();
}