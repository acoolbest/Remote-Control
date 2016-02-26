#ifndef __GYRO_ADC_H__
#define __GYRO_ADC_H__

#define GryoX_Zero_Value	512
#define GryoY_Zero_Value	512
#define Gyro_Level_Reference	5

extern uint8_t SPI_DATA_XL;
extern uint8_t SPI_DATA_YL;
extern uint8_t SPI_DATA_XYH;

extern int16_t Xvalue, Yvalue;

#define GyroX_ADC_Port 0
#define GyroY_ADC_Port 1

extern void HPL_Init_Gyro();
extern void HPL_Get_GyroData();

#endif