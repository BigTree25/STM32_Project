#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "AD.h"
#include "Delay.h"

uint16_t ADValue;
float Volatge;

int main(void)
{
	OLED_Init();
	AD_Init();
	
	OLED_ShowString(1, 1, "ADValue:");
	OLED_ShowString(2, 1, "Volatge:0.00V");
	while(1)
	{	
		ADValue = AD_GetValue();
		Volatge = (float)ADValue / 4095 * 3.3;
		
		OLED_ShowNum(1, 9, ADValue, 4);
		OLED_ShowNum(2, 9, Volatge, 1);
		OLED_ShowNum(2, 11, (uint16_t)(Volatge * 100) % 100, 2);
		
		Delay_ms(100);
	}
}
