#include<regx52.h>
#include"Delay.h"
sbit RCK=P3^5;	//RCLK
sbit SCK=P3^6;	 //SRCLK
sbit SER=P3^4;	 //SER
#define MATRIX_LED_PORT	 P0

 /**
   *    @brief 74HC595 写入一个字节
   *	@param	 要写入的字节
   *	@retval   无
*/
void _74HC595_WriteByte(unsigned char Byte)
{

  unsigned char i;
  for(i=0;i<8;i++)
  {
    SER=Byte&(0x80>>i); // 1000 0000
   //实现移位操作
    SCK=1;
    SCK=0;
  }
  RCK=1;//输出
  RCK=0;
}
 /**
   *    @brief   点阵屏初始化  
   *	@param	 无   
   *	@retval   无 
*/
void MatrixLED_Init()
{
   SCK=0;	//两个灯清零
   RCK=0;
}

 /**
   *    @brief   LED点阵屏显示一列数据
   *	@param	  Column要选择的列，范围0-7，0在最左边
          		   Data选择列显示的数据，高位在上，1为亮
   *	@retval   无
*/
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
   _74HC595_WriteByte(Data); 
    MATRIX_LED_PORT=~(0x80>>Column);//低电平有效
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}