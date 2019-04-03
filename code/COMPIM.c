#include "COMPIM.h"
#include <reg51.h>

// ��������: ���մ�������
// ����: ��
// ����ֵ: str
unsigned char ReadDataFromCom()
{
	unsigned char str;
	while(!RI);
	RI=0;
	str=SBUF;
	return str;
}
	

// ��������: �򴮿ڷ�������
// ����: str[n] Ҫ���͵�����
// ����ֵ: ��
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

// ��������: �򴮿ڷ�������
// ����: str Ҫ���͵�����
// ����ֵ: ��
void SendByteToCom(unsigned char str)
{
	SBUF=str;
	while(!TI);
	TI=0;
}