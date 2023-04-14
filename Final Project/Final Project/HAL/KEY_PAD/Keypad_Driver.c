/*
 * Keypad.c
 *
 * Created: 12/2/2022 10:25:10 AM
 *  Author: imahm
 */ 

#include "keypad_Driver1.h"//keypad keysstatic const uint8_t keypad_keys[NO_ROWS][NO_COLS]= KEYS_VALUES;//arrays of pins rows and cols#ifdef KEYPAD4X3static const uint8_t rows[NO_ROWS] = {ROW1,ROW2,ROW3,ROW4};static const uint8_t cols[NO_COLS] = {COL1,COL2,COL3};#elsestatic const uint8_t rows[NO_ROWS] = {4,5,6,7};static const uint8_t cols[NO_COLS] = {4,5,6,7};#endif//initialization functionvoid KPD_init(void){	//set all rows as output	DIO_init_pin('c',4,OUTPUT);	DIO_init_pin('c',5,OUTPUT);	DIO_init_pin('c',6,OUTPUT);	DIO_init_pin('c',7,OUTPUT);	DIO_write_port('c',0xf0);	//set all cols as input	for(int i =4;i<8;i++)	{		DIO_init_pin('d',i,INPUT);		//enable internal pull up		DIO_write_pin('d',i,HIGH);	}	//set all inputs as internal pull up and all outputs as HIGH	DIO_write_port('d',0xf0);}
uint8_t KPD_getKey(void){	uint8_t key_status = 1;	while (1)
	{
		for(uint8_t i=4;i<8;i++)	{		//enable the current row. low		DIO_write_pin('c',i,0);		for(uint8_t j=4 ; j<8;j++)		{			DIO_read_pin('d',j,&key_status);			if(key_status==0)			{				//debouncing				_delay_ms(20);				//wait until the key is not pressed				while(key_status==LOW)				{					DIO_read_pin('d',j,&key_status);				}				return keypad_keys[i][j];			}		}		//disable the current row. high		DIO_write_pin('c',i,1);	}	return keypad_keys[0][0];	}
}
//*********************************

