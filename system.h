#include <htc.h>
#include <stdio.h>

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;

extern uint8_t mystrlen(uint8_t *strbuff);
extern void GeneralTask();

/////////////////////////////
#define Delay20us()			do{ uint8_t delay10uCNT = 10; \
								while(delay10uCNT--){} }while(0)
#define Delay100us()		do{	uint8_t delay100uCNT = 5; \
								while(delay100uCNT--){ Delay20us();} }while(0)
#define Delay1ms()			do{	uint8_t delay1mCNT = 50; \
								while(delay1mCNT--){ Delay20us();} }while(0)
/////////////////////////////

#include "LED.h"
#include "Button.h"
#include "Timer.h"
#include "UART.h"
#include "ADC.h"
#include "MMA7660.h"
#include "SPI.h"
#include "Gyro_ADC.h"
#include "Airoha.h"
#include "App.h"
#include "Hardware.h"
#include "schedule.h"
