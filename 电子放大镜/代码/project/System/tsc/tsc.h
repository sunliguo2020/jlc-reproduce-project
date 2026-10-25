#ifndef __TSC_H
#define __TSC_H

#include "stm32f0xx.h"

#define TOUCH_1 0
#define TOUCH_2 1
#define TOUCH_3 2

void tsc_init(void);
void tsc_scan(void);
uint16_t tsc_get_value(uint8_t channel);

#endif
