#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Serial.h"

int main(void)
{
	uint8_t MyArray[] = {0x10, 0x20, 0x30, 0x40};
	
	OLED_Init();
	
	Serial_Init();
	
	Serial_SendByte(0x41);
	
	Serial_SendArray(MyArray, 4);
	
	Serial_SendString("Hello");
	
	printf("Num=%d\n",666);
	while (1)
	{
		
	}
}
