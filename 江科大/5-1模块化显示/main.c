#include <REGX52.H>
#include "Delay.h"	//����Delayͷ�ļ�
#include "Nixie.h"	//���������ͷ�ļ�

void main()
{
	while(1)
	{
		Nixie(1,1);	//������ܵĵ�1λ����ʾ1
		Nixie(2,2);	//������ܵĵ�2λ����ʾ2
		Nixie(3,3);	//������ܵĵ�3λ����ʾ3
		Nixie(4,4);	//������ܵĵ�4λ����ʾ4
		Nixie(5,5);	//������ܵĵ�5λ����ʾ5
		Nixie(6,6);	//������ܵĵ�6λ����ʾ6
	}
}
