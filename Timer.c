#include "system.h"

uint16_t Timer0_Setting_Count;
uint16_t Timer0_Setting_Vaule;

void HAL_Init_Timer0() {
	TMR0CS = 0;	//내부클럭
	PSA = 0;	//Prescale사용
	OPTION_REGbits.PS = 0b011; // 1/16
	Timer0_Setting_Count = 0;
	Timer0_Setting_Vaule = 0;
}

void Timer0_Start(uint16_t setValue) {
	TMR0 = 0;
	TMR0IE = 1;
	Timer0_Setting_Vaule = setValue;
	Timer0_Setting_Count = setValue;
}

void Timer0_Stop() {
	TMR0IE = 0;
}

void HAL_ISR_Timer0() {
	if(Timer0_Setting_Count > 0){
		Timer0_Setting_Count--;
		if(Timer0_Setting_Count == 0) {
			Timer0_Setting_Count = Timer0_Setting_Vaule;
			//Timer0_Expire_Task(); //app.c
			TaskPost(Event_TimerExpired_TaskID);
		}
	}
}