#include "touch.h"
#include "tsc.h"

// 触摸检测参数
// #define TOUCH_PRESS_THRESHOLD 180   // 按下至少需要下降的值
// #define TOUCH_RELEASE_THRESHOLD 120 // 释放时允许距离原基准值的范围
#define TOUCH_DOMINANCE_MARGIN 60 // 按键占优判定阈值

#define TOUCH_PRESS_DEBOUNCE_COUNT 5   // 连续按下确认次数，10ms * 5 = 50ms
#define TOUCH_RELEASE_DEBOUNCE_COUNT 4 // 连续释放确认次数，10ms * 4 = 40ms

#define TOUCH_STARTUP_COUNT 10     // 上电稳定时间，10ms * 10 = 100ms
#define TOUCH_COOLDOWN_COUNT 8     // 释放后保护时间，10ms * 8 = 80ms
#define TOUCH_MAX_PRESS_COUNT 1000 // 最长允许连续按下时间，10ms * 1000 = 10s

// 触摸事件参数
#define TOUCH_LONG_PRESS_COUNT 50 // 长按时间 500ms
#define TOUCH_LONG_REPEAT_COUNT 2 // 长按连续触发周期 20ms

#define TOUCH_NONE 0xFF

// 触摸时下降值
static const uint16_t touch_press_threshold[3] = {180, 650, 80};

// 释放时允许距离原基准值的范围
static const uint16_t touch_release_threshold[3] = {120, 300, 60};

// 滤波后的触摸值
static uint16_t touch_filtered[3] = {0};

// 空闲基准值
static uint16_t touch_baseline[3] = {0};

// 本次触摸的最低值
static uint16_t touch_min_value[3] = {0};

// 触摸按键状态
static bool touch_state[3] = {false};

// 上一次触摸按键状态
static bool touch_last_state[3] = {false};

// 按下消抖计数
static uint8_t touch_press_debounce[3] = {0};

// 释放消抖计数
static uint8_t touch_release_debounce[3] = {0};

// 按键按下时间
static uint16_t touch_press_time[3] = {0};

// 触摸按键事件
static uint8_t touch_event[3] = {TOUCH_EVENT_NONE};

// 当前已经按下的按键
static uint8_t touch_active_channel = TOUCH_NONE;

// 上电稳定计数
static uint8_t touch_startup_count = 0;

// 松手保护计数
static uint8_t touch_cooldown_count = 0;

// 更新空闲基准值
static void touch_baseline_update(uint8_t channel)
{
    if (touch_filtered[channel] > touch_baseline[channel])
    {
        touch_baseline[channel] = (touch_baseline[channel] * 7 + touch_filtered[channel]) / 8;
    }
    else
    {

        touch_baseline[channel] = (touch_baseline[channel] * 31 + touch_filtered[channel]) / 32;
    }
}

// 触摸初始化
void touch_init(void)
{
    uint8_t i;

    // 底层TSC初始化
    tsc_init();

    // 初始化触摸参数
    for (i = 0; i < 3; i++)
    {
        touch_filtered[i] = 0;
        touch_baseline[i] = 0;
        touch_min_value[i] = 0;

        touch_state[i] = false;
        touch_last_state[i] = false;

        touch_press_debounce[i] = 0;
        touch_release_debounce[i] = 0;

        touch_press_time[i] = 0;
        touch_event[i] = TOUCH_EVENT_NONE;
    }

    touch_active_channel = TOUCH_NONE;
    touch_startup_count = 0;
    touch_cooldown_count = 0;
}

// 触摸扫描
void touch_scan(void)
{
    uint8_t max_channel = 0;

    uint16_t raw;
    uint16_t delta[3] = {0};

    uint16_t max_delta = 0;
    uint16_t second_delta = 0;

    // 读取并滤波三个通道
    for (uint8_t i = 0; i < 3; i++)
    {
        raw = tsc_get_value(i);

        // 还没有采样数据
        if (raw == 0)
        {
            continue;
        }

        // 第一次采样
        if (touch_filtered[i] == 0)
        {
            touch_filtered[i] = raw;
        }
        else
        {
            // 1/4新数据， 3/4旧数据
            touch_filtered[i] = (touch_filtered[i] * 3 + raw) / 4;
        }

        // 第一次建立基准
        if (touch_baseline[i] == 0)
        {
            touch_baseline[i] = touch_filtered[i];
        }
    }

    // 上电稳定阶段
    if (touch_startup_count < TOUCH_STARTUP_COUNT)
    {
        touch_startup_count++;

        for (uint8_t i = 0; i < 3; i++)
        {
            if (touch_filtered[i] != 0)
            {
                touch_baseline[i] = touch_filtered[i];
            }
        }

        return;
    }

    if (touch_active_channel == TOUCH_NONE)
    {
        if (touch_cooldown_count > 0)
        {
            touch_cooldown_count--;
            for (uint8_t i = 0; i < 3; i++)
            {
                touch_press_debounce[i] = 0;
                touch_baseline_update(i);
            }

            return;
        }
        // 计算三个通道相对于基准下降多少
        for (uint8_t i = 0; i < 3; i++)
        {
            if (touch_baseline[i] > touch_filtered[i])
            {
                delta[i] = touch_baseline[i] - touch_filtered[i];
            }
            else
            {
                delta[i] = 0;
            }
        }

        // 找出变化最大的通道和第二大的通道
        for (uint8_t i = 0; i < 3; i++)
        {
            if (delta[i] > max_delta)
            {
                second_delta = max_delta;
                max_delta = delta[i];
                max_channel = i;
            }
            else if (delta[i] > second_delta)
            {
                second_delta = delta[i];
            }
        }

        // 判断是否真正触摸
        /*
         * 必须同时满足：
         *
         * 1. 主通道下降超过阈值
         * 2. 主通道明显强于其它通道
         *
         * 如果三个通道同时一起变化，
         * 就不会被认为是一次按键触摸。
         */
        if ((max_delta >= touch_press_threshold[max_channel]) && (max_delta >= second_delta + TOUCH_DOMINANCE_MARGIN))
        {
            // 只累计变化最大的通道
            for (uint8_t i = 0; i < 3; i++)
            {
                if (i != max_channel)
                {

                    touch_press_debounce[i] = 0;

                    // 其他通道继续跟踪环境变化
                    touch_baseline_update(i);
                }
            }

            touch_press_debounce[max_channel]++;

            // 连续达到确认次数
            if (touch_press_debounce[max_channel] >= TOUCH_PRESS_DEBOUNCE_COUNT)
            {
                touch_state[max_channel] = true;
                touch_press_debounce[max_channel] = 0;
                touch_active_channel = max_channel;

                // 记录本次触摸过程中的最低值
                touch_min_value[max_channel] = touch_filtered[max_channel];
            }
        }
        // 没有可靠触摸
        else
        {
            for (uint8_t i = 0; i < 3; i++)
            {
                touch_press_debounce[i] = 0;
                touch_baseline_update(i);
            }
        }
    }

    // 当前已经有按键按下
    else
    {
        uint8_t channel = touch_active_channel;
        uint16_t drop;
        uint16_t recover;
        bool release_detected = false;

        // 记录本次触摸过程中的最低值
        if (touch_filtered[channel] < touch_min_value[channel])
        {
            touch_min_value[channel] = touch_filtered[channel];
        }

        // 第一种释放条件
        // 已经回到接近原始空闲基准的状态
        if (touch_filtered[channel] + touch_release_threshold[channel] >= touch_baseline[channel])
        {
            release_detected = true;
        }

        // 第二种释放条件
        // 相对于最低点恢复70%以上
        if (touch_baseline[channel] > touch_min_value[channel])
        {
            drop = touch_baseline[channel] - touch_min_value[channel];

            if (touch_filtered[channel] > touch_min_value[channel])
            {
                recover = touch_filtered[channel] - touch_min_value[channel];
            }
            else
            {
                recover = 0;
            }

            if ((drop >= touch_press_threshold[channel]) && (recover * 10 >= drop * 7))
            {
                release_detected = true;
            }
        }

        // 释放消抖
        if (release_detected == true)
        {
            touch_release_debounce[channel]++;

            if (touch_release_debounce[channel] >= TOUCH_RELEASE_DEBOUNCE_COUNT)
            {
                touch_state[channel] = false;
                touch_release_debounce[channel] = 0;

                // 松手后重新建立基准
                touch_baseline[channel] = touch_filtered[channel];
                touch_min_value[channel] = 0;

                touch_active_channel = TOUCH_NONE;

                // 松手保护
                touch_cooldown_count = TOUCH_COOLDOWN_COUNT;
            }
        }

        else
        {
            touch_release_debounce[channel] = 0;
        }

        // 其他没有按下的通道持续跟踪环境变化
        for (uint8_t i = 0; i < 3; i++)
        {
            if (i != channel)
            {
                touch_baseline_update(i);
            }
        }
    }

    // 生成短按/长按事件
    for (uint8_t i = 0; i < 3; i++)
    {

        // 刚刚按下
        if ((touch_state[i] == true) && (touch_last_state[i] == false))
        {
            // 清除按下时间
            touch_press_time[i] = 0;
        }

        // 持续按下
        if (touch_state[i] == true)
        {
            if (touch_press_time[i] < 65535)
            {
                // 按下时间增加
                touch_press_time[i]++;
            }

            // 达到长按事时间
            if (touch_press_time[i] == TOUCH_LONG_PRESS_COUNT)
            {
                touch_event[i] = TOUCH_EVENT_LONG_PRESS;
            }

            // 达到长按连续触发周期
            if (touch_press_time[i] > TOUCH_LONG_PRESS_COUNT)
            {
                if ((touch_press_time[i] - TOUCH_LONG_PRESS_COUNT) % TOUCH_LONG_REPEAT_COUNT == 0)
                {
                    touch_event[i] = TOUCH_EVENT_PRESS_HOLD;
                }
            }

            // 防止异常锁死
            if (touch_press_time[i] >= TOUCH_MAX_PRESS_COUNT)
            {
                touch_state[i] = false;

                touch_baseline[i] = touch_filtered[i];
                touch_min_value[i] = 0;

                touch_press_debounce[i] = 0;
                touch_release_debounce[i] = 0;

                touch_active_channel = TOUCH_NONE;

                touch_cooldown_count = TOUCH_COOLDOWN_COUNT;
            }
        }

        // 刚刚释放
        if ((touch_state[i] == false) && (touch_last_state[i] == true))
        {
            // 按下时间小于长按时间，判定为短按
            if (touch_press_time[i] < TOUCH_LONG_PRESS_COUNT)
            {
                touch_event[i] = TOUCH_EVENT_SHORT_PRESS;
            }

            // 清除按下时间
            touch_press_time[i] = 0;
        }

        // 保存状态
        touch_last_state[i] = touch_state[i];
    }
}

// 获取按键触摸状态
bool touch_get_state(uint8_t channel)
{
    if (channel > TOUCH_3)
    {
        return false;
    }

    return touch_state[channel];
}

// 获取触摸按键事件
uint8_t touch_get_event(uint8_t channel)
{
    uint8_t event;

    if (channel > TOUCH_3)
    {
        return TOUCH_EVENT_NONE;
    }

    event = touch_event[channel];

    // 读取后清除事件
    touch_event[channel] = TOUCH_EVENT_NONE;

    return event;
}