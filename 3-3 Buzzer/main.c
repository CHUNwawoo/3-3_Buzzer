#include "stm32f10x.h"   // Device header
#include "Delay.h"  // Device:Startup


/*蜂鳴器*/
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //打開 GPIOA 的時鐘
	GPIO_InitTypeDef GPIO_Instruction;
	GPIO_Instruction.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Instruction.GPIO_Pin = GPIO_Pin_12;
	GPIO_Instruction.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Instruction);
	
	
    while (1)
    {
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		Delay_ms(500);
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		Delay_ms(500);
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		Delay_ms(100);
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		Delay_ms(100);
    }
}
