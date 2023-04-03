#include "stm32f10x.h"                  // Device header
#include "LED.h"

void Timer_Init(void)
{
	LED_Init();
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//TIM2定时器的时钟使能，包括内外部
	
	TIM_InternalClockConfig(TIM2);							//默认使用内部时钟可以不写此句
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;		//TIM2的配置初始化
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 7200 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 10000 - 1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2, TIM_IT_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);				//使能中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);			//配置中断优先级
	
	NVIC_InitTypeDef NVIC_InitStructure;					//中断通道配置
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);									//计数器计数使能
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		LED1_Turn();
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
