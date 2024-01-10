#include<REGX52.h>
//���Ŷ���
sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

//�Ĵ���д���ַ/ָ���
#define DS1302_SECOND		0x80
#define DS1302_MINUTE		0x82
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86
#define DS1302_MONTH		0x88
#define DS1302_DAY			0x8A
#define DS1302_YEAR			0x8C
#define DS1302_WP			0x8E

//ʱ�����飬����0~6�ֱ�Ϊ�ꡢ�¡��ա�ʱ���֡��롢����
unsigned char DS1302_Time[]={23,8,10,22,52,33,6};

/**
  * @brief  DS1302��ʼ��
  * @param  ��
  * @retval ��
  */
void DS1302_Init(void)
{
	DS1302_CE=0;
	DS1302_SCLK=0;
}

/**
  * @brief  DS1302дһ���ֽ�
  * @param  Command ������/��ַ
  * @param  Data Ҫд�������
  * @retval ��
  */
void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}

/**
  * @brief  DS1302��һ���ֽ�
  * @param  Command ������/��ַ
  * @retval ����������
  */
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i,Data=0x00;
	Command|=0x01;	//��ָ��ת��Ϊ��ָ��
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=0;
		DS1302_SCLK=1;
	}
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data|=(0x01<<i);}
	}
	DS1302_CE=0;
	DS1302_IO=0;	//��ȡ��IO����Ϊ0��������������ݻ����
	return Data;
}

void DS1302_SetTime(void)
{
   DS1302_WriteByte(DS1302_WP,0x00);	//�ر�д����
   DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);//ʮ����תbcd
   DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
   DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
   DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
   DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
   DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
   DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
   DS1302_WriteByte(DS1302_WP,0x80);
}
void DS1302_ReadTime(void)
{
  unsigned char Temp;
  Temp=DS1302_ReadByte(DS1302_YEAR);
  DS1302_Time[0]=Temp/16*10+Temp%16;//bcdתʮ����
  Temp=DS1302_ReadByte(DS1302_MONTH);
  DS1302_Time[1]=Temp/16*10+Temp%16;//bcdתʮ����
  Temp=DS1302_ReadByte(DS1302_DATE);
  DS1302_Time[2]=Temp/16*10+Temp%16;//bcdתʮ����
  Temp=DS1302_ReadByte(DS1302_HOUR);
  DS1302_Time[3]=Temp/16*10+Temp%16;//bcdתʮ����
  Temp=DS1302_ReadByte(DS1302_MINUTE);
  DS1302_Time[4]=Temp/16*10+Temp%16;//bcdתʮ����
  Temp=DS1302_ReadByte(DS1302_SECOND);
  DS1302_Time[5]=Temp/16*10+Temp%16;//bcdתʮ����
  Temp=DS1302_ReadByte(DS1302_DAY);
  DS1302_Time[6]=Temp/16*10+Temp%16;//bcdתʮ����

}
