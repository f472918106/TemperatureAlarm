#ifndef LM016L.h
#define LM016L.h

// 函数功能: 判断LM016L状态是否忙碌
// 参数: 无
// 返回值: status 0->空闲 1->忙碌
bit IsLM016LBusy();

// 函数功能: 将模式设置指令写入LM016L
// 参数: dictate
// 返回值: 无
void WriteCmdToLM016L(unsigned char dictate);

// 函数功能: 指定字符显示的实际地址
// 参数: x 
// 返回值: 无
void WriteAddressToLM016L(unsigned char x);

// 函数功能: 将字符的标准ASCII码写入LM016L
// 参数: y
// 返回值: 无
void WriteDataToLM016L(unsigned char y);

// 函数功能: 对LM016L显示模式进行初始化
// 参数: 无
// 返回值: 无
void InitlizeLM016L();

#endif