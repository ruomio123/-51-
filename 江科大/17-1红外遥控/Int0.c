#include <REGX52.H>
void Int0_Init(void)
{
  IT0=1;
  IE0=0;
  EX0=1;
  EA=1;	//���ж�
  PX0=1;
}
/* �ж�ģ��
  void Int0_Routine(void) interrupt 0
  {
    
  }
*/