#include "settings.h"
#include "stdbool.h"
#include "stm32f0xx_flash.h"

// STM32F072CB最后一页Flash
#define SETTINGS_FLASH_START_ADDRESS 0x0801F800
#define SETTINGS_FLASH_END_ADDRESS 0x08020000

// 每条记录8字节数据
#define SETTINGS_RECORD_SIZE 8

// 数据有效标志
#define SETTINGS_MAGIC 0xA5A5

// 校验标志
#define SETTINGS_CHECK 0x5A5A

// 判断一条记录是否为空
static bool settings_record_is_empty(uint32_t address)
{
    if (*(uint16_t *)(address + 0) != 0xFFFF)
    {
        return false;
    }
    if (*(uint16_t *)(address + 2) != 0xFFFF)
    {
        return false;
    }
    if (*(uint16_t *)(address + 4) != 0xFFFF)
    {
        return false;
    }
    if (*(uint16_t *)(address + 6) != 0xFFFF)
    {
        return false;
    }

    return true;
}

// 判断一条记录是否有效
static bool settings_record_is_valid(uint32_t address)
{
    uint16_t magic = *(uint16_t *)(address + 0);             // 数据有效位
    uint16_t brightness = *(uint16_t *)(address + 2);        // 亮度值
    uint16_t color_temperature = *(uint16_t *)(address + 4); // 色温值
    uint16_t check = *(uint16_t *)(address + 6);             // 校验位

    // 有效标志不正确
    if (magic != SETTINGS_MAGIC)
    {
        return false;
    }

    // 亮度范围不正确
    if ((brightness < 10) || (brightness > 100))
    {
        return false;
    }

    // 色温范围不正确
    if ((color_temperature < 4000) || (color_temperature > 6500))
    {
        return false;
    }

    // 校验错误
    if (check != (brightness ^ color_temperature ^ SETTINGS_CHECK))
    {
        return false;
    }

    return true;
}

// 读取最后一次保存的设置
void settings_load(uint16_t *brightness, uint16_t *color_temperature)
{
    uint32_t address;
    bool found = false;                  // 标记是否找到有效的设置数据
    uint16_t last_brightness = 0;        // 保存最后一次有效的亮度值
    uint16_t last_color_temperature = 0; // 保存最后一次有效的色温值

    // 扫描整个设置存储区
    for (address = SETTINGS_FLASH_START_ADDRESS; address < SETTINGS_FLASH_END_ADDRESS; address += SETTINGS_RECORD_SIZE)
    {
        if (settings_record_is_valid(address))
        {
            last_brightness = *(uint16_t *)(address + 2);
            last_color_temperature = *(uint16_t *)(address + 4);

            found = true;
        }
    }

    // 找到有效记录才修改数据
    if (found == true)
    {
        *brightness = last_brightness;
        *color_temperature = last_color_temperature;
    }
}

// 保存当前设置
void settings_save(uint16_t brightness, uint16_t color_temperature)
{
    uint16_t check;
    uint32_t address;
    FLASH_Status status;

    // 参数检查
    if ((brightness < 10) || (brightness > 100))
    {
        return;
    }
    if ((color_temperature < 4000) || (color_temperature > 6500))
    {
        return;
    }

    check = brightness ^ color_temperature ^ SETTINGS_CHECK;

    address = SETTINGS_FLASH_START_ADDRESS;

    // 扫描整个设置存储区，找到一个空的记录地址
    while (address < SETTINGS_FLASH_END_ADDRESS)
    {
        if (settings_record_is_empty(address))
        {
            break;
        }

        address += SETTINGS_RECORD_SIZE;
    }

    // 解锁Flash
    FLASH_Unlock();

    // 清除Flash擦除标志
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR);

    // 如果页面已经写满
    if (address >= SETTINGS_FLASH_END_ADDRESS)
    {
        // 擦除最后一页Flash
        status = FLASH_ErasePage(SETTINGS_FLASH_START_ADDRESS);

        if (status != FLASH_COMPLETE)
        {
            // 擦除失败，锁定Flash并返回
            FLASH_Lock();
            return;
        }

        // 重置地址为起始地址,第一页第一行重新开始
        address = SETTINGS_FLASH_START_ADDRESS;
    }

    /*
     * 写入顺序：
     *
     * 亮度
     * 色温
     * 校验值
     * 最后才写MAGIC
     *
     * MAGIC最后写，可以防止写到一半突然断电时，
     * 把不完整的数据当成有效记录。
     */

    status = FLASH_ProgramHalfWord(address + 2, brightness);

    if (status == FLASH_COMPLETE)
    {
        status = FLASH_ProgramHalfWord(address + 4, color_temperature);
    }
    if (status == FLASH_COMPLETE)
    {
        status = FLASH_ProgramHalfWord(address + 6, check);
    }
    if (status == FLASH_COMPLETE)
    {
        FLASH_ProgramHalfWord(address + 0, SETTINGS_MAGIC);
    }

    // 锁定Flash
    FLASH_Lock();
}