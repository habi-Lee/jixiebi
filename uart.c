#include "stm32f10x.h"                  // Device header

void  uart_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	USART_InitTypeDef USART_InitStructure; 
	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		
	USART_InitStructure.USART_BaudRate = 9600;  //波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;  //数据位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;   //停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;   //无奇偶校验
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //无硬件流控制
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;  //能发送和接收
	USART_Init(USART1, &USART_InitStructure);  //串口1 初始化
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);  //使能串口接收中断
	
	
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART1, ENABLE);  //使能串口1外设
}




//void  uart_send_byte( char data )
//{
//	USART_SendData(USART1, data);
//	//确保发送完成，发送未完成会进入死循环
//	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
//}

//void  uart_send_str( char  *str	)
//{
//	//'\0'是字符串结束标志，判断字符串是否结束
//	while(*str  != '\0')
//	{
//		uart_send_byte(*str); //发送一个字符
//		str++;  //向后移动一个字符
//	}
//}

