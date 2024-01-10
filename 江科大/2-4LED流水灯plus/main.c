  #include<regx52.h>
  void Delay(unsigned  int xms)		//@12.000MHz
{
	unsigned char i, j;
for(i=0;i<xms;i++)
for(j=0;j<xms;j++);
    
}

  void main()
  {
  while(1)
  {
	 P2=0xfe;
	 Delay(200);
	 P2=0xef;
	 Delay(200);
  }
	 

  }