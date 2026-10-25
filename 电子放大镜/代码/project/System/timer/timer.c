#include "timer.h"
#include "tsc.h"

// 系统时间，单位为毫秒
static volatile uint32_t sys_time_ms = 0;

// TIM2 1ms定时器初始化
void tim2_init(void)
{
    // 开启TIM2时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    // 配置TIM2参数
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Prescaler = 48 - 1;               // 预分频器，计数频率为48MHz/48=1MHz
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数模式
    TIM_TimeBaseStructure.TIM_Period = 1000 - 1;                // 自动重装载值，计数到1000-1=999时产生更新事件
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     // 时钟分频因子为1
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // 清除更新中断标志位
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    // 使能更新中断
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    // 使能TIM2中断
    NVIC_ClearPendingIRQ(TIM2_IRQn);
    NVIC_SetPriority(TIM2_IRQn, 2);
    NVIC_EnableIRQ(TIM2_IRQn);

    // 启动定时器
    TIM_Cmd(TIM2, ENABLE);
}

// 获取系统运行时间
uint32_t get_sys_time_ms(void)
{
    return sys_time_ms;
}

// TIM2中断服务函数
void TIM2_IRQHandler(void)
{
    // 检查是否为更新中断
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
    {
        // 清除中断标志位
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

        // 系统时间加1ms
        sys_time_ms++;

        // 启动一次触摸采集
        tsc_scan();
    }
}