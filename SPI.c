#include "system.h"

/* Master
void SPIInit() {
	TRISA5 = 0;
	RA5 = 1; 		// NCS
	TRISC3 = 0; 	// SCK
	TRISC4 = 0; 	// MOSI
	TRISC5 = 1;		// MISO

	//BOEN = 0;
	CKP = 1;		//Idle state for clock is a high
	CKE = 0;		//Rising edge
	SMP = 0;		//Input data in middle of output

	SSPCON1bits.SSPM = 0b0100; //Slave mode
	//SSPCON1bits.SSPM = 0b0101; //Slave mode no cs
	
	SSPEN = 1; 
}

uint8_t HPL_CMD_SPI_RW (uint8_t value) {
	SSPBUF = value;		// Write data 
						// Wait for data available in rx_fifo
	while(BF==0);		// 0 -> SSPBUF is empty
						// 1 -> 1 is full
	return SSPBUF;		// Return data register
}

uint8_t SPIRead(){
	uint8_t re;
	RA5 = 0;
	re = HPL_CMD_SPI_RW(0);
	RA5 = 1;
	return re;
}

void SPIWrite(uint8_t writedata) {
	RA5 = 0;
	HPL_CMD_SPI_RW(writedata);
	RA5 = 1;

}
*/



void HAL_Init_SPI_Slave(){
	SSSEL = 0;		// SS function is on RA5
	SSPIE = 0;		// Disables the MSSP Intterupt
	SSPIF = 0;		// Interrupt is not pending
	
	TRISA5 = 1;
	TRISC3 = 1; 	// SCK
	TRISC4 = 1; 	// MOSI
	TRISC5 = 0;		// MISO

	CKP = 1;		//Idle state for clock is a high
	CKE = 0;		//Rising edge
	SSPCON1bits.SSPM = 0b0101; //Slave mode no cs
	SMP = 0;		//Input data in middle of output

	SSPEN = 1;
	SSPIE = 1;
}