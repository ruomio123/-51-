#include<reg51.h> 

void delay(void)
{
  unsigned int i;
  for(i=0;i<30000;i++);

}
void main()
{
   unsigned char i;
   while(1)
   {
	for(i=0;i<255;i++)
	{
	  P2=i;
	  delay();
	}
   }
}