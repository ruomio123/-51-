#include<regx52.h>
  void Delay (unsigned int xms)		//@12.000MHz
{
	unsigned char data i, j;
	while(xms--)
	{
		 i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
	
}
void main()
{
  unsigned char led=0xfe,a,b;
  
  while(1)
  {
	if(P3_1==0)
	{
	  Delay(20);
	  while(P3_1==0);//ËÉ¿ª
	  Delay(20);
	  P2=led;
	  a=led>>7;
	  b=led<<1;
	  led=a|b;
	  
	}
		if(P3_0==0)
	{
	  Delay(20);
	  while(P3_0==0);//ËÉ¿ª
	  Delay(20);
	 
	  a=led<<7;
	  b=led>>1;
	  led=a|b;
	   P2=led;
	   //1111 1101

	}
  }

}