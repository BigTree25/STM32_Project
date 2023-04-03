#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStucture;
	TIM_TimeBaseInitStucture.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStucture.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStucture.TIM_Period = 100-1;				//ARR
	TIM_TimeBaseInitStucture.TIM_Prescaler = 720-1;				//PSC
	TIM_TimeBaseInitStucture.TIM_RepetitionCounter = 0x00;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStucture);
	
	TIM_OCInitTypeDef TIM_OCInitStucture;
	TIM_OCStructInit(&TIM_OCInitStucture);
	TIM_OCInitStucture.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStucture.TIM_OCNPolarity = TIM_OCPolarity_High;
	TIM_OCInitStucture.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStucture.TIM_Pulse = 0;							//CCR
	TIM_OC2Init(TIM3, &TIM_OCInitStucture);
	
	TIM_Cmd(TIM3, ENABLE);
}

void PWM_Set(uint16_t compare)
{
	TIM_SetCompare2(TIM3, compare);
}
