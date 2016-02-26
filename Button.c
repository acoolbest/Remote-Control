#include "system.h"

uint8_t Button;

void HAL_Init_Button() {
	TRISB6 = 1;	
	TRISB7 = 1;
	Button = 0;
}

void HAL_Read_Button() {
	Button = 0;
	if(RB7 == 1){Button |= RightClickB;}
	if(RB6 == 1){Button |= LeftClickB;} 
	if(RE3 == 1){Button |= AdditionB;} 
}