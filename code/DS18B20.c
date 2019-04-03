#include "DS18B20.h"
#include "Timer.h"
#include <reg51.h>

// DS18B20������
sbit DQ=P2^3;

// ��������: DS18B20��ʼ����������ȡӦ���ź�
// ����: ��
// ����ֵ: flag 0->�ɹ� 1->ʧ��
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

// ��������: ��DS18B20��ȡһ���ֽ�����
// ����: ��
// ����ֵ: str
unsigned char ReadByteFromDS18B20() // TODO: ��ȡʱ�������� ǰ�����ݲ�����ͬ
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

// ��������: ��DS18B20д��һ���ֽ�����
// ����: str
// ����ֵ: ��
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

// ��������: ��ȡDS18B20�ɼ������¶�
// ����: ��
// ����ֵ: ��
void ReadTemperature() // TODO: ��ȡʱ�������� ǰ�����ݲ�����ͬ
{
	EA=0;
	InitlizeDS18B20();
	WriteByteToDS18B20(0xCC);
	WriteByteToDS18B20(0x44);
	
	DelayMS(350);
	
	InitlizeDS18B20();
	WriteByteToDS18B20(0xCC);
	WriteByteToDS18B20(0xBE);
	
	TL=ReadByteFromDS18B20(); // ��ȡ�¶�ֵ��λ
	TH=ReadByteFromDS18B20(); // ��ȡ�¶�ֵ��λ	
	
	TN=TH*16+TL/16;
	TD=(TL%16)*10/16;
	EA=1;
}
