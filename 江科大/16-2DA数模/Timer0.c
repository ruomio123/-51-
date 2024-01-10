#include<regx52.h>

/*
  定时器0初始化
*/
void Timer0_Init(void)		//100us@11.0592MHz
{
 
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0xAE;				//设置定时初始值
	TH0 = 0xFB;				//设置定时初始值

	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}

/*
void Timer0_Routine()  interrupt 1
{
  static unsigned int T0Count;
  	TL0 = 0xAE;				//设置定时初始值
	TH0 = 0xFB;				//设置定时初始值

  T0Count++;
  if(T0Count>=1000)
  {
    T0Count=0;
  }

}
*/