#ifndef COMPIM.h
#define COMPIM.h

// 函数功能: 接收串口数据
// 参数: 无
// 返回值: str
unsigned char ReadDataFromCom();

// 函数功能: 向串口发送数据
// 参数: str[n] 要发送的数据
// 返回值: 无
void SendDataToCom(unsigned char str[]);

// 函数功能: 向串口发送数据
// 参数: str 要发送的数据
// 返回值: 无
void SendByteToCom(unsigned char str);

#endif