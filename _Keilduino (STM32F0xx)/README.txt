# A Cross-platform migration Project @FASTSHIFT
# Arduino for STM32F0xx

# https://github.com/FASTSHIFT/Arduino-For-Keil

//*********************************UPGRADE LOGS************************************//

//Finish in 2018.7.29  V_1.0 基于STM32F0xx标志外设库(1.0.1版)，移植了全部的ArduinoAPI
//Upgrade   2018.8.14  V_1.1 整理USART相关代码，修改Tone库只占用一个定时器(可使用toneSetTimer()函数切换),time_exti改名为timer
//Upgrade   2018.8.17  V_1.2 在Arduino.h添加了更完整的与GPIO寄存器交互函数，提升与第三方库的兼容性
//Upgrade   2018.8.20  V_1.3 添加WCharacter.h，支持Arduino有关Characters的函数，添加mcu_type.h，使Arduino.h可以跨MCU使用
//Upgrade   2018.10.9  V_1.4 添加注释，更新Tone、HardwareSerial，去除usart.c usart.h
//Upgrade   2018.11.21 V_1.5 更新Arduino.c
//Upgrade   2019.2.18  V_1.6 整理代码,更好的兼容性
//Upgrade   2019.3.22  V_1.7 为SysTick设置最高中断优先级，防止被其他中断打断(非常重要!)
//Upgrade   2019.6.3   V_1.8 pwm.c库将频率设定值从16位改为32位，并加入参数合法范围判断，ARDUINO宏定义从Arduino.h转至全局宏定义
//Upgrade   2019.6.18  V_1.9 PA4已可以输出PWM
//Upgrade   2019.7.12  V_2.0 Arduino.h里yield()与digitalPinToInterrupt(Pin)定义，更改analogRead_DMA()合法参数判断方式