#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#define HPL_ISR_GLOBAL_CLR()	do{GIE = 0;}while(0)
#define HPL_ISR_GLOBAL_SET()	do{GIE = 1;}while(0)

extern void HAL_Init_Hardware();

#endif