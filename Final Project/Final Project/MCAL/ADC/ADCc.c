/*
 * Keypad.c
 *
 * Created: 12/2/2022 10:25:10 AM
 *  Author: imahm
 */ 
#include "ADC.h"

void ADC_init()
{
	// set all used adc chnel as inout 
	DDRA&=~ADC_USED_CHANNELS ; 
	
	// select referrence voltage 
	#if (ADC_VOLTAGE_REF == ADC_AVCC_SOURCE_5V)
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
	#elif(ADC_VOLTAGE_REF == ADC_INTERNAL_SOURCE_2_56V)
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	#endif
	
	// select prescaler 
	#if (ADC_PRESCALER ==ADC_PRESCALER_128)
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#endif
	
	//select right or left adjustment 
	#if (ADC_READ_ADJEST==ADC_RIGHT_ADJUST_READ )
	CLEAR_BIT(ADMUX,ADLAR);
	#else
	CLEAR_BIT(ADMUX,ADLAR);
	#endif
	// enable ADC 
	SET_BIT(ADCSRA,ADEN); 
}

uint16_t ADC_read(EN_ADC_chanel_t channel )
{
	uint16_t ADC_value =0 ; 
	
	// select the channel 
	ADMUX &=0b11100000;
	ADMUX |= channel ;
	
	// start conversation 
	SET_BIT(ADCSRA,ADSC);
	
	// wait to conversation to finish 
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	
	// clear interrupt flag by setting logical one to it 
	SET_BIT(ADCSRA,ADIF);
	
	// read ADC value 
	#if (ADC_READ_ADJEST == ADC_RIGHT_ADJUST_READ) 
	ADC_value = ADCL+(ADCH<<8);
	#else
	ADC_value = (ADCL>>6)+(ADCH<<2); 
	#endif
	// return ADC value
	return ADC_value ;
}