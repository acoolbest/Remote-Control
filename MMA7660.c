#include "system.h"

#define MMA7660AddrRead		0b10011001
#define MMA7660AddrWrite	0b10011000

#define SDA_Output()	do{TRISB0 = 0;}while(0)
#define SDA_Input()		do{TRISB0 = 1;}while(0)
#define SDA_High()		do{RB0 = 1;}while(0)
#define SDA_Low()		do{RB0 = 0;}while(0)
#define SDA_Read()		RB0

#define SCL_Output()	do{TRISB1 = 0;}while(0)
#define SCL_High()		do{RB1 = 1;}while(0)
#define SCL_Low()		do{RB1 = 0;}while(0)

#define I2CDelay()		do{NOP();NOP();NOP();NOP();NOP();NOP();}while(0)
#define I2CStart()		do{SDA_High();I2CDelay();SCL_High();I2CDelay();SDA_Low();I2CDelay();SCL_Low();}while(0)
#define I2CStop()		do{SDA_Low();I2CDelay();SCL_High();I2CDelay();SDA_High();}while(0)
#define I2CAck()		do{SDA_Low();I2CDelay();SCL_High();I2CDelay();SCL_Low();I2CDelay();}while(0)
#define I2CNck()		do{SDA_High();I2CDelay();SCL_High();I2CDelay();SCL_Low();I2CDelay();SDA_Low();}while(0)

/////////////////////////////////////////////////////////////

uint8_t I2CReadByte() {
	uint8_t i2cdata = 0, i;
	SDA_Input();
	I2CDelay();
	for (i=8; i>0 ; i--) {
		SCL_High();
		if(SDA_Read()) i2cdata |= 1<<(i-1);
		I2CDelay();
		SCL_Low();
		I2CDelay(); 
	}
	SDA_Output();
	return i2cdata;
}

void I2CWriteByte(uint8_t i2cdata) {
	uint8_t i;
	SDA_Output();
	I2CDelay();
	for (i=8; i>0 ; i--) {
		/*
		if(0x01 & (i2cdata>>(i-1))) {
			SDA_High();
		} else {
			SDA_Low();
		}*/
		if(i2cdata & 0x80) SDA_High();
		else SDA_Low();
		I2CDelay();
		SCL_High();
		I2CDelay();
		SCL_Low();
		I2CDelay();
		i2cdata = i2cdata << 1 ;
	}
}

uint8_t I2CWaiteAck() {
	uint8_t recv_ack;
	SDA_Input();
	I2CDelay();	
	SCL_High();
	recv_ack = SDA_Read();
	I2CDelay();
	SCL_Low();
	SDA_Output();
	if(recv_ack) return 1;
	else return 0;
}

/////////////////////////////////////////////////////////////

void I2C_Read_Multi_Bytes(uint8_t waddr, uint8_t raddr, uint8_t reg, uint8_t *multi_data, uint8_t cnt) {
	uint8_t i;

	/////////////////////////////	
	//I2C start
	I2CStart();
	
	////////////////////////////////////////////////////////////
	// send Device Write ADDRESS
	I2CWriteByte (waddr);
	// wait ACK
	I2CWaiteAck(); 
	// send reg
	I2CWriteByte (reg);
	// wait ACK
	I2CWaiteAck(); 
	//I2C stop
	I2CStop();
	////////////////////////////////////////////////////////////

	I2CDelay();
	
	////////////////////////////////////////////////////////////
	//I2C_START();
	I2CStart();
	// send Device Read ADDRESS 
	I2CWriteByte (raddr);
	// wait ACK
	I2CWaiteAck(); 
	
	// read Data
	for( i=0 ; i<cnt ; i++){
		// send reg
		multi_data[i] = I2CReadByte();
		if(i==(cnt-1)) {
			// send NACK
			I2CNck();
		} else{
			// send ACK
			I2CAck();
		}
 	}
	////////////////////////////////////////////////////////////

	//I2C stop
	I2CStop();
	/////////////////////////////
}

void I2C_Write_One_Byte(uint8_t waddr, uint8_t reg, uint8_t one_data) {
	/////////////////////////////
	//I2C start
	I2CStart();
	
	////////////////////////////////////////////////////////////
	// send Device Write ADDRESS
	I2CWriteByte (waddr);
	// wait ACK
	I2CWaiteAck(); 	
	// send reg
	I2CWriteByte (reg);
	// wait ACK
	I2CWaiteAck();
	////////////////////////////////////////////////////////////
	
	////////////////////////////////////////////////////////////	
	// send one_data
	I2CWriteByte (one_data);
	// wait ACK
	I2CWaiteAck();
	////////////////////////////////////////////////////////////

	//I2C stop
	I2CStop();
	/////////////////////////////
}

////////////////////////////////////////////////////////////////////////


void HPL_Init_MMA7660() {
	SDA_Output();
	SCL_Output();
	SDA_High();
	SCL_High();

	I2CDelay();

	I2C_Write_One_Byte(MMA7660AddrWrite, 0x08, 0x02); 	// sampling set to 32
	I2C_Write_One_Byte(MMA7660AddrWrite, 0x07, 0x11);	// mode, auto-sleep
}

int8_t  AccX, AccY, AccZ;

void MMA7660GetDate() {
	uint8_t Accel_Buff[3];

	I2C_Read_Multi_Bytes(MMA7660AddrWrite, MMA7660AddrRead, 0x00, Accel_Buff, 3);

	if(Accel_Buff[0] & 0x20) {
		AccX = (int8_t) Accel_Buff[0] & 0x1F;
		AccX |= 0xE0;
	} else {
		AccX = (int8_t) Accel_Buff[0] & 0x1F;
	}
	
	if(Accel_Buff[1] & 0x20) {
		AccY = (int8_t) Accel_Buff[1] & 0x1F;
		AccY |= 0xE0;
	} else {
		AccY = (int8_t) Accel_Buff[1] & 0x1F;
	}

	if(Accel_Buff[2] & 0x20) {
		AccZ = (int8_t) Accel_Buff[2] & 0x1F;
		AccZ |= 0xE0;
	} else {
		AccZ = (int8_t) Accel_Buff[2] & 0x1F;
	}		
}
