#include "stm32f10x.h"                  // Device header
#include "Delay.h"

#define SCL_PORT GPIOF
#define SCL_PIN GPIO_Pin_3
#define SDA_PORT GPIOF
#define SDA_PIN GPIO_Pin_4

void MyI2C_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = SCL_PIN | SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOF, SCL_PIN | SDA_PIN);
}

void MyI2C_W_SCL(uint8_t BitValue)
{
	GPIO_WriteBit(SCL_PORT, SCL_PIN, (BitAction)BitValue);
	Delay_us(10);
}

void MyI2C_W_SDA(uint8_t BitValue)
{
	GPIO_WriteBit(SDA_PORT, SDA_PIN, (BitAction)BitValue);
	Delay_us(10);
}

uint8_t MyI2C_R_SDA(void)
{
	uint8_t a;
	a = GPIO_ReadInputDataBit(SDA_PORT, SDA_PIN);
	Delay_us(10);
	return a;
}

void MyI2C_Start(void)
{
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(0);
}

void MyI2C_Stop(void)
{
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(1);
}

void MyI2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for(i = 0;i < 8;i ++)
	{
		MyI2C_W_SDA(Byte & (0x80 >> i));
		MyI2C_W_SCL(1);
		MyI2C_W_SCL(0);
	}
}

uint8_t MyI2C_ReceviceByte(void)
{
	uint8_t i;
	uint8_t Byte = 0x00;
	MyI2C_W_SDA(1);
	for(i = 0;i < 8;i ++)
	{
		MyI2C_W_SCL(1);
		if(MyI2C_R_SDA() == 1)
		{
			Byte |= (0x80 >> i);
		}
		MyI2C_W_SCL(0);
	}
	return Byte;
}

uint8_t MyI2C_ReceviceAck(void)
{
	uint8_t Ack;
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	Ack = MyI2C_R_SDA();
	MyI2C_W_SCL(0);
	
	return Ack;
}

void MyI2C_SendAck(uint8_t AckBit)
{
	MyI2C_W_SDA(AckBit);
	MyI2C_W_SCL(1);
	MyI2C_W_SCL(0);
}
