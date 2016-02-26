#ifndef __UART_H__
#define __UART_H__

extern void UartInit();
extern void UartStop();
extern void UartTX(uint8_t *buff, uint8_t len);

#endif