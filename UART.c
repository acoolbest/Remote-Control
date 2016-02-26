#include "system.h"

#define BAUD 38400   
#define FOSC 16000000L
#define DIVIDER ((int)(FOSC/(16UL * BAUD) -1))

void UartInit() {
	SPBRG = DIVIDER;	//baud rate.
	TX9 = 0;			
	TXEN = 1;
	SYNC = 0;
	BRGH = 1;
	BRG16 = 0;

	SPEN = 1;	//UART Enable
}

void UartStop() {
	TXEN = 0;
	SPEN = 0;
}

void UartTX(uint8_t *buff, uint8_t len) {
	uint8_t i;
	for( i = 0 ; i < len ; i++) {
		while(!TRMT);
		TXREG = buff[i];
	}
}