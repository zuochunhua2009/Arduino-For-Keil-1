# Arduino for Keil

>   (一个新的移植项目:https://github.com/FASTSHIFT/Arduino-For-STM32Cube)

>   这是一个跨平台移植的项目，可以在Keil MDK5环境下使用Arduino的函数对**STM32**系列单片机进行编程。
它本质上是一个建立好的Keil工程，然后在它的基础上封装一套类似于Arduino的底层函数库，可以像在Arduino IDE一样直接调用写好的API，
只需将Arduino支持的第三方库的文件夹加入 "Libraries" 文件夹下即可，然后打开"USER"文件夹启动keil工程进行编写程序。

>   底层基于 **STM32标准外设库** 二次封装，安装之后才能正常编译，下载链接位于下方。

[STM32F0xx标准外设库](https://keilpack.azureedge.net/pack/Keil.STM32F0xx_DFP.1.0.1.pack)

[STM32F10x标准外设库](https://keilpack.azureedge.net/pack/Keil.STM32F1xx_DFP.1.1.0.pack)

[STM32F3xx标准外设库](https://keilpack.azureedge.net/pack/Keil.STM32F3xx_DFP.1.2.0.pack)

[STM32F4xx标准外设库](https://keilpack.azureedge.net/pack/Keil.STM32F4xx_DFP.1.0.8.pack)

**注意** 如果您已经安装了更高版本的pack，需要使用keil自带的包管理器将高版本的pack进行Remove

>这个项目大部分核心函数是重构的，有部分源代码参考了 [stm32duino](https://github.com/stm32duino)。

>一般用法可以直接参照[Arduino语法](https://www.arduino.cc/reference/en/)，高级用法参考工程自带的Example文件夹内的示例。

支持与寄存器和标准外设库的函数混用，**保证兼容性、提升运行效率**:
```C
void setup()
{
	pinMode(PA0,OUTPUT);			//使用Arduino函数将配置PA0为输出模式
}

void loop()
{
	GPIOA -> BSRR = GPIO_Pin_0;		//使用寄存器将PA0电平拉高
	delay(1000);				//延时一秒
	GPIO_ResetBits(GPIOA, GPIO_Pin_0);	//使用标准外设库的函数将PA0电平拉低
	delay(1000);				//延时一秒
}
```



## 注意： 
     1.请不要删除"main.cpp"中的FileGroup.h和main函数。 
     2.添加第三方库函数的时候要加入完整的路径. 
     3.由于平台的不同，所以不能保证兼容所有的Arduino第三方库函数，有的函数库可能要进行修改才能正常运行，
       具体修改方式请按照编译器的提示，或者可以提交Issues。 
       
## 支持Arduino函数有:
### 基本:
#### 时间:
```C
	delay(Time_ms);
	delayMicroseconds(Time_us);
	millis();
	micros();
```
#### 输入输出:
```C
	pinMode(Pin,Mode);
	attachInterrrupt(Pin,Callback_function,Trigger_Mode);	
	digitalWrite(Pin,State);
	digitalRead(Pin);
	analogRead(Pin);
	analogWrite(Pin,DutyCycle);
	shiftOut(dataPin,clockPin,bitOrder,value);
	shiftIn(dataPin,clockPin,bitOrder);
	tone(Pin,Frequency,Time_ms);
	tone(Pin,Frequency);
```          
 > Print
```C++
	Serial.print("Hello STM32");
	Serial.printf("Hello STM%d",32);
	Serial << "Hello STM32" << "\r\n";
```
 > String 
```C++
	String s1 = "Hello";
	String s2 = " STM32";
	Serial.print(s1 + s2);
```
 > Stream
```C++
	Serial.begin(115200);
	Serial.setTimeout(20);
	if(Serial.available())
	{
		String s = Serial.readString();
	}
```
### 外设:
 > Serial
```C++
 	Serial.begin(115200);
	while(Serial.available())
	{
		Serial.print(Serial.read());
	}
```
 > Wire
```C++
	Wire.begin();
	Wire.beginTransmission(0xFF);
	Wire.write(0x01);
	Wire.endTransmission();
```
 > SPI
```C++
	SPI.begin();
	SPI.transfer(0xFF);
```
