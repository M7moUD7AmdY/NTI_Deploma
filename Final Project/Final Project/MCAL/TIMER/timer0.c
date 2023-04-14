/*
 * Keypad.c
 *
 * Created: 12/2/2022 10:25:10 AM
 *  Author: imahm
 */ 
#include "timer0.h"
#include <avr/io.h>

static void (*ptr2fun_t0ovf)(void)=NULL; 
static void (*ptr2fun_t0cmp)(void)=NULL;

//timer 0 initiation
void timer0_init(ET_T0MODES_t mode , EN_setPrescaler_t prescaler)
{
	//clear timer 0 register 
	TCNT0 =0;
	//select the mode 
		//enable 
	switch(mode)
	{
		case NORMAL_MODE:
		
			// select the normal mode 
			CLEAR_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			//enable global interrupt 
			sei();
			//enable timer0 overflow
			SET_BIT(TIMSK,TOIE0);
			break;
		case CTC_MODE:
			//select the CTC mode 
			CLEAR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			//Enable Global interrupt 
			sei();
			//enable timer0 output compare interrupt 
			SET_BIT(TIMSK,OCIE0);
		
			break;
		case FAST_PWM_MODE:
			//select the fast pwm mode 
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			
			//SELECT inverting or non inverting 
			#ifdef NON_INVERTING
			CLEAR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			#else //inverting mode 
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			#endif
			
			//set pin b3 as output (OC0)
			SET_BIT(DDRB,PINB3);
		
		break;
		case PWM_PHASE_CORRECT_MODE:
			//select PWM with phase correct mode 
			SET_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			
			//SELECT inverting or non inverting
			#ifdef NON_INVERTING
			CLEAR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			#else //inverting mode
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			#endif
			
			//set pin b3 as output (OC0)
			SET_BIT(DDRB,PINB3);
		break;
		default:
		//error handling 
		break;
	}
	
	
	//set prescaler 
	switch(prescaler)
	{
		case NO_CLOCK:
			CLEAR_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
			break;
		case NO_PRESCALAR:
			SET_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
			break;
		case PRESCALER_8:
			CLEAR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
			break;
		case PRESCALER_64:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
			break;
		case PRESCALER_256:
			CLEAR_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
			break;
		case PRESCALER_1024:
			SET_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
			break;
			
		default:
		break;
	}

}
void timer0_start(uint8_t timer_iv , EN_setPrescaler_t prescaler)
{
	//SET TIMER INITIAL VALUE
	TCNT0 = timer_iv;
	
	//set prescaler
	switch(prescaler)
	{
		case NO_CLOCK:
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		case NO_PRESCALAR:
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		case PRESCALER_8:
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		
		default:
		break;
	}
	
}

//analog write takes a value from 0 to 255 
void Timer0_Set_OCR0(uint8_t value)
{
	OCR0 = value;
}

void timer0_stop()
{
	TCCR0 =0;
}



void timer0_dutyCycle(ET_T0MODES_t mode , uint8_t duty)
{
	switch(mode)
	{
		case FAST_PWM_MODE:
		//SELECT inverting or non inverting
		#ifdef NON_INVERTING
			Timer0_Set_OCR0((256*duty)/100-1);
		#else //inverting mode
		
		#endif
		break;
		case PWM_PHASE_CORRECT_MODE:
			Timer0_Set_OCR0((255*duty)/100);
		break;
		default:
		//error
		break;
	}
}

void timer0_setCallBack( void (* ptf_to_ISR_t0ovf)(void) , ET_T0MODES_t mode )
{
	switch(mode)
	{
		case NORMAL_MODE:
			if(ptf_to_ISR_t0ovf != NULL)
				ptr2fun_t0ovf = ptf_to_ISR_t0ovf;
			break;
		case CTC_MODE:
			if(ptr2fun_t0cmp != NULL)
				ptr2fun_t0cmp = ptf_to_ISR_t0ovf;
			break;
		default:
			break;
	}
	if(ptf_to_ISR_t0ovf != NULL)
		ptr2fun_t0ovf = ptf_to_ISR_t0ovf;
}

ISR(TIMER0_OVF_vect)
{
	if(ptr2fun_t0ovf != NULL)
		ptr2fun_t0ovf();  //func();
}

ISR(TIMER0_COMP_vect)
{
	if(ptr2fun_t0ovf != NULL)
		ptr2fun_t0ovf();  //func_comp()
}
