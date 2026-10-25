#include "light_control.h"
#include "touch.h"
#include "tsc.h"
#include "led.h"
#include "timer.h"
#include "settings.h"
#include "stdbool.h"

// 色温范围
#define COLOR_TEMPERATURE_MIN 4000
#define COLOR_TEMPERATURE_MAX 6500
// 亮度范围
#define BRIGHTNESS_MIN 10
#define BRIGHTNESS_MAX 100
// 无极步进调整
#define COLOR_TEMPERATURE_CONTINUOUS_STEP 15
#define BRIGHTNESS_CONTINUOUS_STEP 1
// 闪烁间隔
#define FLASH_INTERVAL_MS 200

// 过温保护
#define TEMPERATURE_SHUTDOWN 55.0f
#define TEMPERATURE_RECOVER 45.0f

// 固定色温档位
static const uint16_t color_level[] = {4000, 4500, 5000, 5500, 6000, 6500};
// 固定亮度档位
static const uint16_t brightness_level[] = {10, 25, 50, 75, 100};

// 灯开关状态
static bool led_on = false;
// 当前色温
static uint16_t color_temperature = 5000;
// 当前亮度
static uint16_t brightness = 50;

// 闪烁状态
static bool flash_active = false;
static uint8_t flash_step = 0;
static uint32_t flash_time = 0;

// 过温标志
static bool over_temperature_flag = false;

// 闪烁状态通知
static void flash_notify(void)
{
    // 关灯状态下不处理
    if (led_on == false)
    {
        return;
    }

    flash_active = true;
    flash_step = 0;
    flash_time = get_sys_time_ms();

    // 立刻开始第一次闪烁,第一次熄灭
    led_output_off();
}

// 闪烁状态处理
static void flash_process(void)
{
    uint32_t now;

    // 判断闪烁是否激活
    if (flash_active == false)
    {
        return;
    }

    // 获取当前系统时间
    now = get_sys_time_ms();

    // 判断是否达到闪烁间隔
    if (now - flash_time < FLASH_INTERVAL_MS)
    {
        return;
    }

    // 更新闪烁时间
    flash_time = now;

    // 第一次点亮
    if (flash_step == 0)
    {
        led_output_on();
        flash_step = 1;
    }

    // 第二次熄灭
    else if (flash_step == 1)
    {
        led_output_off();
        flash_step = 2;
    }

    // 第二次点亮，闪烁结束
    else
    {
        led_output_on();
        flash_active = false;
        flash_step = 0;
    }
}

// 寻找当前值以上的下一个固定档位
static uint16_t find_upper_level(uint16_t value, const uint16_t *level_array, uint8_t level_count)
{
    // 寻找当前值以上的下一个固定档位
    for (uint8_t i = 0; i < level_count; i++)
    {
        if (value < level_array[i])
        {
            return level_array[i];
        }
    }

    // 达到最大值，返回固定档位最小值循环
    return level_array[0];
}

// 色温短按处理
static void color_temperature_short_press(void)
{
    // 寻找当前色温以上的下一个固定档位
    uint16_t new_color_temperature = find_upper_level(color_temperature, color_level, sizeof(color_level) / sizeof(color_level[0]));

    // 更新当前色温
    color_temperature = new_color_temperature;
    // 设置LED色温
    led_color_temperature_set(color_temperature);

    // 达到最高色温
    if (color_temperature == COLOR_TEMPERATURE_MAX)
    {
        // 触发闪烁状态
        flash_notify();
    }
}

// 色温长按处理
static void color_temperature_long_press(void)
{
    // 达到最大值，循环到最小值
    if (color_temperature >= COLOR_TEMPERATURE_MAX)
    {
        // 继续按住循环会最低档位
        color_temperature = COLOR_TEMPERATURE_MIN;
        led_color_temperature_set(color_temperature);
        return;
    }

    // 增加色温
    color_temperature += COLOR_TEMPERATURE_CONTINUOUS_STEP;

    // 限制最大值
    if (color_temperature >= COLOR_TEMPERATURE_MAX)
    {
        color_temperature = COLOR_TEMPERATURE_MAX;
        led_color_temperature_set(color_temperature);

        // 触发闪烁状态
        flash_notify();
        return;
    }

    led_color_temperature_set(color_temperature);
}

// 亮度短按处理
static void brightness_short_press(void)
{
    // 寻找当前亮度以上的下一个固定档位
    uint16_t new_brightness = find_upper_level(brightness, brightness_level, sizeof(brightness_level) / sizeof(brightness_level[0]));

    // 更新当前亮度
    brightness = new_brightness;
    // 设置LED亮度
    led_brightness_set(brightness);

    // 达到最高亮度
    if (brightness == BRIGHTNESS_MAX)
    {
        // 触发闪烁状态
        flash_notify();
    }
}

// 亮度长按处理
static void brightness_long_press(void)
{
    // 达到最大值，循环到最小值
    if (brightness >= BRIGHTNESS_MAX)
    {
        // 继续按住循环会最低档位
        brightness = BRIGHTNESS_MIN;
        led_brightness_set(brightness);
        return;
    }

    // 增加亮度
    brightness += BRIGHTNESS_CONTINUOUS_STEP;

    // 限制最大值
    if (brightness >= BRIGHTNESS_MAX)
    {
        brightness = BRIGHTNESS_MAX;
        led_brightness_set(brightness);

        // 触发闪烁状态
        flash_notify();
        return;
    }

    led_brightness_set(brightness);
}

// 按键1事件处理（开关）
static void touch1_handler(uint8_t event)
{
    // 判断事件，只响应短按
    if (event != TOUCH_EVENT_SHORT_PRESS)
    {
        return;
    }

    // 当前关闭状态
    if (led_on == false)
    {
        // 过温状态禁止开灯
        if (over_temperature_flag == true)
        {
            return;
        }

        led_on = true;
        led_output_on();
    }

    // 当前开启状态
    else
    {
        // 关闭灯光保存当前设置
        settings_save(brightness, color_temperature);

        led_on = false;

        flash_active = false;
        flash_step = 0;
        flash_time = 0;

        led_output_off();
    }
}

// 按键2事件处理（色温调节）
static void touch2_handler(uint8_t event)
{
    // 短按固定档位调节
    if (event == TOUCH_EVENT_SHORT_PRESS)
    {
        color_temperature_short_press();
    }

    // 长按连续无极调节
    else if ((event == TOUCH_EVENT_LONG_PRESS) || (event == TOUCH_EVENT_PRESS_HOLD))
    {
        color_temperature_long_press();
    }
}

// 按键3事件处理（亮度调节）
static void touch3_handler(uint8_t event)
{
    // 短按固定档位调节
    if (event == TOUCH_EVENT_SHORT_PRESS)
    {
        brightness_short_press();
    }

    // 长按连续无极调节
    else if ((event == TOUCH_EVENT_LONG_PRESS) || (event == TOUCH_EVENT_PRESS_HOLD))
    {
        brightness_long_press();
    }
}

// 灯光控制初始化
void light_control_init(void)
{
    // 初始化LED
    led_init();

    // 设置初始灯光状态
    led_on = false;
    color_temperature = 5000;
    brightness = 50;

    flash_active = false;
    flash_step = 0;
    flash_time = 0;

    over_temperature_flag = false;

    // 读取最后一次保存的设置
    settings_load(&brightness, &color_temperature);

    // 设置LED默认参数
    led_color_temperature_set(color_temperature);
    led_brightness_set(brightness);

    // 默认关闭灯光
    led_output_off();
}

// 灯光控制处理
void light_control_process(void)
{
    uint8_t event1;
    uint8_t event2;
    uint8_t event3;
    bool led_on_before;

    // 处理闪烁状态
    flash_process();

    // 获取3个按键的触摸事件
    event1 = touch_get_event(TOUCH_1);
    event2 = touch_get_event(TOUCH_2);
    event3 = touch_get_event(TOUCH_3);

    // 记录本轮之前的灯光状态
    led_on_before = led_on;

    // 开关
    touch1_handler(event1);

    // 灯光关闭状态下不处理按键2和按键3
    if (led_on_before == false)
    {
        return;
    }

    // 按键1关灯状态下不处理按键2和按键3
    if (led_on == false)
    {
        return;
    }

    // 闪烁提醒时不处理按键2和按键3
    if (flash_active == true)
    {
        return;
    }

    // 色温
    touch2_handler(event2);

    // 如果按键2触发闪烁，本轮不处理按键3
    if (flash_active == true)
    {
        return;
    }

    // 亮度
    touch3_handler(event3);
}

// 过温保护处理
void over_temperature_protection_process(float temperature)
{
    // 如果温度超过过温保护阈值，关闭灯光
    if (temperature >= TEMPERATURE_SHUTDOWN)
    {
        over_temperature_flag = true;
        // 强制关闭灯光
        led_on = false;
        // 取消闪烁
        flash_active = false;
        flash_step = 0;
        flash_time = 0;
        led_output_off();
    }
    // 如果温度低于恢复阈值，允许重新开启灯光
    else if ((over_temperature_flag == true) && (temperature <= TEMPERATURE_RECOVER))
    {
        over_temperature_flag = false;
    }
}