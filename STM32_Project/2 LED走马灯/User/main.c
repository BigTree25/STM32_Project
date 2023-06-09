#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
//	GPIO_SetBits(GPIOB, GPIO_Pin_5);
//	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
//	GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_SET);
//	GPIO_Write(GPIOB, ~0x0020);
	while (1)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);
		Delay_ms(500);
		GPIO_SetBits(GPIOB, GPIO_Pin_5);
		GPIO_ResetBits(GPIOE, GPIO_Pin_5);
		Delay_ms(500);
		GPIO_SetBits(GPIOE, GPIO_Pin_5);
	}
}
