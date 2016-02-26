#include "system.h"

uint8_t SPI_DATA_XL;
uint8_t SPI_DATA_YL;
uint8_t SPI_DATA_XYH;
int16_t Xvalue, Yvalue;

void HPL_Init_Gyro() {
	SPI_DATA_XL = 0;
	SPI_DATA_YL = 0;
	SPI_DATA_XYH = 0;
}

void HPL_Get_GyroData() {

	Xvalue = (int16_t)HAL_Read_ADC(GyroX_ADC_Port);
	Yvalue = (int16_t)HAL_Read_ADC(GyroY_ADC_Port);

	Xvalue -= GryoX_Zero_Value;
	Yvalue -= GryoY_Zero_Value;

	Xvalue /= Gyro_Level_Reference;
	Yvalue /= Gyro_Level_Reference;

}