/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 16/11/2022                      */
/*                      Module : DIO_config                      */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

//set direction options
#define DIO_U8_INPUT      0
#define DIO_U8_OUTPUT     1

// DIO_PIN_CONFIGRATION
/** if you dont used any pin you must set it as input to avoid short circit **/
#define DIO_U8_PIN0_DIR    DIO_U8_INPUT           // ADC  channel
#define DIO_U8_PIN1_DIR    DIO_U8_OUTPUT          // BUZZER 
#define DIO_U8_PIN2_DIR    DIO_U8_INPUT
#define DIO_U8_PIN3_DIR    DIO_U8_INPUT
#define DIO_U8_PIN4_DIR    DIO_U8_OUTPUT          // for LCD DATA PINS
#define DIO_U8_PIN5_DIR    DIO_U8_OUTPUT		  // for LCD DATA PINS
#define DIO_U8_PIN6_DIR    DIO_U8_OUTPUT		  // for LCD DATA PINS
#define DIO_U8_PIN7_DIR    DIO_U8_OUTPUT		  // for LCD DATA PINS
						  
#define DIO_U8_PIN8_DIR    DIO_U8_OUTPUT         // for LCD	CONTROl PINS
#define DIO_U8_PIN9_DIR    DIO_U8_OUTPUT         // for LCD CONTROl PINS
#define DIO_U8_PIN10_DIR   DIO_U8_OUTPUT		 // for LCD	CONTROl PINS
#define DIO_U8_PIN11_DIR   DIO_U8_OUTPUT         // OC0		 
#define DIO_U8_PIN12_DIR   DIO_U8_OUTPUT		 // LEDS	 
#define DIO_U8_PIN13_DIR   DIO_U8_OUTPUT		 // LEDS
#define DIO_U8_PIN14_DIR   DIO_U8_OUTPUT		 // LEDS
#define DIO_U8_PIN15_DIR   DIO_U8_OUTPUT		 // LEDS
						  
#define DIO_U8_PIN16_DIR   DIO_U8_OUTPUT          //  TWI
#define DIO_U8_PIN17_DIR   DIO_U8_OUTPUT	      //  TWI
#define DIO_U8_PIN18_DIR   DIO_U8_INPUT	          //  KEYPAD PINS
#define DIO_U8_PIN19_DIR   DIO_U8_INPUT   	      //  KEYPAD PINS
#define DIO_U8_PIN20_DIR   DIO_U8_OUTPUT		      //  KEYPAD PINS COLUMNS
#define DIO_U8_PIN21_DIR   DIO_U8_OUTPUT		      //  KEYPAD PINS COLUMNS
#define DIO_U8_PIN22_DIR   DIO_U8_OUTPUT		      //  KEYPAD PINS COLUMNS
#define DIO_U8_PIN23_DIR   DIO_U8_OUTPUT		      //  KEYPAD PINS COLUMNS
						   
#define DIO_U8_PIN24_DIR   DIO_U8_INPUT      //RXD
#define DIO_U8_PIN25_DIR   DIO_U8_OUTPUT     //TXD
#define DIO_U8_PIN26_DIR   DIO_U8_INPUT     
#define DIO_U8_PIN27_DIR   DIO_U8_INPUT         //INT1
#define DIO_U8_PIN28_DIR   DIO_U8_INPUT        //  OCR1B 
#define DIO_U8_PIN29_DIR   DIO_U8_INPUT        //  OCR1A 
#define DIO_U8_PIN30_DIR   DIO_U8_INPUT      //  KEYPAD PINS
#define DIO_U8_PIN31_DIR   DIO_U8_INPUT	     //  KEYPAD PINS


#endif  /* DIO_CONFIG_H_ */
