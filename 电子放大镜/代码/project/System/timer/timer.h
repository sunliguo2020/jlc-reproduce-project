#ifndef __TIMER_H
#define __TIMER_H

#include "stm32f0xx.h"

void tim2_init(void);
uint32_t get_sys_time_ms(void);

#endif
