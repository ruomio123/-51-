#include <REGX52.H>
#include"Delay.h"
#include"Key.h"
#include"Nixie.h"
#include"Timer0.h"
unsigned char Count,Compare;
unsigned char i;
sbit DA=P2^1;
void main()
{
   Timer0_Init();
    
   while(1)
   {
     for(i=0;i<100;i++)
	 {
	   Compare=i;
	   Delay(10);
	 }
	   for(i=100;i>0;i--)
	 {
	   Compare=i;
	   Delay(10);
	 }

   }

}
 
void Timer0_Routine()  interrupt 1
{
   
  	TL0 = 0xAE;				//设置定时初始值
	TH0 = 0xFB;				//设置定时初始值
   Count++;
  if( Count>=100)
  {
     Count=0;
  }
 if(Count<Compare)
 {
   DA=1;
 }
 else
 {
   DA=0;
 }
}
 