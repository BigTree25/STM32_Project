#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "FreeRTOS.h"
#include "task.h"

//任务优先级
#define START_TASK_PRIO		4
//任务堆栈大小
#define START_TASK_SIZE		128
//任务句柄
TaskHandle_t StartTask_Handle;
//任务函数
void start_task(void *pvParameters);

//任务优先级
#define OLED_TASK_PRIO		0
//任务堆栈大小
#define OLED_TASK_SIZE		50
//任务句柄
TaskHandle_t OLEDTask_Handle;
//任务函数
void OLED_task(void *pvParameters);

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组
	OLED_Init();
	
	xTaskCreate((TaskFunction_t	)start_task,
				(const char*	)"start_task",
				(uint16_t		)START_TASK_SIZE,
				(void*			)NULL,
				(UBaseType_t	)START_TASK_PRIO,
				(TaskHandle_t*	)&StartTask_Handle);
	vTaskStartScheduler();
}

void start_task(void *pvParameters)
{
	taskENTER_CRITICAL();
	
	xTaskCreate((TaskFunction_t	)OLED_task,
				(const char*	)"OLED_task",
				(uint16_t		)OLED_TASK_SIZE,
				(void*			)NULL,
				(UBaseType_t	)OLED_TASK_PRIO,
				(TaskHandle_t*	)&OLEDTask_Handle);
				
	vTaskDelete(StartTask_Handle);
				
	taskEXIT_CRITICAL();
}

void OLED_task(void *pvParameters)
{
	while(1)
	{
		OLED_ShowNum(1, 1, 234, 5);
		OLED_Clear();
	}
}
