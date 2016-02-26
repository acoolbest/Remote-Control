#include "system.h"

void HAL_Init_ADC() {
	TRISA0 = 1;
	TRISA1 = 1;
	ANSA0 = 1;
	ANSA1 = 1;

	ADFM = 1;
	ADCON1bits.ADCS = 0b001;	// Fosc/8
	ADCON1bits.ADPREF = 0b00;	// DVCC

}

uint16_t HAL_Read_ADC (uint8_t ADC_Channel)  {

	ADCON0bits.CHS = ADC_Channel;

	ADON = 1;
	GO_nDONE = 1;
	while(GO_nDONE);
	ADON = 0;

	return ADRES;
}
