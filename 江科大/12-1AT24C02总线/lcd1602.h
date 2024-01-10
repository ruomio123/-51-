#ifndef _lcd1602_H
#define _lcd1602_H

#include "public.h"

//LCD1602���ݿ�4λ��8λ���壬��Ϊ1����ΪLCD1602��λ���ݿ���������֮Ϊ8λ
#define LCD1602_4OR8_DATA_INTERFACE	0	//Ĭ��ʹ��8λ���ݿ�LCD1602

//�ܽŶ���
sbit LCD1602_RS=P2^6;//��������ѡ��
sbit LCD1602_RW=P2^5;//��дѡ��
sbit LCD1602_E=P2^7; //ʹ���ź�
#define LCD1602_DATAPORT P0	//�궨��LCD1602���ݶ˿�


//��������
//�û����ú�����
void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
#endif