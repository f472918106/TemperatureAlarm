#ifndef DS18B20.h
#define DS18B20.h

extern unsigned char TL;
extern unsigned char TH;
extern unsigned char TN;
extern unsigned char TD;

// 函数功能: DS18B20初始化函数，读取应答信号
// 参数: 无
// 返回值: flag 0->成功 1->失败
void InitlizeDS18B20();

// 函数功能: 从DS18B20读取一个字节数据
// 参数: 无
// 返回值: str
unsigned char ReadByteFromDS18B20();

// 函数功能: 向DS18B20写入一个字节数据
// 参数: str
// 返回值: 无
void WriteByteToDS18B20(unsigned char str);

// 函数功能: 读取DS18B20采集到的温度
// 参数: 无
// 返回值: 无
void ReadTemperature();

#endif