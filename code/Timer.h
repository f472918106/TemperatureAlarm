#ifndef Timer.h
#define Timer.h

// 函数功能: 11.0592Mhz晶振 毫秒级延时函数
// 参数: n
// 返回值: 无
void Delay(unsigned int n);

// 函数功能: 11.0592Mhz晶振 微秒级延时函数
// 参数: n
// 返回值: 无
void DelayMS(unsigned int n);

// 函数功能: 定时器初始化函数
// 参数: 无
// 返回值: 无
void InitlizeTimer();

#endif