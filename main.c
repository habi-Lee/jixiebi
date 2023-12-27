#include "stm32f10x.h"                  // Device header
#include "uart.h"
#include "pwm.h"
static int z=1500;
static int x=1500;
static int c=1500;
static int v=1500;
static int b=1500;
static int n=1500;
void key_init(void)
{
	//PB3 PB4 PB5 PA15 PA4
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA , ENABLE);

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_15; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}

void delay(int n)
{
	
	int i = 0;
	while(n--)
	{
		for(i=0; i<5000; i++);
	}
}


int main()
{

	key_init();
	uart_init();
	clock_init();
	pwm_init();
	
	
}



void  USART1_IRQHandler(void)
{
	u16 RxData;
	int w;
	
	//判断接收中断是否产生
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		RxData = USART_ReceiveData(USART1); //550-2450
		if(RxData=='0')
		{
			z+=50;
			pwm_set_M4(z);
			
		}
		if(RxData=='1')
		{
			z-=50;
			pwm_set_M4(z);
		}
		if(RxData=='2')
		{
			x+=50;
			pwm_set_M5(x);
			
		}
		if(RxData=='3')
		{
			x-=50;
			pwm_set_M5(x);
		}
		if(RxData=='4')
		{
			c+=50;
			pwm_set_M6(c);
			
		}
		if(RxData=='5')
		{
			c-=50;
			pwm_set_M6(c);
		}
		if(RxData=='6')
		{
			v+=50;
			pwm_set_M7(v);
			
		}
		if(RxData=='7')
		{
			v-=50;
			pwm_set_M7(v);
		}
		if(RxData=='8')
		{
			b+=50;
			pwm_set_M8(b);
			
		}
		if(RxData=='9')
		{
			b-=50;
			pwm_set_M8(b);
		}
		if(RxData=='a')
		{
			n+=50;
			pwm_set_M9(n);
			
		}
		if(RxData=='b')
		{
			n-=50;
			pwm_set_M9(n);
		}
		if(RxData=='c')
		{
				for(w = 0;w<20;w++){
			z-=50;
			pwm_set_M6(z);
			delay(50);
			x-=50;
			pwm_set_M7(x);
			delay(50);
			c-=50;
			pwm_set_M9(c);
			}
			
		delay(3000);
		for(w = 0;w<20;w++)
		{
			c+=50;
			pwm_set_M9(c);
				
		}
		
		}
		if(RxData=='d')
		{
			
		for(w = 0;w<20;w++)
		{
			z+=50;
			x+=50;
			pwm_set_M6(z);
			pwm_set_M7(x);
			delay(50);
		}
		}
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);  //清除接收中断标志						
	}
}

