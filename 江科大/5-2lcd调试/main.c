#include <REG52.H>
#include "LCD1602.h"	//����LCD1602ͷ�ļ�
#include "Delay.h"		//����Delayͷ�ļ�
 

void main()
{
     LCD_Init();
	 LCD_ShowString(1,3,"hello");
}
