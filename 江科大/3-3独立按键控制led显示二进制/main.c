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
  unsigned char ledNum=0;
   while(1)
   {
	if(P3_1==0)
	{
	 Delay(20);//Èí¼þÏû¶¶
	 while(!P3_1);
	 Delay(20);
	 //1111 1111 
	 ledNum++;
	 P2=~ledNum;
	}


   }

}