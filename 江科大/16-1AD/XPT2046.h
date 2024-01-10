#ifndef _XPT2046_H_
#define _XPT2046_H_
#define XPT2046_XP  0x9C//0x8C  8λ
#define XPT2046_YP  0xDC 
#define XPT2046_VBAT  0xAC 
#define XPT2046_AUX  0xEC  

#define XPT2046_XP_12  0x94//0x8C
#define XPT2046_YP_12  0xD4 
#define XPT2046_VBAT_12 0xA4 
#define XPT2046_AUX_12  0xE4 

unsigned int XPT2046_ReadAD(unsigned char Command);

#endif