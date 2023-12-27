#include "stm32f10x.h"   // Device header

void clock_init()
{
    RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON); 
	while(RCC_WaitForHSEStartUp()  !=SUCCESS );//�̨���y?e??
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
	RCC_PLLCmd(ENABLE); //��1?��
	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
	//????��??��o����?����?������?a?�̨�3����?��  72MHZ
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); 
	RCC_HCLKConfig(RCC_SYSCLK_Div1); //2?��??��
	RCC_PCLK1Config(RCC_HCLK_Div2); 
	RCC_PCLK2Config(RCC_HCLK_Div1); 
}

void  pwm_init()
{
	
    GPIO_InitTypeDef GPIO_InitStructure;     //?����??��11��?
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;    //?����??��11��?
	TIM_OCInitTypeDef TIM_OCInitStructure;       //?����??��11��?
//???��	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);      //����?����1?��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4, ENABLE);      //����?����1?��
				               //RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);      //����?����1?��	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 |  GPIO_Pin_0 | GPIO_Pin_7 | GPIO_Pin_6 | GPIO_Pin_9 | GPIO_Pin_8;   //????��y??M4,M5,M6,M7,M8,M9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;     //��?3??��?��         M4
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;       
    GPIO_Init(GPIOB, &GPIO_InitStructure);      // ��y??3?��??��
	GPIO_Init(GPIOA, &GPIO_InitStructure);      // ��y??3?��??��
	
	TIM_TimeBaseStructure.TIM_Period = 20000; 
	TIM_TimeBaseStructure.TIM_Prescaler = 72; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM3, & TIM_TimeBaseStructure); 
	TIM_TimeBaseInit(TIM4, & TIM_TimeBaseStructure); 
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = ENABLE;
	TIM_OCInitStructure.TIM_Pulse = 1500; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC4Init(TIM3, & TIM_OCInitStructure); 
	TIM_OC3Init(TIM3, & TIM_OCInitStructure);    
	TIM_OC2Init(TIM3, & TIM_OCInitStructure);	
	TIM_OC1Init(TIM3, & TIM_OCInitStructure);
	TIM_OC4Init(TIM4, & TIM_OCInitStructure);
	TIM_OC3Init(TIM4, & TIM_OCInitStructure);
	TIM_Cmd(TIM3, ENABLE);
	TIM_Cmd(TIM4, ENABLE);
	
	
}
void pwm_set_M4(int pulse)
{
	if(pulse>=550&&pulse<=2450)
	{
	   TIM_SetCompare4(TIM3, pulse);  //M4
     
	}

}

void pwm_set_M5(int pulse)
{
	if(pulse>=550&&pulse<=2450)
	{
	  
       TIM_SetCompare3(TIM3, pulse);//M5
		
	}
}

void pwm_set_M6(int pulse)
{
	if(pulse>=550&&pulse<=2450)
	{
	  
		TIM_SetCompare2(TIM3, pulse);//M6
		
	}
}

void pwm_set_M7(int pulse)
{
	if(pulse>=550&&pulse<=2450)
	{
	  
		TIM_SetCompare1(TIM3, pulse);//M7
		
	}
}

void pwm_set_M8(int pulse)
{
	if(pulse>=550&&pulse<=2450)
	{
	   
		TIM_SetCompare4(TIM4, pulse);//M8
		
	}
}

void pwm_set_M9(int pulse)
{
	if(pulse>=550&&pulse<=2450)
	{
	  
		TIM_SetCompare3(TIM4, pulse);//M9
	}
}




