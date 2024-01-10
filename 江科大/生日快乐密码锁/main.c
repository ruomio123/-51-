#include<regx52.h>
#include"lcd1602.h"
#include"public.h"
#include"MatrixKey.h"
unsigned char KeyNum;
int Password,count;
void main()
{
    LCD_Init();
    LCD_ShowString(1,1,"PassWord"); 	 
	while(1)
	{
	  KeyNum=MatrixKey();
      if(KeyNum)   //判断按键按下
	  {
	   if(KeyNum<=10)//如果s1-s10按下	s1-s10为密码区,10作为0
	   {
	     if(count<7)
		 {
		 Password*=10;	//密码左移一位
	     Password+=KeyNum%10;//获取一位密码
		 count++; //输入次数加一
		 }
	    LCD_ShowNum(2,1,Password,3);//更新显示//第二行第一列开始显示，长度为8 
	   }

	   if(KeyNum==11)  //s11按下，确认密码
	   {
		 if(Password==810)
		 {
		    LCD_ShowString(1,1,"coco    "); 
		    LCD_ShowString(2,1,"happy birthday");
			Password=0;
		    count=0;
		 }
		 else 
		 {
		    LCD_ShowString(2,1,"error");
			Password=0;
			count=0;			//清零
			LCD_ShowNum(2,1,Password,8);//更新显示//第二行第一列开始显示，长度为4
		 }
	   }
        if(KeyNum==12) //s12按下，取消
		{
		  	Password=0;
			count=0;			//清零
			LCD_ShowNum(2,1,Password,8);//更新显示//第二行第一列开始显示，长度为4
		
		}  
	  }

	}
}