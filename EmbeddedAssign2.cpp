#include <Arduino.h>
String password[] = {"AA", "BB", "CC", "DD"};
int currentStep = 0;
int ledCorrectPin = 13;  // 正确指示灯连接的引脚
int ledErrorPin = 12;    // 错误指示灯连接的引脚
unsigned long errorStartTime = 0;  // 错误发生的时间
bool errorActive = false;  // 是否处于错误状态

void setup() {
  Serial.begin(9600);  // 启动串口通信，波特率9600
  pinMode(ledCorrectPin, OUTPUT);  // 设置正确指示灯引脚为输出模式
  pinMode(ledErrorPin, OUTPUT);    // 设置错误指示灯引脚为输出模式
  digitalWrite(ledCorrectPin, LOW);  // 初始状态关闭正确指示灯
  digitalWrite(ledErrorPin, LOW);    // 初始状态关闭错误指示灯
}

void loop() {
  // 检查错误状态是否需要清除
    if (errorActive && (millis() - errorStartTime >= 1000)) {
    digitalWrite(ledErrorPin, LOW);  // 关闭错误指示灯
    errorActive = false;
    }

    if (!errorActive && Serial.available()) {
    String input = Serial.readStringUntil('\n'); // 读取一行（直到换行符）
    input.trim(); // 去除前后空格与换行符

    if (input.equalsIgnoreCase(password[currentStep])) {
        currentStep++;

      // 只有当所有密码都正确输入后才点亮正确LED
        if (currentStep == 4) {
        Serial.println("密码正确");
        digitalWrite(ledCorrectPin, HIGH);  // 点亮正确指示灯
        
        // 5秒后自动熄灭正确LED（可选）
        delay(5000);
        digitalWrite(ledCorrectPin, LOW);
        
        currentStep = 0; // 重置以便下次输入
        }
    } else {
        Serial.println("密码错误");
      currentStep = 0; // 输入错误，重置状态

      digitalWrite(ledErrorPin, HIGH);    // 点亮错误指示灯
      errorStartTime = millis();          // 记录错误开始时间
      errorActive = true;                 // 标记为错误状态
    }
    }
}