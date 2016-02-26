#ifndef __AIROHA_H__
#define __AIROHA_H__

#define B_WH_W1_OnOff() 	do{if(RA6) RA6=0; else RA6=1;}while(0)
#define B_WH_W2_OnOff() 	do{if(RA7) RA7=0; else RA7=1;}while(0)

#define B_WH_Down_Done()	do{B_WH_W2_OnOff();Delay1ms();B_WH_W1_OnOff();}while(0)
#define B_WH_Up_Done()		do{B_WH_W1_OnOff();Delay1ms();B_WH_W2_OnOff();}while(0)
#define B_WH_Z_Null()		do{TRISB4 = 1;}while(0)
#define B_WH_Z_On()			do{TRISB4 = 0; RB4 = 0;}while(0)

//#define B_Reset()			do{RB2 = 0;Delay1ms();RB2 = 1;}while(0)
#define B_Reset_Null()		do{TRISB2 = 1;}while(0)
#define B_Reset_On()		do{TRISB2 = 0; RB2 = 0;}while(0)
#define B_R_Click_Null()	do{TRISC1 = 1;}while(0)
#define B_R_Click_On()		do{TRISC1 = 0; RC1 = 0;}while(0)
#define B_L_Click_Null()	do{TRISC0 = 1;}while(0)
#define B_L_Click_On()		do{TRISC0 = 0; RC0 = 0;}while(0)
#define B_ADNS_Motion_Null()	do{RB5 = 1;}while(0)
#define B_ADNS_Motion_On()		do{RB5 = 0;}while(0)
#define B_Conn_Null()		do{TRISC7 = 1;}while(0)
#define B_Conn_On()			do{TRISC7 = 0; RC7 = 0;}while(0)


extern void HAL_Airoha_Init();

#endif