#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MyI2C.h"

uint8_t Ack;

int main(void)
{
	OLED_Init();
	
	MyI2C_Init();
	
	MyI2C_Start();
	MyI2C_SendByte(0xD0);
	Ack = MyI2C_ReceviceAck();
	MyI2C_Stop();
	
	OLED_ShowNum(1, 1, Ack, 3);
	
	while (1)
	{			
		
	}
}
