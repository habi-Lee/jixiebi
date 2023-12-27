#ifndef  __UART_H
#define  __UART_H

void  uart_init(void);
void  uart_send_byte( char data );
void  uart_send_str( char  *str	);

#endif
