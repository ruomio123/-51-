#include<regx52.h>
#include"lcd1602.h"
#include"public.h"
#include"MatrixKey.h"
unsigned char KeyNum;
unsigned int Password,count;
void main()
{
    LCD_Init();
    LCD_ShowString(1,1,"PassWord"); 	 
	while(1)
	{
	  KeyNum=MatrixKey();
      if(KeyNum)   //�жϰ�������
	  {
	   if(KeyNum<=10)//���s1-s10����	s1-s10Ϊ������,10��Ϊ0
	   {
	     if(count<4)
		 {
		 Password*=10;	//��������һλ
	     Password+=KeyNum%10;//��ȡһλ����
		 count++; //���������һ
		 }
	    LCD_ShowNum(2,1,Password,4);//������ʾ//�ڶ��е�һ�п�ʼ��ʾ������Ϊ4 
	   }

	   if(KeyNum==11)  //s11���£�ȷ������
	   {
		 if(Password==2345)
		 {
		    LCD_ShowString(2,7,"weikeke sb");
			Password=0;
		    count=0;
		    LCD_ShowNum(2,1,Password,4);
		 }
		 else 
		 {
		    LCD_ShowString(2,7,"error");
			Password=0;
			count=0;			//����
			LCD_ShowNum(2,1,Password,4);//������ʾ//�ڶ��е�һ�п�ʼ��ʾ������Ϊ4
		 }
	   }
        if(KeyNum==12) //s12���£�ȡ��
		{
		  	Password=0;
			count=0;			//����
			LCD_ShowNum(2,1,Password,4);//������ʾ//�ڶ��е�һ�п�ʼ��ʾ������Ϊ4
		
		}  
	  }

	}
}