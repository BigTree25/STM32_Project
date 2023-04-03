#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Delay.h"
#include "Key.h"

uint8_t KeyNum;							

int main(void)
{
	Key_Init();							//按键模块初始化
	LED_Init();							//LED模块初始化
	while(1)
	{
		KeyNum = Key_GetNum();			//接受按键返回字符，0为没有按键按下
		if(KeyNum == 1){LED1_Turn();}	//按键1按下返回0，使LED1点亮反转
		if(KeyNum == 2){LED2_Turn();}	//按键2按下返回0，使LED2点亮反转
	}
}
