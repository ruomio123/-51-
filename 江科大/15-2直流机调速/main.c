#include <REGX52.H>
#include"Delay.h"
#include"Key.h"
#include"Nixie.h"
#include"Timer0.h"
unsigned char Count,Compare,KeyNum,Speed;
sbit Montor=P1^0;
void main()
{
   Timer0_Init();
    
   while(1)
   {
	 KeyNum=Key();
	 if(KeyNum==1)
	 {
	   Speed++;
	   Speed%=4;
	   if(Speed==0)	{Compare=0;}
	    if(Speed==1)	{Compare=30;}
		 if(Speed==2)	{Compare=60;}
		  if(Speed==3)	{Compare=100;}
	 }
	 Nixie(1,Speed);
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
   Montor=1;
 }
 else
 {
   Montor=0;
 }
}
 