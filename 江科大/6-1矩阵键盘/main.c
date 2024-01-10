#include<regx52.h>
#include"lcd1602.h"
#include"public.h"
#include"MatrixKey.h"
unsigned char KeyNum;
void main()
{
   LCD_Init();
	 
	while(1)
	{
	  KeyNum=MatrixKey();
      if(KeyNum)   //ÅÐ¶Ï°´¼ü°´ÏÂ
	  {
	    LCD_ShowNum(2,1,KeyNum,2);
	  }

	}
}