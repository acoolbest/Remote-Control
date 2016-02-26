#include "system.h"

uint8_t testbuff[64];

void APP_Init() {
	#ifdef DebugFlag	//DebugFlag is defined in App.h
		Timer0_Start(200);	//ms unit, 16bits
	#else
		Timer0_Start(8);	//ms unit, 16bits
	#endif
}

void DebugMsg() {
	MMA7660GetDate();
	HAL_Read_Button();

	sprintf(testbuff, "Chansu DEBUG: B:%X,GX:%d,GY:%d,XYZ[%d:%d:%d]\n", Button, HAL_Read_ADC(GyroX_ADC_Port), HAL_Read_ADC(GyroY_ADC_Port), \
					(short)AccX, (short)AccY, (short)AccZ);

	UartTX(testbuff, mystrlen(testbuff));
}

void Operations() {
	HAL_Read_Button();
	if(Button==0) {
		UartStop();
		LEDOff();
		B_L_Click_Null();
		B_R_Click_Null();
		B_Conn_Null();
	
	} else if (Button==RightClickB) {
		B_R_Click_On();
	} else if (Button==LeftClickB) {
		B_L_Click_On();
	} else if (Button==AdditionB) {
		LEDOn();
		B_Conn_On();
	}

	// 자이로 값과 가속도 값 측정
	MMA7660GetDate();
	HPL_Get_GyroData();

	// 12bit크기의 X/Y 데이터로 변환
	{
		uint8_t *array;
		HPL_ISR_GLOBAL_CLR();
		array = (uint8_t *)&Xvalue;
		SPI_DATA_XL = array[0];
		SPI_DATA_XYH = array[1]<<4;

		array = (uint8_t *)&Yvalue;
		SPI_DATA_YL = array[0];
		SPI_DATA_XYH |= array[1]&0x0F;
		HPL_ISR_GLOBAL_SET();
	}
	B_ADNS_Motion_On();
}

void Timer0_Expire_Task() {
	#ifdef DebugFlag	//DebugFlag is defined in App.h
		DebugMsg();
	#else
		Operations();
	#endif
}