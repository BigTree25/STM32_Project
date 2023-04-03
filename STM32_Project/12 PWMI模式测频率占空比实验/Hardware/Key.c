#include "stm32f10x.h"                  // Device header
#include "Delay.h"

/**
  * @brief  按键模块初始化，使能时钟以及初始化GPIO
  * @param  无
  * @retval 无
  */
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/**
  * @brief  返回按键情况
  * @param  无
  * @retval KeyNum：返回0代表没有按键按下，返回1代表按键1按下，返回2代表按键2按下
  */
uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)==0);
		Delay_ms(20);
		KeyNum = 1;
	}
	
	if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)==0);
		Delay_ms(20);
		KeyNum = 2;
	}
	
	return KeyNum;
}
