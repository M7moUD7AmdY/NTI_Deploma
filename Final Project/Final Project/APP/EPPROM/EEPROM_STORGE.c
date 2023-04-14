/*
 * EEPROM_STORGE.c
 *
 * Created: 1/3/2023 1:28:27 AM
 *  Author: Moamen
 */ 
#include "../../service_layer/std_types_MT.h"
#include "../../MCAL/I2C/i2c_MT.h"
#include "../../HAL/EEPROM/EEPROM_MT.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../HAL/KEY_PAD/keypad_Driver1.h"
#include "EEPROM_STORGE.h"


#define HIGH_TEMP_U8_LOCATION     0x11
#define LOW_TEMP_U8_LOCATION      0x22
#define HIGH_TEMP_U8_ADD           EEPROM_ADRESS
#define LOW_TEMP_U8_ADD            EEPROM_ADRESS

void EEPROM_voidStorgeTempInit(void)
{
	volatile u8 data =0;
	 
	 if (i2c_slave_available()==TW_SR_SLA_ACK)
	 {
		 data = i2c_read(1);
	 }
	 
}

void TEMP_voidStoreValue(u8 Copy_u8TempHigh,u8 Copy_u8TempLow)
{
	LCD_voidClear();
	LCD_voidSendString("ENTER HIGH TEMP = ");
	Copy_u8TempHigh=UART_u8ReceiveByte();
	/*KEYPAD_voidGetFrstParametr(&Copy_u8TempHigh);*/
	LCD_voidSendNumber(Copy_u8TempHigh);
	LCD_voidPositionWitting(LCD_U8_COL1,LCD_U8_ROW2);
	//LCD_voidClear();
	LCD_voidSendString("ENTER LOW TEMP = ");
	Copy_u8TempLow=UART_u8ReceiveByte();
	/*KEYPAD_voidGetFrstParametr(&Copy_u8TempLow);*/
	LCD_voidSendNumber(Copy_u8TempLow);
	EEPROM_write (HIGH_TEMP_U8_LOCATION,HIGH_TEMP_U8_ADD,Copy_u8TempHigh);
	EEPROM_write(LOW_TEMP_U8_LOCATION,LOW_TEMP_U8_ADD,Copy_u8TempLow);
}
void TEMP_voidReadValue(u8 Copy_u8TempHigh,u8 Copy_u8TempLow)
{
	LCD_voidClear();
	Copy_u8TempHigh = EEPROM_READ(HIGH_TEMP_U8_LOCATION,HIGH_TEMP_U8_ADD);
	LCD_voidSendString("T_HIGH =");
	
	LCD_voidSendNumber(Copy_u8TempHigh);
	Copy_u8TempLow =EEPROM_READ(LOW_TEMP_U8_LOCATION,LOW_TEMP_U8_ADD);
	LCD_voidPositionWitting(LCD_U8_COL1,LCD_U8_ROW2);
	LCD_voidSendString("T_LOW =");
	
	LCD_voidSendNumber(Copy_u8TempLow);
	
}