#include <REG52.H>
#include "LCD1602.h"	//包含LCD1602头文件
#include "Delay.h"		//包含Delay头文件
 

void main()
{
     LCD_Init();
	 LCD_ShowString(1,3,"hello");
}
