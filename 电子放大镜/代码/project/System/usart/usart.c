#include "usart.h"
#include "stdio.h"

// USART初始化
void usart_init(uint32_t baudrate)
{
    // 开启GPIOB时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

    // 开启USART1时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    // 配置USART1引脚
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // 配置引脚复用功能
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_0);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_0);

    // 配置USART1
    USART_InitTypeDef USART_InitStructure;
    USART_InitStructure.USART_BaudRate = baudrate;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART_InitStructure);

    // 使能USART1
    USART_Cmd(USART1, ENABLE);
}

// pfintf重定向
int fputc(int ch, FILE *f)
{
    // 等待数据寄存器为空
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
        ;

    // 发送一个字节数据
    USART_SendData(USART1, (uint8_t)ch);

    return ch;
}
