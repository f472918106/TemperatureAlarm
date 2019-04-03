#include "COMPIM.h"
#include <reg51.h>

// 函数功能: 接收串口数据
// 参数: 无
// 返回值: str
unsigned char ReadDataFromCom()
{
	unsigned char str;
	while(!RI);
	RI=0;
	str=SBUF;
	return str;
}
	

// 函数功能: 向串口发送数据
// 参数: str[n] 要发送的数据
// 返回值: 无
void SendDataToCom(unsigned char str[])
{
	unsigned char i=0;
	while(str[i]!='\0')
	{
		SBUF=str[i];
		while(!TI);
		TI=0;
		i++;
	}
}

// 函数功能: 向串口发送数据
// 参数: str 要发送的数据
// 返回值: 无
void SendByteToCom(unsigned char str)
{
	SBUF=str;
	while(!TI);
	TI=0;
}