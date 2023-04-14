/*
 * Keypad.c
 *
 * Created: 12/2/2022 10:25:10 AM
 *  Author: imahm
 */ 
#include "UART.h"
#include <avr/io.h>

static volatile void (*p2RXC_ISR_Func)(void)= NULL;

void UART_Init( unsigned int baud )
{
	baud =  F_CPU/16/baud-1;
	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data,no parity, 1stop bit */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}

void UART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
}

void UART_RXC_interruptEnable()
{
	//enable the RX complete interrupt
	UCSRB |= (1<<RXCIE);
	//enable the global interrupt
	sei();
}

unsigned char UART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}

void UART_sendString(sint8_t*str)
{
	for(uint8_t i=0;str[i]!='\0';i++)
	{
		UART_Transmit(str[i]);
	}
}

void UART_setCallBack( void (*p2f) (void) )
{
	if(p2f!=NULL)
	{
		p2RXC_ISR_Func= p2f;
	}
}

ISR(UART_RXC_VECT)
{
	if(p2RXC_ISR_Func !=NULL)
	{
		p2RXC_ISR_Func();
	}
}