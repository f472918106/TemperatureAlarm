#include "Timer.h"
#include <reg51.h>
#include "intrins.h"
#define BAUDRATE 9600
#define SYSCLK 11059200

// 函数功能: 11.0592Mhz晶振 毫秒级延时函数
// 参数: n
// 返回值: 无
void Delay(unsigned int n)
{
	unsigned char x,y;
	for(x=n;x>0;x--)
		for(y=124;y>0;y--);
}

// 函数功能: 11.0592Mhz晶振 微秒级延时函数
// 参数: n
// 返回值: 无
void DelayMS(unsigned int n)
{
	while(n--);
}

// 函数功能: 定时器初始化函数
// 参数: 无
// 返回值: 无
void InitlizeTimer()
{
	TMOD=0x20;
	PCON=0;
	TL1=TH1=256-SYSCLK/BAUDRATE/32/12;
	SCON=0x50;
	TR1=1;
}
