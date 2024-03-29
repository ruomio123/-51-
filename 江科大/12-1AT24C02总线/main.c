#include<regx52.h>
#include "Key.h"
#include "LCD1602.h"
#include"AT24C02.h"
#include"I2C.h"
#include"Delay.h"
unsigned char KeyNum;
unsigned int Num;
void main()
{
   LCD_Init();
   LCD_ShowNum(1,1,Num,5);
   while(1)
   {
	  KeyNum=Key();
	  if(KeyNum==1)
	  {
	    Num++;
		LCD_ShowNum(1,1,Num,5);
	  }
	  if(KeyNum==2)
	  {
	    Num--;
		LCD_ShowNum(1,1,Num,5);
	  }
	  if(KeyNum==3)
	  {
	    AT24C02_WriteByte(0,Num%256); //写入低八位
		Delay(5);
		AT24C02_WriteByte(1,Num/256);//写入高八位
		Delay(5);
		LCD_ShowString(2,1,"Write ok");
		Delay(1000);
		LCD_ShowString(2,1,"        ");
	  }
	  if(KeyNum==4)//读
	  {
	    Num=AT24C02_ReadByte(0);
		Num|=AT24C02_ReadByte(1)<<8; //复原
		LCD_ShowNum(1,1,Num,5);
				LCD_ShowString(2,1,"Read ok");
		Delay(1000);
		LCD_ShowString(2,1,"        ");
	  }
   }

}