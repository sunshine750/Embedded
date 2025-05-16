#include <Arduino.h>

part 1:
const int ledPins[] = {13, 12, 14, 27, 26, 25}; 
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  // 初始化所有引脚为输出模式
    for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // 初始状态熄灭
    }
}

void loop() {
  // 实现流水灯效果
    for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH); // 点亮当前 LED
    delay(300); // 延时，调整流水灯速度
    digitalWrite(ledPins[i], LOW); // 熄灭当前 LED
    }
}




part 2:
int led1Pin = 13;  // 定义 LED2 连接的引脚
int led2Pin = 12;

void setup() {
  Serial.begin(9600);  // 初始化串口通信，波特率设为 9600
  pinMode(led1Pin, OUTPUT);  // 设置 LED1 引脚为输出模式
  pinMode(led2Pin, OUTPUT);  // 设置 LED2 引脚为输出模式
}

void loop() {
  if (Serial.available() > 0) {  // 检查是否有串口数据可读
    String command = Serial.readStringUntil('\n');  // 读取字符串直到换行符
    command.trim();  // 去除字符串两端的空白和换行符
    
    if (command.equals("1")) {  // 检查是否为指令 "1"
      digitalWrite(led1Pin, HIGH);  // 点亮 LED1
      Serial.println("LED1亮");  // 向串口发送反馈信息
    } else if (command.equals("2")) {  // 检查是否为指令 "2"
      digitalWrite(led2Pin, HIGH);  // 点亮 LED2
      Serial.println("LED2亮");  // 向串口发送反馈信息
    }
    }
}
