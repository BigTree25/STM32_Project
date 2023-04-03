#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"
#include "OLED.h"

uint8_t i;
uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	PWM_Init();
	while(1)
	{			
		for(i = 0;i <= 100;i++)
		{
			PWM_Set(i);
			Delay_ms(10);
		}
		for(i = 0;i <= 100;i++)
		{
			PWM_Set(100-i);
			Delay_ms(10);
		}
	}
}
