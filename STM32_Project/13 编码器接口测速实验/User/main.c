#include "stm32f10x.h"                  // Device header
#include "Encoder.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
	Encoder_Init();
	
	OLED_ShowString(1, 1, "CNT:");
	while(1)
	{
		OLED_ShowSignedNum(1, 5, Encoder_Get(), 5);
	}
}
