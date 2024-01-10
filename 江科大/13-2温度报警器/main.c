#include <REGX52.H>
#include "lcd1602.h"
#include "DS18B20.h"
#include "Delay.h"
#include "AT24C02.h"
#include "Key.h"
#include "Timer0.h"

float T,TShow;
char TLow,THigh;
unsigned char KeyNum;

void main()
{
	DS18B20_ConvertT();		//�ϵ���ת��һ���¶ȣ���ֹ��һ�ζ����ݴ���
	Delay(1000);			//�ȴ�ת�����
	THigh=AT24C02_ReadByte(0);	//��ȡ�¶���ֵ����
	TLow=AT24C02_ReadByte(1);
	if(THigh>125 || TLow<-55 || THigh<=TLow)
	{
		THigh=20;			//�����ֵ�Ƿ�������ΪĬ��ֵ
		TLow=15;
	}
	LCD_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	LCD_ShowSignedNum(2,4,THigh,3);
	LCD_ShowSignedNum(2,12,TLow,3);
	Timer0_Init();
	
	while(1)
	{
		KeyNum=Key();
		
		/*�¶ȶ�ȡ����ʾ*/
		DS18B20_ConvertT();	//ת���¶�
		T=DS18B20_ReadT();	//��ȡ�¶�
		if(T<0)				//����¶�С��0
		{
			LCD_ShowChar(1,3,'-');	//��ʾ����
			TShow=-T;		//���¶ȱ�Ϊ����
		}
		else				//����¶ȴ��ڵ���0
		{
			LCD_ShowChar(1,3,'+');	//��ʾ����
			TShow=T;
		}
		LCD_ShowNum(1,4,TShow,3);		//��ʾ�¶���������
		LCD_ShowChar(1,7,'.');		//��ʾС����
		LCD_ShowNum(1,8,(unsigned long)(TShow*100)%100,2);//��ʾ�¶�С������
		
		/*��ֵ�жϼ���ʾ*/
		if(KeyNum)
		{
			if(KeyNum==1)	//K1������THigh����
			{
				THigh++;
				if(THigh>125){THigh=125;}
			}
			if(KeyNum==2)	//K2������THigh�Լ�
			{
				THigh--;
				if(THigh<=TLow){THigh++;}
			}
			if(KeyNum==3)	//K3������TLow����
			{
				TLow++;
				if(TLow>=THigh){TLow--;}
			}
			if(KeyNum==4)	//K4������TLow�Լ�
			{
				TLow--;
				if(TLow<-55){TLow=-55;}
			}
			LCD_ShowSignedNum(2,4,THigh,3);	//��ʾ��ֵ����
			LCD_ShowSignedNum(2,12,TLow,3);
			AT24C02_WriteByte(0,THigh);		//д�뵽At24C02�б���
			Delay(5);
			AT24C02_WriteByte(1,TLow);
			Delay(5);
		}
		if(T>THigh)			//Խ���ж�
		{
			LCD_ShowString(1,13,"OV:H");
		}
		else if(T<TLow)
		{
			LCD_ShowString(1,13,"OV:L");
		}
		else
		{
			LCD_ShowString(1,13,"    ");
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0xCD;				//���ö�ʱ��ʼֵ
	TH0 = 0xD4;				//���ö�ʱ��ʼֵ
	T0Count++;
	if(T0Count>=20)
	{
		T0Count=0;
		Key_Loop();	//ÿ20ms����һ�ΰ�����������
	}
}
