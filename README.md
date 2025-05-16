# EmbeddedAssign1:
## part 1：
定义引脚数组：通过 ledPins[] 数组定义了 6 个连接 LED 的引脚（13、12、14、27、26、25）。
在 loop() 中通过循环依次点亮每个 LED：
使用 digitalWrite(ledPins[i], HIGH) 点亮当前 LED。
通过 delay(300) 控制流水灯的速度（延时 300 毫秒）。
使用 digitalWrite(ledPins[i], LOW) 熄灭当前 LED，移动到下一个 LED。
## part 2：
定义特定 LED 引脚：led1Pin = 13 和 led2Pin = 12 分别对应两个 LED。
使用 Serial.readStringUntil('\n') 读取指令，去除多余字符后判断指令：
输入 "1"：点亮 led1Pin 并通过串口反馈 "LED1亮"。
输入 "2"：点亮 led2Pin 并通过串口反馈 "LED2亮"。
# EmbeddedAssign2:
正确指示灯：连接到引脚 13，当密码全部正确输入后点亮。
错误指示灯：连接到引脚 12，当输入错误时点亮，并在 1 秒后自动熄灭。
当输入错误时，错误指示灯会点亮 1 秒，然后自动熄灭。
使用 errorActive 和 errorStartTime 来控制错误指示灯的点亮时间。
通过串口输入密码段，每个段以换行符结束。
系统依次验证输入是否与密码数组中的顺序匹配。
# EmbeddedAssign3:
引入库：
<U8g2lib.h>：提供对 OLED 显示器的支持。
调用 OLED.begin() 启动显示器。
调用 OLED.enableUTF8Print() 允许显示 UTF-8 编码的中文字符。
调用 OLED.sendBuffer() 将缓存内容传输到 OLED 显示器。