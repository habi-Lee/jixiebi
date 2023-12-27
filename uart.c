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
	
		
	USART_InitStructure.USART_BaudRate = 9600;  //������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;  //����λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;   //ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;   //����żУ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //��Ӳ��������
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;  //�ܷ��ͺͽ���
	USART_Init(USART1, &USART_InitStructure);  //����1 ��ʼ��
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);  //ʹ�ܴ��ڽ����ж�
	
	
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART1, ENABLE);  //ʹ�ܴ���1����
}




//void  uart_send_byte( char data )
//{
//	USART_SendData(USART1, data);
//	//ȷ��������ɣ�����δ��ɻ������ѭ��
//	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
//}

//void  uart_send_str( char  *str	)
//{
//	//'\0'���ַ���������־���ж��ַ����Ƿ����
//	while(*str  != '\0')
//	{
//		uart_send_byte(*str); //����һ���ַ�
//		str++;  //����ƶ�һ���ַ�
//	}
//}

