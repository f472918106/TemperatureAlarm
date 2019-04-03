#ifndef DS18B20.h
#define DS18B20.h

extern unsigned char TL;
extern unsigned char TH;
extern unsigned char TN;
extern unsigned char TD;

// ��������: DS18B20��ʼ����������ȡӦ���ź�
// ����: ��
// ����ֵ: flag 0->�ɹ� 1->ʧ��
void InitlizeDS18B20();

// ��������: ��DS18B20��ȡһ���ֽ�����
// ����: ��
// ����ֵ: str
unsigned char ReadByteFromDS18B20();

// ��������: ��DS18B20д��һ���ֽ�����
// ����: str
// ����ֵ: ��
void WriteByteToDS18B20(unsigned char str);

// ��������: ��ȡDS18B20�ɼ������¶�
// ����: ��
// ����ֵ: ��
void ReadTemperature();

#endif