#include <REGX52.H>
#include"lcd1602.h"
#include"DS18B20.h"
#include"Delay.h"
float T;

void main()
{
   DS18B20_ConvertT();		//�ϵ���ת��һ���¶ȣ���ֹ��һ�ζ����ݴ���
   Delay(1000);			//�ȴ�ת�����
   LCD_Init();
   LCD_ShowString(1,1,"Temperature:");
    
 	while(1)
	{
		DS18B20_ConvertT();	//ת���¶�
		T=DS18B20_ReadT();	//��ȡ�¶�
		if(T<0)				//����¶�С��0
		{
			LCD_ShowChar(2,1,'-');	//��ʾ����
			T=-T;			//���¶ȱ�Ϊ����
		}
		else				//����¶ȴ��ڵ���0
		{
			LCD_ShowChar(2,1,'+');	//��ʾ����
		}
		LCD_ShowNum(2,2,T,3);		//��ʾ�¶���������
		LCD_ShowChar(2,5,'.');		//��ʾС����
		LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);//��ʾ�¶�С������
	}

}