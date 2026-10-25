#ifndef __TOUCH_H
#define __TOUCH_H

#include "stm32f0xx.h"
#include "stdbool.h"

// 触摸事件
#define TOUCH_EVENT_NONE 0
#define TOUCH_EVENT_SHORT_PRESS 1
#define TOUCH_EVENT_LONG_PRESS 2
#define TOUCH_EVENT_PRESS_HOLD 3

void touch_init(void);
void touch_scan(void);
bool touch_get_state(uint8_t channel);
uint8_t touch_get_event(uint8_t channel);

#endif
