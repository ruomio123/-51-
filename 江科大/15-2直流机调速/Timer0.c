#include<regx52.h>

/*
  ��ʱ��0��ʼ��
*/
void Timer0_Init(void)		//100us@11.0592MHz
{
 
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TL0 = 0xAE;				//���ö�ʱ��ʼֵ
	TH0 = 0xFB;				//���ö�ʱ��ʼֵ

	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0=1;
	EA=1;
	PT0=0;
}

/*
void Timer0_Routine()  interrupt 1
{
  static unsigned int T0Count;
  	TL0 = 0xAE;				//���ö�ʱ��ʼֵ
	TH0 = 0xFB;				//���ö�ʱ��ʼֵ

  T0Count++;
  if(T0Count>=1000)
  {
    T0Count=0;
  }

}
*/