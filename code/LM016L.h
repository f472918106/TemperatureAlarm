#ifndef LM016L.h
#define LM016L.h

// ��������: �ж�LM016L״̬�Ƿ�æµ
// ����: ��
// ����ֵ: status 0->���� 1->æµ
bit IsLM016LBusy();

// ��������: ��ģʽ����ָ��д��LM016L
// ����: dictate
// ����ֵ: ��
void WriteCmdToLM016L(unsigned char dictate);

// ��������: ָ���ַ���ʾ��ʵ�ʵ�ַ
// ����: x 
// ����ֵ: ��
void WriteAddressToLM016L(unsigned char x);

// ��������: ���ַ��ı�׼ASCII��д��LM016L
// ����: y
// ����ֵ: ��
void WriteDataToLM016L(unsigned char y);

// ��������: ��LM016L��ʾģʽ���г�ʼ��
// ����: ��
// ����ֵ: ��
void InitlizeLM016L();

#endif