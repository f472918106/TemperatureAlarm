#include "LM016L.h"
#include <reg51.h>
#include <intrins.h>
#include "Timer.h"

// 寄存器选择位
sbit RS=P2^0;

// 读写选择位
sbit RW=P2^1;

// 使能信号位
sbit E=P2^2;

// 忙碌标志位
sbit BF=P0^7;

// 函数功能: 判断LM016L状态是否忙碌
// 参数: 无
// 返回值: status 0->空闲 1->忙碌
bit IsLM016LBusy()
{
	bit status;
	RS=0;
	RW=1;
	E=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	status=BF;
	E=0;
	return status;
}

// 函数功能: 将模式设置指令写入LM016L
// 参数: dictate
// 返回值: 无
void WriteCmdToLM016L(unsigned char dictate)
{
	while(IsLM016LBusy()==1);
	RS=0;
	RW=0;
	E=0;
	_nop_();
	_nop_();
	P0=dictate;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	E=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	E=0;
}

// 函数功能: 指定字符显示的实际地址
// 参数: x 
// 返回值: 无
void WriteAddressToLM016L(unsigned char x)
{
	WriteCmdToLM016L(x|0x80);
}

// 函数功能: 将字符的标准ASCII码写入LM016L
// 参数: y
// 返回值: 无
void WriteDataToLM016L(unsigned char y)
{
	while(IsLM016LBusy()==1);
	RS=1;
	RW=0;
	E=0;
	P0=y;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	E=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	E=0;
}

// 函数功能: 对LM016L显示模式进行初始化
// 参数: 无
// 返回值: 无
void InitlizeLM016L()
{
	DelayMS(15);
	WriteCmdToLM016L(0x38);
	DelayMS(5);
  WriteCmdToLM016L(0x38);
	DelayMS(5);
	WriteCmdToLM016L(0x38);
	DelayMS(5);
	WriteCmdToLM016L(0x0C);
	DelayMS(5);
	WriteCmdToLM016L(0x06);
	DelayMS(5);
	WriteCmdToLM016L(0x01);
	DelayMS(5);
}