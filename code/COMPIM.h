#ifndef COMPIM.h
#define COMPIM.h

// ��������: ���մ�������
// ����: ��
// ����ֵ: str
unsigned char ReadDataFromCom();

// ��������: �򴮿ڷ�������
// ����: str[n] Ҫ���͵�����
// ����ֵ: ��
void SendDataToCom(unsigned char str[]);

// ��������: �򴮿ڷ�������
// ����: str Ҫ���͵�����
// ����ֵ: ��
void SendByteToCom(unsigned char str);

#endif