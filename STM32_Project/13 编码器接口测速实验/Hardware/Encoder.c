#include "stm32f10x.h"                  // Device header

void Encoder_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM_TimeBaseInitTypeDef TIM_TimwBaseInitStucture;
	TIM_TimwBaseInitStucture.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimwBaseInitStucture.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimwBaseInitStucture.TIM_Period = 65536 - 1;
	TIM_TimwBaseInitStucture.TIM_Prescaler = 1 - 1;
	TIM_TimwBaseInitStucture.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimwBaseInitStucture);
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInit(TIM4, &TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInit(TIM4, &TIM_ICInitStructure);
	
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	
	TIM_Cmd(TIM4, ENABLE);
}

int16_t Encoder_Get(void)
{
	return TIM_GetCounter(TIM4);
}
