#include <reg51.h>
#include <rtx51tny.h>
#include "Timer.h"
#include "LM016L.h"
#include "DS18B20.h"
#include "COMPIM.h"

unsigned char code Number[]={"0123456789"};
unsigned char code Notice[]={"Run By DS18B20"};
unsigned char code Error[]={"ERROR"};
unsigned char code Temp[]={"Temp:"};
unsigned char code Cent[]={"'C"};
unsigned char code Alarm[]={"Runnaway Temperature"};

unsigned char TL;
unsigned char TH;
unsigned char TN;
unsigned char TD;

sbit Sounder=P1^0;

void DisplayError()
{
	unsigned char i;
	WriteAddressToLM016L(0x00);
	i=0;
	while(Error[i]!='\0')
	{
		WriteDataToLM016L(Error[i]);
		i++;
		DelayMS(100);
	}
	while(1);
}

void DisplayExplain()
{
	unsigned char i;
	WriteAddressToLM016L(0x00);
	i=0;
	while(Notice[i]!='\0')
	{
		WriteDataToLM016L(Notice[i]);
		i++;
		DelayMS(10);
	}
}

void DisplaySymbol()
{
	unsigned char i;
	WriteAddressToLM016L(0x40);
	i=0;
	while(Temp[i]!='\0')
	{
		WriteDataToLM016L(Temp[i]);
		i++;
		DelayMS(10);
	}
}

void DisplayDot()
{
	WriteAddressToLM016L(0x49);
	WriteDataToLM016L('.');
	DelayMS(10);
}

void DisplayCent()
{
	unsigned char i;
	WriteAddressToLM016L(0x4C);
	i=0;
	while(Cent[i]!='\0')
	{
		WriteDataToLM016L(Cent[i]);
		i++;
		DelayMS(10);
	}
}

void DisplayTN(unsigned char x)
{
	unsigned char j,k,l;
	j=x/100;
	k=(x%100)/10;
	l=x%10;
	WriteAddressToLM016L(0x46);
	WriteDataToLM016L(Number[j]);
	WriteDataToLM016L(Number[k]);
	WriteDataToLM016L(Number[l]);
	Delay(50);
}

void DisplayTD(unsigned char x)
{
	WriteAddressToLM016L(0x4A);
	WriteDataToLM016L(Number[x]);
	Delay(50); // ?
}
	
void Initlize() _task_ 0
{
	InitlizeTimer();
	os_create_task(1);
	os_create_task(2);
	os_create_task(3);
	os_create_task(4);
	os_delete_task(0);
}

void ComData() _task_ 1
{
	unsigned char str;
	while(1)
	{
		str=ReadDataFromCom();
		SendByteToCom(str);
	}
}

void TempController() _task_ 2
{
	InitlizeLM016L();
	Delay(5);
	DisplayExplain();
	DisplaySymbol();
	DisplayDot();
	DisplayCent();
	// TODO: 温度读取有问题
	while(1)
	{
		ReadTemperature();
		DisplayTN(TN);
		DisplayTD(TD);
		DelayMS(100);
	}
}

void TempMonitor() _task_ 3
{
	while(1)
	{
		if((TN/100)>0)
		{
		  SendDataToCom(Alarm);
			os_send_signal(4);
		}
		else
		{
			Sounder=1;
		}
	}
}

void SounderController() _task_ 4
{
	unsigned char i=0;
	while(1)
	{
		os_wait(K_SIG,0,0);
		for(i=0;i<100;i++)
		{
			Sounder=~Sounder;
			Delay(2);
		}
		Sounder=0;
	}
}
		
			
		