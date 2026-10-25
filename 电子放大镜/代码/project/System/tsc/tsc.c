#include "tsc.h"
#include "stdbool.h"
#include "stm32f0xx_tsc_bits.h"

// 触摸按键原始采样值
static volatile uint16_t tsc_value[3] = {0};

// 当前采集的通道
static volatile uint8_t tsc_current_channel = TOUCH_1;

// TSC采集状态
static volatile bool tsc_busy = false;

// 触摸初始化
void tsc_init(void)
{
    // 开启GPIOA时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

    // 开启TSC时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_TS, ENABLE);

    // 配置采样引脚
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 配置触摸引脚
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 配置引脚复用功能
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_3);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_3);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_3);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_3);

    // 禁止施密特迟滞
    TSC->IOHCR &= ~(TSC_IOHCR_G1_IO1 | TSC_IOHCR_G1_IO2 | TSC_IOHCR_G1_IO3 | TSC_IOHCR_G1_IO4);

    // 采样电容
    TSC->IOSCR = TSC_IOSCR_G1_IO1;

    // 固定使用触摸Group1
    TSC->IOGCSR = TSC_IOGCSR_G1E;

    // 初始化不选择具体触摸通道
    TSC->IOCCR = 0;

    // 配置触摸控制寄存器
    /*
     * TSC参数
     *
     * HCLK = 48MHz
     * PGCLK = HCLK / 32 = 1.5MHz
     *
     * 高电平2个PGCLK
     * 低电平2个PGCLK
     *
     * 最大计数 = 16383
     */
    TSC->CR = TSC_CR_PGPSC_2 | TSC_CR_PGPSC_0 | TSC_CR_CTPH_0 | TSC_CR_CTPL_0 | TSC_CR_MCV_2 | TSC_CR_MCV_1 | TSC_CR_TSCE;

    // 清除中断标志位
    TSC->ICR = TSC_ICR_EOAIC | TSC_ICR_MCEIC;

    // 开启采集完成和最大计数中断
    TSC->IER = TSC_IER_EOAIE | TSC_IER_MCEIE;

    // 开启TSC中断
    NVIC_ClearPendingIRQ(TSC_IRQn);
    NVIC_SetPriority(TSC_IRQn, 1);
    NVIC_EnableIRQ(TSC_IRQn);
}

// 启动一次触摸采集
void tsc_scan(void)
{
    // 检测上一次采集是否完成
    if (tsc_busy)
    {
        return;
    }

    // 选择触摸通道
    switch (tsc_current_channel)
    {
    case TOUCH_1:
        TSC->IOCCR = TSC_IOCCR_G1_IO2;
        break;
    case TOUCH_2:
        TSC->IOCCR = TSC_IOCCR_G1_IO3;
        break;
    case TOUCH_3:
        TSC->IOCCR = TSC_IOCCR_G1_IO4;
        break;
    default:
        break;
    }

    // 清除上一次采集的中断标志位
    TSC->ICR = TSC_ICR_EOAIC | TSC_ICR_MCEIC;

    // 标记状态
    tsc_busy = true;

    // 启动采集
    TSC->CR |= TSC_CR_START;
}

// 获取触摸按键原始采样值
uint16_t tsc_get_value(uint8_t channel)
{
    if (channel > TOUCH_3)
    {
        return 0;
    }

    return tsc_value[channel];
}

// 触摸中断服务函数
void TSC_IRQHandler(void)
{
    // 最大计数错误中断标志
    if (TSC->ISR & TSC_ISR_MCEF)
    {
        // 清除中断标志位
        TSC->ICR = TSC_ICR_MCEIC | TSC_ICR_EOAIC;

        // 切换下一个通道
        tsc_current_channel++;

        if (tsc_current_channel > TOUCH_3)
        {
            tsc_current_channel = TOUCH_1;
        }

        // 清除忙碌标志位
        tsc_busy = false;

        return;
    }

    // 正常采集完成中断标志
    if (TSC->ISR & TSC_ISR_EOAF)
    {
        // 读取采样值
        tsc_value[tsc_current_channel] = TSC->IOGXCR[0] & TSC_IOGXCR_CNT;

        // 清除中断标志位
        TSC->ICR = TSC_ICR_EOAIC | TSC_ICR_MCEIC;

        // 切换下一个通道
        tsc_current_channel++;

        if (tsc_current_channel > TOUCH_3)
        {
            tsc_current_channel = TOUCH_1;
        }

        // 清除忙碌标志位
        tsc_busy = false;

        return;
    }
}