/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 16/11/2022                      */
/*                      Module : DIO_prog                        */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/
#include "../../service_layer/std_types_MT.h"
#include "DIO_int.h"
#include "../../SERVICE/BIT_math.h"
#include "DIO_config.h"
#include "DIO_private.h"

void DIO_voidInit(void)
{
	//here we will prepare Direction of try state buffer input or output in DDR for each port 
	DDRA = DIO_U8_PORTA_DIR;
	DDRB = DIO_U8_PORTB_DIR;
	DDRC = DIO_U8_PORTC_DIR;
	DDRD = DIO_U8_PORTD_DIR;
}
void DIO_voidSetPinValue(u8 Copy_u8Pin,u8 Copy_u8Value)
{
	//we set value of any pin for high or low 
	if(Copy_u8Pin<DIO_U8_END_PORTA)
	{
	
	   switch(Copy_u8Value)
	   {
	   	case DIO_U8_HIGH: SET_BIT(PORTA,Copy_u8Pin);  break;
	   	case DIO_U8_LOW: CLEAR_BIT(PORTA,Copy_u8Pin);  break;
	   }
	}
	else if(Copy_u8Pin<DIO_U8_END_PORTB)
	{
	   Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTA;
	   switch(Copy_u8Value)
	   {
	   	case DIO_U8_HIGH: SET_BIT(PORTB,Copy_u8Pin);  break;
	   	case DIO_U8_LOW: CLEAR_BIT(PORTB,Copy_u8Pin);  break;
	   }
	} 
	else if(Copy_u8Pin<DIO_U8_END_PORTC)
	{
	   Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTB;
	   switch(Copy_u8Value)
	   {
	   	case DIO_U8_HIGH: SET_BIT(PORTC,Copy_u8Pin);  break;
	   	case DIO_U8_LOW: CLEAR_BIT(PORTC,Copy_u8Pin);  break;
	   }
	} 
	else if(Copy_u8Pin<DIO_U8_END_PORTD)
	{
	   Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTC;
	   switch(Copy_u8Value)
	   {
	   	case DIO_U8_HIGH: SET_BIT(PORTD,Copy_u8Pin);  break;
	   	case DIO_U8_LOW: CLEAR_BIT(PORTD,Copy_u8Pin);  break;
	   }
	} 
}
void DIO_voidTogglePinValue(u8 Copy_u8Pin)
{
	if(Copy_u8Pin<DIO_U8_END_PORTA)
	{
	    TOGGLE_BIT(PORTA,Copy_u8Pin);
	}
	else if(Copy_u8Pin<DIO_U8_END_PORTB)
	{
	   Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTA;
	    TOGGLE_BIT(PORTB,Copy_u8Pin);
	} 
	else if(Copy_u8Pin<DIO_U8_END_PORTC)
	{
	   Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTB;
	    TOGGLE_BIT(PORTC,Copy_u8Pin);
	} 
	else if(Copy_u8Pin<DIO_U8_END_PORTD)
	{
	   Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTC;
	    TOGGLE_BIT(PORTD,Copy_u8Pin);
	}
}
u8   DIO_u8GetPinValue(u8 Copy_u8Pin)
{
	u8 Local_u8Variable=0;
	if(Copy_u8Pin<DIO_U8_END_PORTA)
	{
	   Local_u8Variable = GET_BIT(PINA,Copy_u8Pin);
	}
	else if(Copy_u8Pin<DIO_U8_END_PORTB)
	{
	   Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTA;
	   Local_u8Variable = GET_BIT(PINB,Copy_u8Pin);
	} 
	else if(Copy_u8Pin<DIO_U8_END_PORTC)
	{
	   Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTB;
	   Local_u8Variable = GET_BIT(PINC,Copy_u8Pin);
	} 
	else if(Copy_u8Pin<DIO_U8_END_PORTD)
	{
	   Copy_u8Pin = Copy_u8Pin - DIO_U8_END_PORTC;
	   Local_u8Variable = GET_BIT(PIND,Copy_u8Pin);
	}
	return Local_u8Variable;
}
