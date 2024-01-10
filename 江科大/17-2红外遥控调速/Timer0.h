#ifndef _TIMER0_H
#define _TIMER0_H
  void Timer0_Run(unsigned char Flag);
  unsigned int Timer0_GetCounter(void);
  void Timer0_SetCounter(unsigned int Value);
 void Timer0_Init(void);
#endif