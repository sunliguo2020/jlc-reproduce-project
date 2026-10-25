#include "clock.h"

/**
 * 由于芯片外部没有使用晶振，所以需要配置内部时钟，频率48MHz
 * 注意：该函数必须在其他外设初始化之前调用
 */
void clock_init(void)
{
    // 开启内部48MHz高速时钟
    RCC_HSI48Cmd(ENABLE);

    // 等待内部48MHz高速时钟稳定
    while (RCC_GetFlagStatus(RCC_FLAG_HSI48RDY) == RESET)
        ;

    // 1个Flash周期
    FLASH_SetLatency(FLASH_Latency_1);

    // 配置AHB时钟=48MHz
    RCC_HCLKConfig(RCC_SYSCLK_Div1);

    // 配置APB时钟=48MHz
    RCC_PCLKConfig(RCC_HCLK_Div1);

    // 选择HSI48作为系统时钟
    RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI48);

    // 等待系统时钟切换成功
    while (RCC_GetSYSCLKSource() != 0x0C)
        ;

    // 更新系统时钟变量
    SystemCoreClock = 48000000;
}
