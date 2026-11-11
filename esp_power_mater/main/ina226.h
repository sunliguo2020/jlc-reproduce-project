#ifndef __INA226_H__
#define __INA226_H__

#define INA226_ADDR     0x40
#define INA226_ID_NUM   0x2260

#define INA226_REG_CONF 0x00    //Configuration Register
#define INA226_REG_SV   0x01    //Shunt Voltage Register
#define INA226_REG_BV   0x02    //Bus Voltage Register
#define INA226_REG_PWR  0x03    //Power Register
#define INA226_REG_CUR  0x04    //Current Register
#define INA226_REG_CAL  0x05    //Calibration Register
#define INA226_REG_ID   0xFF    //ID:0x2260

//INA226 可能的 I2C 地址范围（由 A0/A1 引脚决定）
#define INA226_ADDR_MIN 0x40
#define INA226_ADDR_MAX 0x4F

int ina226_init(void);
int ina226_scan_addr(void);
void ina226_task(void *param);
void ina226_timer_fun(unsigned long data);
int ina226_set_cal(void);

#endif