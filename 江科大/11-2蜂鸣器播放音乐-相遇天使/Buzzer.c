#include<regx52.h>
#include<intrins.h>
 
sbit Buzzer=P2^5;
unsigned int i;
/**
  * @brief ������ר����ʱ���� 
  *	@param	 
  *	@retval 
*/
void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}


/**
  * @brief ����������ʱ��
  *	@param	 
  *	@retval 
*/
void Buzzer_Time(unsigned int ms)
{
  for(i=0;i<2*ms;i++)
  {
    Buzzer=!Buzzer;
     Buzzer_Delay500us();
  }
}