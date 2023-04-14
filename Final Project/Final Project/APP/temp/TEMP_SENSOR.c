/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 01/12/2022                      */
/*                      Module : TEMP_SENSOR                     */
/*                      Layer  : APP                             */
/*                      Version:  1.0                            */
/*****************************************************************/
#include "../../service_layer/std_types_MT.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../MCAL/TIMER0/Timer_int.h"
#include "../../HAL/ALARM/BUZZER.h"
#define F_CPU 16000000
#include <util/delay.h>






void TEMP_SENSOR_voidRead(void)
{

	f32 TempC =100*((f32)(ADC_u16Convert(ADC_U8_Channel0))*5.0)/1024.0;
	LED_voidOFF(LED_L_PIN);
	LED_voidOFF(LED_M_PIN);
	LED_voidOFF(LED_H_PIN);
	LED_voidOFF(LED_A_PIN);
	BUZZ_voidDisable();
	
	if(TempC>28 && TempC<35)
	{
		LCD_voidClear();
		LCD_voidSendString("TEMP =");
		LCD_voidSendNumber(TempC);
		LCD_voidSendString(" *C");
		LCD_voidPositionWitting(LCD_U8_COL1,LCD_U8_ROW2);
		LCD_voidSendString("HIGH TEMP");
		UART_voidWriteNewLine();
		UART_voidSendString("HIGH TEMP");
		TIMER0_voidSetCompareVal(255);          //DC ON with full speed
		LCD_voidPositionWitting(LCD_U8_COL12,LCD_U8_ROW2);
		LCD_voidSendString("It's Hot");
		LED_voidON(LED_H_PIN);
		_delay_ms(500);
	}
	else if(TempC>21 && TempC<28)
	{
		LCD_voidClear();
		LCD_voidSendString("TEMP = ");
		LCD_voidSendNumber(TempC);
		LCD_voidSendString(" *C");
		LCD_voidPositionWitting(LCD_U8_COL1,LCD_U8_ROW2);
		TIMER0_voidSetCompareVal(128);          //DC ON with 50% speed
		LCD_voidSendString("NORMAL TEMP");
		UART_voidWriteNewLine();
		UART_voidSendString("NORMAL TEMP");
		LED_voidON(LED_M_PIN);
		_delay_ms(500);
	}
	else if (TempC<21)
	{
		LCD_voidClear();
		LCD_voidSendString("TEMP =");
		LCD_voidSendNumber(TempC);
		LCD_voidSendString(" C");
		TIMER0_voidSetCompareVal(0);          //DC ON with 0% speed
		LCD_voidPositionWitting(LCD_U8_COL3,LCD_U8_ROW2);
		LCD_voidSendString("LOW TEMP");
		UART_voidWriteNewLine();
		UART_voidSendString("LOW TEMP");
		LED_voidON(LED_L_PIN);
		_delay_ms(500);
	}
	else if(TempC>35)
	{
		LCD_voidClear();
		LCD_voidSendString("TEMP =");
		LCD_voidSendNumber(TempC);
		LCD_voidSendString(" C");
		TIMER0_voidSetCompareVal(255);          //DC ON with 100% speed
		LCD_voidPositionWitting(LCD_U8_COL3,LCD_U8_ROW2);
		LCD_voidSendString("DANGERUS");
		UART_voidWriteNewLine();
		UART_voidSendString("DANGERUS");
		BUZZ_voidEnable();
		LED_voidToggle(LED_A_PIN);
		_delay_ms(500);
	}
	
}

