#include<regx52.h>

/*
  ��ʱ��0��ʼ��
*/
void Timer0Init(void)		//1΢��@11.0592MHz
{
 
	TL0 = 0xFF;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	ET0=1;
	EA=1;
	PT0=0;
}
 