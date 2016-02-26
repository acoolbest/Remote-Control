#include "system.h"

void HAL_Airoha_Init() {
	TRISB4 = 1; 
	TRISB2 = 1; 
	TRISC7 = 1; 
	TRISB5 = 0; 
	TRISA6 = 0; 
	TRISA7 = 0; 
	TRISC0 = 1; 
	TRISC1 = 1; 
	RA6 = 0;	
	RA7 = 0;	
}
