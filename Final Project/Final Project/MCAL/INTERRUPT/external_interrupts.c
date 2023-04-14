


#include "external_interrupts.h"


// external interrupt 0 initialization
void EXT_INT_0_init(EN_interrupt_sense_t sense)
{
	//1. Enable the global interrupt
	sei();
	//2. choose the interrupt sense on ext interrupt 0
	switch(sense)
	{
		case low_level_sense:
			MCUCR &=~ ((1<<ISC00)|(1<<ISC01)); // low level interrupt
			break;
		case anyLogicChange_sense:
			MCUCR |= (1<<ISC00); //any logical change 
			break;
		case falling_edge_sense:
			MCUCR |= (1<<ISC01);  // Falling edge trigger
			break;
		case rising_edge_sense:
			MCUCR |= (1<<ISC01) | (1<<ISC00); // rising edge 
			break;
		default:
		break;
	}
	//3. Enable the external interrupt 0
	GICR |= (1<<INT0);
}

// external interrupt 1 initialization
void EXT_INT_1_init(EN_interrupt_sense_t sense)
{
	//1. Enable the global interrupt
	sei();
	//2. Enable the external interrupt 1
	GICR |= (1<<INT1);
	//3. choose the interrupt sense on ext interrupt 0
	switch(sense)
	{
		case low_level_sense:
		MCUCR &=~ ((1<<ISC00)|(1<<ISC01)); // low level interrupt
		break;
		case anyLogicChange_sense:
		MCUCR |= (1<<ISC00); //any logical change
		break;
		case falling_edge_sense:
		MCUCR |= (1<<ISC01);  // Falling edge trigger
		break;
		case rising_edge_sense:
		MCUCR |= (1<<ISC01) | (1<<ISC00); // rising edge
		break;
		default:
		break;
	}	
	
}
// external interrupt 2 initialization
void EXT_INT_2_init(EN_interrupt_sense_t sense)
{
	//1. Enable the global interrupt
	sei();
	//2. Enable the external interrupt 2
	GICR |= (1<<INT2);
	//3. choose the interrupt sense on ext interrupt 0
	switch(sense)
	{
		case low_level_sense:
		MCUCSR &=~ (1<<ISC2); // low level interrupt
		break;
		case rising_edge_sense:
		MCUCSR |= (1<<ISC2); //High level interrupt
		break;
		default:
		break;
	}
	
}