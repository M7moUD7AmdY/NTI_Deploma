/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 03/01/2022                      */
/*                      Module : APPLICATION_MODE                */
/*                      Layer  : APP                             */
/*                      Version:  1.0                            */
/*****************************************************************/
#include <avr/interrupt.h>
#include "../../service_layer/std_types_MT.h"
#include "../../MCAL/DIO/DIO_int.h"
//#include "../../MCAL/EXTI/EXTI_int.h"
//#include "../../MCAL/GIE/GIE_int.h"
// #include "../../MCAL/TIMER/Timer_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../HAL/KEYPAD/KEYPAD_int.h"
#include "../../APP/TEMP_SENSOR/TEMP_SENSOR.h"
#include "APP_MODE.h"
#define F_CPU 80000000UL
#include <util/delay.h>


volatile u8 flag=0;

void INTRO_voidDisplayScreen(void)
{
	
	DIO_voidInit();
	EXTI_voidInit_INT1();
	EXTI_voidEnable_INT1();
	LCD_voidInit();
	ADC_voidInit();
	KEYPAD_voidInt();
	ADC_voidEnable();
	UART_voidInit();
	TIMER0_voidInit();
	//EEPROM_voidStorgeTempInit();
	GIE_voidEnable();
	DIO_voidSetPinValue(DIO_U8_PIN27,DIO_U8_HIGH);    // for EXTI0 PULL UP RESISTOR

	
	//UART MASSAGE
	UART_voidSendString("NTI AVR PROJECT");
	UART_voidWriteNewLine();
	UART_voidSendString("WELCOME TO TEMP CONTROL SYSTEM");
	
	//LCD
	LCD_voidPositionWitting(LCD_U8_COL8,LCD_U8_ROW1);
	LCD_voidSendString("NTI");
	LCD_voidPositionWitting(LCD_U8_COL5,LCD_U8_ROW2);
	LCD_voidSendString("AVR PROJECT");
	
	LCD_voidClear();
	LCD_voidPositionWitting(LCD_U8_COL5,LCD_U8_ROW1);
	LCD_voidSendString("WELCOME TO");
	LCD_voidPositionWitting(LCD_U8_COL1,LCD_U8_ROW2);
	LCD_voidSendString("TEMP CONTROL SYSTEM");
	//_delay_ms(500);
	LCD_voidClear();
	LCD_voidSendString("1-TEMP CONTROL SYSTEM");
	LCD_voidPositionWitting(LCD_U8_COL1,LCD_U8_ROW2);
	LCD_voidSendString("2-SET TEMP");
	LCD_voidPositionWitting(LCD_U8_COL11,LCD_U8_ROW2);
	LCD_voidSendString("3-SHOW TEMP");
	// _delay_ms(500);
	LCD_voidClear();
	
	
}


void APP_voidModes(void)
{
	volatile u8 H_TEMP=0;
	volatile u8 L_TEMP=0;
	volatile u8 Local_u8Check=0;
	volatile u8 Local_uPressedKey = KEYPAD_U8_NO_Pressed;
	
	LCD_voidClear();
	LCD_voidSendString("SELECT MODE");
	UART_voidWriteNewLine();
		Local_u8Check=UART_u8ReceiveByte();

		
// 		Local_u8Check=KEYPAD_u8GetPressedButton();
// 		KEYPAD_voidWaitingKEY(Local_u8Check);
		
		
		/*LCD_voidPositionWitting(LCD_U8_COL5,LCD_U8_ROW2);
		LCD_voidSendString("KEY");
		Local_u8Check=KEYPAD_u8GetPressedButton();
		KEYPAD_voidWaitingKEY(Local_u8Check);
		LCD_voidSendData(Local_u8Check);
		_delay_ms(500);
		LCD_voidClear();*/
		
		switch(Local_u8Check)
		{
			case '1':
			{ 
				
				LCD_voidSendString("TEMP CONTROL SYSTEM");
				while(1)
				{
					TEMP_SENSOR_voidRead();
				}
				
				break;
			}
			case '2' :
			{
				
				TEMP_voidStoreValue(H_TEMP,L_TEMP);
				break;
			}
			case '3':
			{
				
				LCD_voidClear();
				TEMP_voidReadValue(H_TEMP,L_TEMP);
				
				break;
			}
			default:
			break;
		}
		
}


ISR(INT1_vect)
{
	APP_voidModes();
}








