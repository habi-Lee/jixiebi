#ifndef  __PWM_H
#define  __PWM_H

void  clock_init(void);
void  pwm_init(void);
void  pwm_set_M4(int pulse);
void  pwm_set_M5(int pulse);
void  pwm_set_M6(int pulse);
void  pwm_set_M7(int pulse);
void  pwm_set_M8(int pulse);
void  pwm_set_M9(int pulse);

void  USART1_IRQHandler(void);

#endif
