# Electronic Load Project

这是一个基于 ESP32 的电子负载控制程序，适用于带有 160x80 TFT 显示屏、INA226 电量监测芯片、MCP4725 DAC 和旋转编码器的测试平台。

## 项目功能

- 实时显示电压、电流、功率、能量（Wh）、温度和运行时间
- 通过旋转编码器调整输出电流设定值
- 按下旋转编码器切换电子负载开/关
- 根据温度自动控制风扇
- 温度过高时自动关闭负载输出
- 使用 LVGL 在 TFT 显示屏上显示仪表信息

## 主要硬件组件

- ESP32 开发板
- TFT 显示屏（使用 `TFT_eSPI` 和 `LVGL` 驱动）
- INA226 电流/电压传感器
- MCP4725 I2C DAC
- 旋转编码器（带按键）
- 温度传感器（通过模拟输入读取并用 B3950 查表计算温度）
- 风扇控制接口
- 负载使能输出

## 代码说明

主要代码位于 `01 Software/ele_load/ele_load.ino`：

- `setup()`
  - 初始化串口、TFT、LVGL、I2C 设备
  - 初始化 INA226 并进入连续测量模式
  - 初始化旋转编码器输入

- `loop()`
  - 调用 `lv_task_handler()` 更新图形界面
  - 调用 `ina266_task()` 获取 INA226 电压、电流、功率，并更新显示
  - 调用 `time_update_task()` 更新运行时钟
  - 调用 `button_handle_task()` 处理旋转编码器输入，包括开/关和电流调节

- 温度读取和风扇控制
  - 通过 `analogRead(38)` 和 `analogRead(37)` 读取温度和电池相关 ADC 值
  - 使用 `B3950.h` 中的温度查表进行热敏电阻温度换算
  - 50°C 以上开启风扇，90°C 以上断开输出

## 引脚定义

- `OUT_EN_PIN`：25，负载输出使能
- `FAN_CTL_PIN`：14，风扇控制
- `LCD_BL`：26，LCD 背光（代码中定义但未显式使用）
- `PinA`：19，旋转编码器 A
- `PinB`：23，旋转编码器 B
- `PinC`：26，旋转编码器按键

## 依赖库

- `lvgl`
- `TFT_eSPI`
- `lv_examples`
- `Wire`
- `Bounce2`
- `INA.h`
- `SPI`
- `Ticker`
- `MD_REncoder`

## 使用方法

### 通过 VS Code 编译并上传

本项目使用 Arduino 草图格式。可以在 VS Code 集成终端中使用 Arduino CLI 编译和上传：

1. 安装 [Arduino CLI](https://arduino.github.io/arduino-cli/)；也可以安装 VS Code 的 Arduino 扩展，便于在编辑器中使用相关命令。
2. 在 VS Code 中打开 `01 Software/ele_load` 文件夹（其中包含 `ele_load.ino`），然后在终端安装 ESP32 Arduino 核心：

   ```powershell
   arduino-cli core update-index
   arduino-cli core install esp32:esp32
   ```

3. 安装项目依赖库。LVGL 需使用 7.x 版本，因为代码使用了 LVGL 7 的 API：

   ```powershell
   arduino-cli lib install "TFT_eSPI"
   arduino-cli lib install "lvgl@7.11.0"
   arduino-cli lib install "INA"
   arduino-cli lib install "Bounce2"
   ```

   `Wire`、`SPI` 和 `Ticker` 通常由 ESP32 Arduino 核心提供。`lv_examples` 和 `MD_REncoder` 需要根据其实际来源补齐，并使用与 LVGL 版本兼容的 `lv_examples`。当前仓库的草图目录没有 `MD_REncoder.h`，缺少此文件会导致编译失败。

4. 配置 `TFT_eSPI` 的屏幕驱动和引脚，使其与实际 TFT 屏幕及硬件连接一致。根据实际开发板调整代码中的引脚定义和 I2C 地址。
5. 连接开发板，在终端查看串口和端口：

   ```powershell
   arduino-cli board list
   ```

6. 按实际开发板型号和串口替换下面示例中的 `esp32:esp32:esp32` 和 `COM5`，然后编译并上传：

   ```powershell
   arduino-cli compile --fqbn esp32:esp32:esp32 "D:\github\jlc-reproduce-project\Electronic-load\01 Software\ele_load"
   arduino-cli upload -p COM5 --fqbn esp32:esp32:esp32 "D:\github\jlc-reproduce-project\Electronic-load\01 Software\ele_load"
   ```

   例如 ESP32-S3 等不同型号应选择对应的 FQBN。若上传时无法连接，尝试在上传开始时按住开发板的 BOOT 键，待上传开始后松开。

7. 上传成功后，可通过串口监视器以 `115200` 波特率查看程序输出。首次验证时先不要连接电池或功率负载；确认开发板、显示屏和外围接线正常后，再连接负载。

也可以使用 Arduino IDE 打开 `01 Software/ele_load/ele_load.ino`，安装相同依赖、选择正确的 ESP32 开发板和端口后编译上传。

## 备注

- 代码中 `stopvol_label` 用于显示截止电压，但当前实现中未关联实际截止阈值控制逻辑。
- `B3950.h` 包含基于 B3950 热敏电阻的温度查表，用于温度显示和保护。
- 代码默认 I2C DAC 地址为 `0x60`。

---

如需扩展功能，可考虑增加：
- 精确的截止电压保护
- 电流设定显示界面
- 更复杂的负载模式（恒流、恒压、恒功率）
- 持久化设置存储
