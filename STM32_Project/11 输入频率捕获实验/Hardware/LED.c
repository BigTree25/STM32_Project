#include "stm32f10x.h"                  // Device header
/**
  * @brief  初始化LED模块，使能LED的IO口时钟以及配置GPIO
  * @param  无
  * @retval 无
  */
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_5);
	GPIO_SetBits(GPIOE, GPIO_Pin_5);
}

/**
  * @brief  点亮LED1
  * @param  无
  * @retval 无
  */
void LED1_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
}

/**
  * @brief  点亮LED2
  * @param  无
  * @retval 无
  */
void LED2_ON(void)
{
	GPIO_ResetBits(GPIOE, GPIO_Pin_5);
}

/**
  * @brief  熄灭LED1
  * @param  无
  * @retval 无
  */
void LED1_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_5);
}

/**
  * @brief  熄灭LED2
  * @param  无
  * @retval 无
  */
void LED2_OFF(void)
{
	GPIO_SetBits(GPIOE, GPIO_Pin_5);
}

/**
  * @brief  使LED1的点亮情况反转
  * @param  无
  * @retval 无
  */
void LED1_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_5) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_5);
	}else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	}
}

/**
  * @brief  使LED2的点亮情况反转
  * @param  无
  * @retval 无
  */
void LED2_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5) == 0)
	{
		GPIO_SetBits(GPIOE, GPIO_Pin_5);
	}else
	{
		GPIO_ResetBits(GPIOE, GPIO_Pin_5);
	}
}
