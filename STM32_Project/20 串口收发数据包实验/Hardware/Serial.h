#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdio.h>

extern uint8_t Serial_TxPacket[4];
extern uint8_t Serial_RxPacket[4];

void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendString(char *String);
uint32_t Serial_Pow(uint32_t X, uint32_t Y);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
uint8_t Serial_GetRxFlag(void);
void Serial_SendTxPacket(uint8_t TxPacket[]);

uint8_t Serial_GetRxData(void);
uint8_t Serial_GetRxFlag(void);
	
#endif
