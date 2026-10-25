#ifndef __NTC_H
#define __NTC_H

#include "stm32f0xx.h"

void ntc_init(void);
uint16_t ntc_get_adc(void);
float ntc_get_temperature(void);

#endif
