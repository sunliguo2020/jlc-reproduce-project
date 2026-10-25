#ifndef __LED_H
#define __LED_H

#include "stm32f0xx.h"

void led_init(void);
void led_brightness_set(uint16_t brightness);
void led_color_temperature_set(uint16_t color_tempurature);
void led_output_off(void);
void led_output_on(void);

#endif
