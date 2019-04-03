#include "Timer.h"
#include <reg51.h>
#include "intrins.h"
#define BAUDRATE 9600
#define SYSCLK 11059200

// ��������: 11.0592Mhz���� ���뼶��ʱ����
// ����: n
// ����ֵ: ��
void Delay(unsigned int n)
{
	unsigned char x,y;
	for(x=n;x>0;x--)
		for(y=124;y>0;y--);
}

// ��������: 11.0592Mhz���� ΢�뼶��ʱ����
// ����: n
// ����ֵ: ��
void DelayMS(unsigned int n)
{
	while(n--);
}

// ��������: ��ʱ����ʼ������
// ����: ��
// ����ֵ: ��
void InitlizeTimer()
{
	TMOD=0x20;
	PCON=0;
	TL1=TH1=256-SYSCLK/BAUDRATE/32/12;
	SCON=0x50;
	TR1=1;
}
