/*
 * UART.h
 *
 * Created: 12/24/2022 12:49:47 PM
 *  Author: cm
 */ 


#ifndef UART_H_
#define UART_H_
#include "../../service_layer/MCU_config.h"
#include "../../service_layer/std_types_MT.h"
#include "../../service_layer/interrupts.h"

#define BAUD_RATE 9600


//UART INIT FUNCITON 
void UART_Init( unsigned int baud );


void UART_Transmit( unsigned char data );

// this function will enable the RX complete interrupt 
// also enable global interrupt 
void UART_RXC_interruptEnable();

unsigned char UART_Receive( void );

void UART_sendString(sint8_t*str);

//call back function to the RX complete 
void UART_setCallBack( void (*p2f) (void) );


#endif /* UART_H_ */