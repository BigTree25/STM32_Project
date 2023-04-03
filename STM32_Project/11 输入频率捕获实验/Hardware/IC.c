#include "stm32f10x.h"                  // Device header

void IC_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM4);
	
	TIM_TimeBaseInitTypeDef TIM_TimwBaseInitStucture;
	TIM_TimwBaseInitStucture.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimwBaseInitStucture.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimwBaseInitStucture.TIM_Period = 65536 - 1;
	TIM_TimwBaseInitStucture.TIM_Prescaler = 72 - 1;
	TIM_TimwBaseInitStucture.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimwBaseInitStucture);
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM4, &TIM_ICInitStructure);
	
	TIM_SelectInputTrigger(TIM4, TIM_TS_TI1FP1);
	TIM_SelectSlaveMode(TIM4, TIM_SlaveMode_Reset);
	
	TIM_Cmd(TIM4, ENABLE);
}

uint32_t IC_GetFreq(void)
{
	return 1000000 / (TIM_GetCapture1(TIM4)+1);
}
