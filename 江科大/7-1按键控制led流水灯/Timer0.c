#include<regx52.h>

/*
  定时器0初始化
*/
void Timer0Init(void)		//1微秒@11.0592MHz
{
 
	TL0 = 0xFF;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}
 