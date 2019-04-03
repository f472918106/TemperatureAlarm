#include "DS18B20.h"
#include "Timer.h"
#include <reg51.h>

// DS18B20数据线
sbit DQ=P2^3;

// 函数功能: DS18B20初始化函数，读取应答信号
// 参数: 无
// 返回值: flag 0->成功 1->失败
void InitlizeDS18B20()
{
	DQ=1;
	DelayMS(8);
	DQ=0;
	DelayMS(90);
	DQ=1;
	DelayMS(8);
	DQ=1;
	DelayMS(4);
}

// 函数功能: 从DS18B20读取一个字节数据
// 参数: 无
// 返回值: str
unsigned char ReadByteFromDS18B20() // TODO: 读取时序有问题 前后数据采样相同
{
	unsigned char i,str;
	DQ=1;
	for(i=0;i<8;i++)
	{
		DQ=0;
		str>>=1;
		DQ=1;
		if(DQ==1)
		{
			str|=0x80;
		}
		DelayMS(8);
		DQ=1;
	}
	return str;
}

// 函数功能: 向DS18B20写入一个字节数据
// 参数: str
// 返回值: 无
void WriteByteToDS18B20(unsigned char str)
{
	unsigned char i=0;
	// DQ=1;
	for(i=0;i<8;i++)
	{
		DQ=0;
		DQ=str&0x01;
		DelayMS(5);
		DQ=1;
		str>>=1;
	}
	DelayMS(4); //1
}

// 函数功能: 读取DS18B20采集到的温度
// 参数: 无
// 返回值: 无
void ReadTemperature() // TODO: 读取时序有问题 前后数据采样相同
{
	EA=0;
	InitlizeDS18B20();
	WriteByteToDS18B20(0xCC);
	WriteByteToDS18B20(0x44);
	
	DelayMS(350);
	
	InitlizeDS18B20();
	WriteByteToDS18B20(0xCC);
	WriteByteToDS18B20(0xBE);
	
	TL=ReadByteFromDS18B20(); // 读取温度值低位
	TH=ReadByteFromDS18B20(); // 读取温度值高位	
	
	TN=TH*16+TL/16;
	TD=(TL%16)*10/16;
	EA=1;
}
