#include<regx52.h>
#include"Delay.h"
#include"MatrixLED.h"

//��������	  ������flah�У��ؼ��� code
unsigned char code Animation[]={
	0x3C,0x42,0xA9,0x85,0x85,0xA9,0x42,0x3C,
	0x3C,0x42,0xA1,0x85,0x85,0xA1,0x42,0x3C,
	0x3C,0x42,0xA5,0x89,0x89,0xA5,0x42,0x3C,
};
void main()
{
	unsigned char i,Offset=0,Count=0;  //offƫ����
	MatrixLED_Init();
	while(1)
	{
		for(i=0;i<8;i++)	//ѭ��8�Σ���ʾ8������
		{
			MatrixLED_ShowColumn(i,Animation[i+Offset]);
		}
		Count++;			//�ƴ���ʱ
		if(Count>15) //��ʱ
		{
			Count=0;
			Offset+=8;		//ƫ��+8���л���һ֡����
			if(Offset>16)
			{
				Offset=0;
			}
		}
	}
}

