 #include<regx52.h>
/**
  * @brief ���ڳ�ʼ��	4800bps@11.0592MHz
  *	@param	��
  *	@retval	��
*/

void UART_Init()
{
  PCON &= 0x7F;		//�����ʲ�����
  SCON = 0x50;		//8λ����,�ɱ䲨����
  TMOD &= 0x0F;			//���ö�ʱ��ģʽ
  TMOD|=0x20;				//���ö�ʱ��ģʽ
	TL1 = 0xFA;			//���ö�ʱ��ʼֵ
	TH1 = 0xFA;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	TR1 = 1;			//��ʱ��1��ʼ��ʱ
}

/**
  * @brief ���ڷ���һ���ֽ�����
  *	@param	��
  *	@retval	��
*/
void UART_SendByte(unsigned char Byte)
{
  	SBUF=Byte;
	while(TI==0);
	TI=0;

}