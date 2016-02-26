#ifndef __TIMER_H__
#define __TIMER_H__

extern void HAL_Init_Timer0();
extern void Timer0_Start(uint16_t setValue);
extern void Timer0_Stop();
extern void HAL_ISR_Timer0();

#endif