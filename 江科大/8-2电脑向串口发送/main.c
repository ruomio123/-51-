#include<regx52.h>
#include"Delay.h"
#include"UART.h"
 unsigned char Sec;
void main()
{
  UART_Init();
 
   while(1)
   {
	   
   }
  
}

void UART_Routine() interrupt 4
{
   if(RI==1) //溢出
   {
	 P2=~SBUF; //读数据
	 UART_SendByte(SBUF);//发送给电脑			 
	 RI=0;//清零，接收中断标志位
   }
}