#include "stm32f0xx.h"
#include "clock.h"
#include "usart.h"
#include "timer.h"
#include "touch.h"
#include "light_control.h"


int main(void)
{
    uint32_t now;
    uint32_t last_touch_time = 0;

    // 系统时钟初始化，配置48MHz系统时钟
    clock_init();

    // 串口初始化
    usart_init(115200);

    // 触摸初始化
    touch_init();

    // 灯光控制初始化
    light_control_init();

    // 1ms定时器初始化
    tim2_init();

    while (1)
		{
        // 获取当前系统时间
        now = get_sys_time_ms();

        // 10ms扫描一次触摸按键
        if (now - last_touch_time >= 10)
				{
            // 更新上一次触摸时间
            last_touch_time = now;

            // 处理触摸按键扫描
            touch_scan();

            // 处理灯光控制
            light_control_process();
        }
    }
}
