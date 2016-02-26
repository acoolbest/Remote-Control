#include "system.h"

void LEDInit() {
	TRISC6 = 0;
	RC6 = 1;
}

void LEDOn() {
	RC6 = 0;
}

void LEDOff() {
	RC6 = 1;
}

void LEDToggle() {
	if(RC6==1) {
		RC6 = 0 ;
	} else {
		RC6 = 1;
	}
}