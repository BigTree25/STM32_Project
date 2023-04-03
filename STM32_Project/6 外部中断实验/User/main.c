#include "stm32f10x.h"                  // Device header
#include "CounterSensor.h"
#include "LED.h"

uint8_t KeyNum;

int main(void)
{
	LED_Init();
	CounterSensor_Init();			
	while(1)
	{			
		
	}
}
