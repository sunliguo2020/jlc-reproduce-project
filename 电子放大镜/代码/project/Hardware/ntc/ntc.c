#include "ntc.h"
#include "math.h"

// NTC参数
#define NTC_R25 10000.0f // 25摄氏度时的电阻值
#define NTC_B 3450.0f    // B值
#define NTC_R0 10000.0f  // 电路中串联的电阻值

#define NTC_T25 298.15f // 25摄氏度时的绝对温度值

// NTC初始化
void ntc_init(void)
{
    // 开启GPIOB时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

    // 开启ADC1时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

    // 配置ADC时钟
    ADC_ClockModeConfig(ADC1, ADC_ClockMode_SynClkDiv4);

    // 配置NTC引脚
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // 配置ADC1
    ADC_InitTypeDef ADC_InitStructure;
    ADC_StructInit(&ADC_InitStructure);
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ScanDirection = ADC_ScanDirection_Upward;
    ADC_Init(ADC1, &ADC_InitStructure);

    // 配置ADC1通道8
    ADC_ChannelConfig(ADC1, ADC_Channel_8, ADC_SampleTime_239_5Cycles);

    // ADC校准
    ADC_GetCalibrationFactor(ADC1);

    // 开启ADC
    ADC_Cmd(ADC1, ENABLE);
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_ADRDY) == RESET)
        ;
}

// 读取ADC原始值
uint16_t ntc_get_adc(void)
{
    uint32_t adc_sum = 0;
    for (int i = 0; i < 10; i++)
    {
        // 启动一次ADC转换
        ADC_StartOfConversion(ADC1);
        // 等待转换完成
        while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET)
            ;
        // 累加ADC数值
        adc_sum += ADC_GetConversionValue(ADC1);
    }

    // 返回10次ADC平均值
    return adc_sum / 10;
}

// 读取ADC平均温度
float ntc_get_temperature(void)
{
    float resistance;  // NTC电阻值
    float temperature; // 温度值

    uint16_t adc_value = ntc_get_adc();

    // 防止除零错误
    if (adc_value == 0)
    {
        return 200.0f;
    }

    if (adc_value >= 4095)
    {
        return 200.0f;
    }

    // 计算NTC电阻值
    resistance = NTC_R0 * adc_value / (4095.0f - adc_value);

    // B值公式计算温度
    temperature = 1.0f / (1.0f / NTC_T25 + logf(resistance / NTC_R25) / NTC_B) - 273.15f;

    return temperature;
}
