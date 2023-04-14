/*
 * MCU_config.h
 *
 * Created: 11/12/2022 10:10:52 AM
 *  Author: Mohamed Taha Gabriel
 */ 


#ifndef MCU_CONFIG_H_
#define MCU_CONFIG_H_

#define F_CPU 1000000UL

#include <util/delay.h>

typedef unsigned char uint8_t;
#define NULL (void*)0

/************************************************************************/
/* ATMEGA32A RIGISTERS                                                                     */
/************************************************************************/

//PORT A 
#define PORTA *((volatile uint8_t * )(0X3B))
#define DDRA *((volatile uint8_t * )(0X3A))
#define PINA *((volatile uint8_t * )(0X39))

//PORT B
#define PORTB *((volatile uint8_t * )(0X38))
#define DDRB *((volatile uint8_t * )(0X37))
#define PINB *((volatile uint8_t * )(0X36))

//PORT C
#define PORTC *((volatile uint8_t * )(0X35))
#define DDRC *((volatile uint8_t * )(0X34))
#define PINC *((volatile uint8_t * )(0X33))

//PORT D
#define PORTD *((volatile uint8_t * )(0X32))
#define DDRD *((volatile uint8_t * )(0X31))
#define PIND *((volatile uint8_t * )(0X30))
/************************************************************************/
/* interrupt                                                           */
/**********************************************************************/

#define MCUCR *((volatile uint8_t *)0x55)  // 8-bit register
#define MCUCSR *((volatile uint8_t *)0x54)  // 8-bit register
#define GICR *((volatile uint8_t *)0x5B)  // 8-bit register
#define GIFR *((volatile uint8_t *)0x5A)  // 8-bit register
//External interrupt 0 sense bits
#define ISC00   0
#define ISC01   1
//External interrupt 1 sense bits
#define ISC10   2
#define ISC11   3
//External interrupt 2 sense bits
#define ISC2   6
//external interrupt enable bits 
#define INT2    5
#define INT0    6
#define INT1    7

#endif /* MCU_CONFIG_H_ */