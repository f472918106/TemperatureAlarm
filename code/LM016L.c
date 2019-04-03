#include "LM016L.h"
#include <reg51.h>
#include <intrins.h>
#include "Timer.h"

// �Ĵ���ѡ��λ
sbit RS=P2^0;

// ��дѡ��λ
sbit RW=P2^1;

// ʹ���ź�λ
sbit E=P2^2;

// æµ��־λ
sbit BF=P0^7;

// ��������: �ж�LM016L״̬�Ƿ�æµ
// ����: ��
// ����ֵ: status 0->���� 1->æµ
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

// ��������: ��ģʽ����ָ��д��LM016L
// ����: dictate
// ����ֵ: ��
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

// ��������: ָ���ַ���ʾ��ʵ�ʵ�ַ
// ����: x 
// ����ֵ: ��
void WriteAddressToLM016L(unsigned char x)
{
	WriteCmdToLM016L(x|0x80);
}

// ��������: ���ַ��ı�׼ASCII��д��LM016L
// ����: y
// ����ֵ: ��
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

// ��������: ��LM016L��ʾģʽ���г�ʼ��
// ����: ��
// ����ֵ: ��
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