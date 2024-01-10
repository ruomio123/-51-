#include<regx52.h>
#include<intrins.h>
 void Delay500ms()		//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 23;
	j = 205;
	k = 120;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
   while(1)
   {
	  P2=0xfe;//1111 1110
	  Delay500ms();
	  P2=0xfd;	 //1111 1101
	  Delay500ms();
	  P2=0xfb;	 //1111 1011 
	  Delay500ms();
	  P2=0xf7;
	  Delay500ms();
	  P2=0xef;
	  Delay500ms();
	  P2=0xdf;
	  Delay500ms();
	   P2=0xbf;
	  Delay500ms();
	   P2=0x7f;
	  Delay500ms();
	  
   }

}