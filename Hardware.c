#include "system.h"

void HAL_Init_Port() {
	ANSELA = 0;	
	ANSELB = 0;
	ANSELC = 0;
	LEDInit();
}


void HAL_Init_Hardware() {
	OSCCONbits.IRCF = 0b1111;	// 16Mhz 속도로 클럭 설정
	HAL_Init_Port(); 			// GPIO 포트 및 LED 초기화
	HAL_Airoha_Init(); 			// 블루투스 칩 초기화
	HAL_Init_Button(); 			// 버튼 초기화
	HAL_Init_Timer0(); 			// Timer 초기화
	HAL_Init_ADC();    			// ADC 레지스터 초기화
	HPL_Init_Gyro();   			// 자이로 관련 초기화
	HPL_Init_MMA7660(); 		// 가속도 관련 초기화
	HAL_Init_SPI_Slave(); 		// SPI 레지스터 초기화
	#ifdef DebugFlag	//DebugFlag is defined in App.h
		UartInit();
	#endif
	ScheduleInit();
}

interrupt ServiceRoutine(void) {	

	if(SSPIF == 1) {		//Synch Serial Port (SPI)
		uint8_t recv_spi = SSPBUF;
		//*
		if(recv_spi==0x05) {
			SSPBUF = SPI_DATA_XYH;
			B_ADNS_Motion_Null();
		}
		else if(recv_spi==0x03) {
			SSPBUF = SPI_DATA_XL;
		}
		else if(recv_spi==0x04) {
			SSPBUF = SPI_DATA_YL;

		} else {
			SSPBUF = 0x80;
		}//*/
		SSPIF = 0;
	
	} else if(TMR0IF) {	// Timer0 Overflow Intterupt
		TMR0IF = 0;
		HAL_ISR_Timer0();

	}else if(TMR1IF == 1) {	//Timer1 Overflow
		TMR1IF = 0 ;

	} else if(INTF == 1) {		//RB0/INT 
		INTF = 0 ;

	} else if(IOCIF == 1) {		//Port B Change 
		IOCBF = 0 ;
		IOCIF = 0 ;

	} else if(TMR1GIF == 1) {	//Timer1 Gate INT
		TMR1GIF = 0 ;

	} else if(ADIF == 1) {		//ADC Converter
		ADIF = 0 ;

	} else if(RCIF == 1) {		//USART RX
		RCIF = 0 ;

	} else if(TXIF == 1) {		//USART TX
		TXIF = 0 ;

	} else if(CCP1IF == 1) {	//CCP1 INT
		CCP1IF = 0 ;

	} else if(TMR2IF == 1) {	//Timer2 to PR2 
		TMR2IF = 0 ;

	} else if(TMR1IF == 1) {	//Timer1 to PR1 
		TMR1IF = 0 ;

	} else if(OSFIF == 1) {		//Oscillator Fail
		OSFIF = 0 ;
	
	} else if(BCLIF == 1) {		//MSSP Bus Collision
		BCLIF = 0 ;
	
	} else if(CCP2IF == 1) {		//CCP2 INT
		CCP2IF = 0 ;
	}
}
