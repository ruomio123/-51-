#include <REGX52.H>
#include "Timer1.h"

//���Ŷ���
sbit Motor=P1^0;

unsigned char Counter,Compare;

/**
  * @brief  �����ʼ��
  * @param  ��
  * @retval ��
  */
void Motor_Init(void)
{
	Timer1_Init();
}

/**
  * @brief  ��������ٶ�
  * @param  Speed Ҫ���õ��ٶȣ���Χ0~100
  * @retval ��
  */
void Motor_SetSpeed(unsigned char Speed)
{
	Compare=Speed;
}

//��ʱ��1�жϺ���
void Timer1_Routine() interrupt 3
{
	TL1 = 0x9C;		//���ö�ʱ��ֵ
	TH1 = 0xFF;		//���ö�ʱ��ֵ
	Counter++;
	Counter%=100;	//����ֵ�仯��Χ������0~99
	if(Counter<Compare)	//����ֵС�ڱȽ�ֵ
	{
		Motor=1;		//���1
	}
	else				//����ֵ���ڱȽ�ֵ
	{
		Motor=0;		//���0
	}
}
