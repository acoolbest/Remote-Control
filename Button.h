#ifndef __BUTTON_H__
#define __BUTTON_H__

#define RightClickB	0x01
#define LeftClickB	0x02
#define AdditionB	0x04

extern uint8_t Button;
extern void HAL_Init_Button();
extern void HAL_Read_Button();

#endif