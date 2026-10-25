#ifndef __SETTINGS_H
#define __SETTINGS_H

#include "stm32f0xx.h"

void settings_load(uint16_t *brightness, uint16_t *color_temperature);
void settings_save(uint16_t brightness, uint16_t color_temperature);

#endif
