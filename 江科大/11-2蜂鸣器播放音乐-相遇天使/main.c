#include <REGX52.H>
#include"Delay.h"
#include"Timer0.h"
sbit Buzzer=P2^5;
//�����ٶȣ�ֵΪ�ķ�������ʱ��(ms)
#define SPEED  513 //�����ٶ�

//P����ֹ����L��������M��������H���������»��ߣ�����������#
#define P	0
#define L1	1
#define L1_	2
#define L2	3
#define L2_	4
#define L3	5
#define L4	6
#define L4_	7
#define L5	8
#define L5_	9
#define L6	10
#define L6_	11
#define L7	12
#define M1	13
#define M1_	14
#define M2	15
#define M2_	16
#define M3	17
#define M4	18
#define M4_	19
#define M5	20
#define M5_	21
#define M6	22
#define M6_	23
#define M7	24
#define H1	25
#define H1_	26
#define H2	27
#define H2_	28
#define H3	29
#define H4	30
#define H4_	31
#define H5	32
#define H5_	33
#define H6	34
#define H6_	35
#define H7	36

//������Ƶ�ʶ��ձ�
unsigned int FreqTable[]={
	0,
51465,52255,53000,53704,54368,54995,55586,56145,56672,57169,57639,58082,
58500,58895,59268,59620,59952,60265,60561,60840,61104,
61353,61587,61809,62018,62216,62402,62578,62744,62901,
63049,63188,63320,63444,63562,63673
};

//����
unsigned char code Music[]={
	//ǰ��
    M5,2,
	M7,2,
	H1,2,
	H2,2,
	H2,2,
	H1,2,
	H2,2,
	H5,2,

	H5,2,
	H4,2,
	H3,2,
	H4,2,
	H3,1,
    H4,1,
	H3,1,
	H2,1,
	H1,2,
	M7,2,

	M1,2,
	H1,2,
	H2,2,
	M7,4,
	M5,4,
 	M6,4,


    //��Ψ
	P,4,
	M3,4,
	M1,2,
	M3,2,
	M4,2,
	M5,2,
	M4,2,
	M3,2,
	M2,2,
	M1,2,
	M3,6,

	M1,2,
	M3,2,
	M4,2,
	M5,2,
	M4,2,
	M3,2,
	M2,2,
	M3,2,
	M2,2,
	M1,6,

	M1,2,
	M3,4,
	M2,2,
	M1,6,

	M2,2,
	M3,2,
	M4,2,
	M3,2,
	M4,2,
	M3,2,
	M4,2,
	M3,2,
	M1,2,
	M3,2,
	M2,8,

	//mio
   	M3,6,
	M1,2,
	M3,2,
	M4,2,
	M5,2,
	M4,2,
	M3,2,
	M2,2,
	M1,2,
	M3,6,

	M1,2,
	M3,2,
	M4,2,
	M5,2,
	M4,2,
	M3,2,
	M2,2,
	M3,2,
	M2,2,
	M1,6,

	M2,2,
	M3,2,
	M4,2,
	M3,2,
	M4,2,
	M3,2,
	M4,2,
	M3,2,
	M1,2,
	M3,2,
	M2,6,

	//��
	M1,4,
	M3,4,
	M5,4,

	M6,2,
	M6,2,
	M6,2,
	M4,2,
	M3,2,
	M2,2,
	M3,2,
	M4,2,
	M4,2,

	M5,2,
	M5,4,
	M3,2,
	M5,4,
	M6,4,

	M3,4,
	M2,4,
	M1,6,
	M1,2,

	M4,6,
	M1,2,
	M4,6,
	M4,2,

	M5,6,
	M3,2,
	M2,2,
	M1,6,

	M2,2,
	M3,2,
	M4,2,
	M3,2,
	M4,2,
	M3,2,
	M4,2,
	M4,2,
	M5,2,
	M5,2,
	M6,4,
	M5,4,
	M6,4,
	M7,4,

	M2,4,
	M1,2,
	M1,4,
	M3,4,
	M6,4,
	M5,2,
	M5,2,
	M2,2,

	M2,4,
	M1,2,
	M1,4,
	M3,2,

	M6,4,
	M5,2,
	M5,4,
	M5,2,

	M6,4,
	M4,2,
	M1,2,
	M7,4,
	M7,2,
	M1,2,
	M2,2,
	M7,2,
	M2,2,
	M1,4,
	M3,2,

	M4,6,
	M3,2,
	M4,4,
	M5,4,

	M2,2,
	M2,2,
	M3,2,
	M2,2,
	M1,2,
	M1,2,

	//
	M2,4,
	M1,2,
	M1,4,
	M3,4,
	M6,4,
	M5,2,
	M5,2,
	M2,2,

	H2,4,
	H1,2,
	H1,4,
	M3,2,

	M6,6,
	M5,2,
	M5,6,

	M5,2,
	M6_,2,
	M4,4,
	M3,2,
	M2,2,
	M2,2,
	M3,2,
	M5,4,
	M3,2,
	M7,4,
	M6,6,

	M3,2,
	M4,4,
	M4,2,
	M4,2,
	M5,2,
	M3,4,
	M2,4,

	M1,4,
	M2,2,
	M2,2,
	M1,2,
	M1,2,

	0xFF	//��ֹ��־
};
unsigned char FreqSelect,MusicSelect;

void main()
{
	Timer0Init();
	while(1)
	{
		if(Music[MusicSelect]!=0xFF)	//�������ֹͣ��־λ
		{
			FreqSelect=Music[MusicSelect];	//ѡ��������Ӧ��Ƶ��
			MusicSelect++;
			Delay(SPEED/4*Music[MusicSelect]);	//ѡ��������Ӧ��ʱֵ
			MusicSelect++;
			TR0=0;//�رն�ʱ��
			Delay(5);	//���������ͣ��
			TR0=1;//�򿪶�ʱ��
		}
		else	//�����ֹͣ��־λ
		{
			TR0=0;
			while(1);
		}
	}
}

void Timer0_Routine() interrupt 1
{
	if(FreqTable[FreqSelect])	//���������ֹ��
	{
		/*ȡ��ӦƵ��ֵ����װ��ֵ����ʱ��*/
		TL0 = FreqTable[FreqSelect]%256;		//���ö�ʱ��ֵ
		TH0 = FreqTable[FreqSelect]/256;		//���ö�ʱ��ֵ
		Buzzer=!Buzzer;	//��ת������IO��
	}
}
