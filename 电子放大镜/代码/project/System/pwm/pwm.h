#ifndef __PWM_H
#define __PWM_H

#include "stm32f0xx.h"

#define LED_6500K GPIO_Pin_8
#define LED_6500K_PIN_SOURCE GPIO_PinSource8
#define LED_4000K GPIO_Pin_9
#define LED_4000K_PIN_SOURCE GPIO_PinSource9
#define LED_PWM_PERIOD 1200

void pwm_init(void);
void led_pwm_set(uint16_t led_6500k_compare, uint16_t led_4000k_compare);

#endif
