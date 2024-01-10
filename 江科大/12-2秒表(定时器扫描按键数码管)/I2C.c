#include <REGX52.H>
sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;
/**
  * @brief  I2C开始
  *	@param	 
  *	@retval 
*/
void I2C_Start(void)
{
 I2C_SCL=1;
 I2C_SDA=1;//保证都是1

 I2C_SDA=0;
 I2C_SCL=0;//完成
}
/**
  * @brief I2C停止 
  *	@param	 
  *	@retval 
*/
void I2C_Stop(void)
{
  I2C_SDA=0; //确保一开始是低电平·
  I2C_SCL=1;
  I2C_SDA=1;
}

/**
  * @brief  I2C发送一个字节
  *	@param	Byte要发送的字节 
  *	@retval 
*/
void I2C_SendByte(unsigned char Byte)
{
  unsigned char i;
  for(i=0;i<8;i++)
  {
  I2C_SDA=Byte&(0x80>>i);//从高位到低位，依次取出数据到SDA线上
  I2C_SCL=1;//再次拉高,从机读取数据位
  I2C_SCL=0; 
  }

}
/**
  * @brief  I2C接收一个字节
  *	@param	 
  *	@retval  接收到的一个字节数据
*/
unsigned char I2C_ReceiveByte(void)
{
  unsigned char Byte=0x00,i;
  I2C_SDA=1; //让从机控制SDA

  for(i=0;i<8;i++)
  {
   I2C_SCL=1;
   if(I2C_SDA){Byte|=(0x80>>i);}
   I2C_SCL=0;
   
  }

  return Byte;
}

 /**
   * @brief  发送应答
   * @param	 应答位，0应答，1不应答
   * @retval 
*/
void I2C_SendAck(unsigned char AckBit)
{
   I2C_SDA=AckBit;
   I2C_SCL=1;
   I2C_SCL=0;
}

/**
  * @brief  接收应答
  *	@param	 
  *	@retval 接收到的应答
*/
unsigned char I2C_ReceiveAck(void)
{
  unsigned char AckBit;
  I2C_SDA=1;//释放SDA
  I2C_SCL=1;
  AckBit=I2C_SDA;
  I2C_SCL=0;
  return AckBit;
}