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
  P2=0x00;
}