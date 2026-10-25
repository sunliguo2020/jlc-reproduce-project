#ifndef __LIGHT_CONTROL_H
#define __LIGHT_CONTROL_H

#include "stm32f0xx.h"

void light_control_init(void);
void light_control_process(void);
void over_temperature_protection_process(float temperature);

#endif
