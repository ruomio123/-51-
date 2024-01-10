#include <REGX52.H>
void Int0_Init(void)
{
  IT0=1;
  IE0=0;
  EX0=1;
  EA=1;	//开中断
  PX0=1;
}
/* 中断模板
  void Int0_Routine(void) interrupt 0
  {
    
  }
*/