#ifndef _lcd1602_H
#define _lcd1602_H

#include "public.h"

//LCD1602数据口4位和8位定义，若为1，则为LCD1602四位数据口驱动，反之为8位
#define LCD1602_4OR8_DATA_INTERFACE	0	//默认使用8位数据口LCD1602

//管脚定义
sbit LCD1602_RS=P2^6;//数据命令选择
sbit LCD1602_RW=P2^5;//读写选择
sbit LCD1602_E=P2^7; //使能信号
#define LCD1602_DATAPORT P0	//宏定义LCD1602数据端口


//函数声明
//用户调用函数：
void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
#endif