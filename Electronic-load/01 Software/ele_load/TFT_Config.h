#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

#define USER_SETUP_LOADED

// 屏幕驱动 0.96寸 ST7735S 物理分辨率80*160，软件旋转为160*80横屏
#define ST7735_DRIVER
#define TFT_WIDTH  80
#define TFT_HEIGHT 160
#define ST7735_GREENTAB160x80

// ==== 严格跟随 Netlist_电子负载仪V1.2 PCB网表引脚 ====
#define TFT_MISO  -1        // 该屏单向SPI，不使用MISO
#define TFT_MOSI  10        // LCD_MOSI  FPC2.2 U23.29
#define TFT_SCLK  13        // LCD_CLK   FPC2.1 U23.20
#define TFT_CS    27        // LCD_CS    FPC2.5 U23.16
#define TFT_DC    5        // LCD_D/C   FPC2.3 U23.34
#define TFT_RST   18        // LCD_RST   FPC2.4 U23.35

#define SPI_FREQUENCY  27000000
#define SPI_READ_FREQUENCY  20000000
#define TFT_RGB_ORDER TFT_RGB

// 字体配置
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT

#endif
