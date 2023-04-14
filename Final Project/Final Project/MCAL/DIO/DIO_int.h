/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 16/11/2022                      */
/*                      Module : DIO_int                         */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/

#ifndef DIO_INT_H_
#define DIO_INT_H_
//options for DIO_PinValue
#define DIO_U8_HIGH        1
#define DIO_U8_LOW         0

/*that all pin Macros for Atmega32 4 PORT   and we will used PINS directly to save size on function parameter and argument*/
#define DIO_U8_PIN0        0
#define DIO_U8_PIN1        1
#define DIO_U8_PIN2        2
#define DIO_U8_PIN3        3
#define DIO_U8_PIN4        4
#define DIO_U8_PIN5        5
#define DIO_U8_PIN6        6
#define DIO_U8_PIN7        7
#define DIO_U8_PIN8        8
#define DIO_U8_PIN9        9
#define DIO_U8_PIN10       10
#define DIO_U8_PIN11       11
#define DIO_U8_PIN12       12
#define DIO_U8_PIN13       13
#define DIO_U8_PIN14       14
#define DIO_U8_PIN15       15
#define DIO_U8_PIN16       16
#define DIO_U8_PIN17       17
#define DIO_U8_PIN18       18
#define DIO_U8_PIN19       19
#define DIO_U8_PIN20       20
#define DIO_U8_PIN21       21
#define DIO_U8_PIN22       22
#define DIO_U8_PIN23       23
#define DIO_U8_PIN24       24
#define DIO_U8_PIN25       25
#define DIO_U8_PIN26       26
#define DIO_U8_PIN27       27
#define DIO_U8_PIN28       28
#define DIO_U8_PIN29       29
#define DIO_U8_PIN30       30
#define DIO_U8_PIN31       31


void DIO_voidInit(void);
void DIO_voidSetPinValue(u8 Copy_u8Pin,u8 Copy_u8Value);
void DIO_voidTogglePinValue(u8 Copy_u8Pin);
u8 DIO_u8GetPinValue(u8 Copy_u8Pin);


// DIO_PIN_CONFIGRATION
#define CONC_BIT(A7,A6,A5,A4,A3,A2,A1,A0)    CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)
#define CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)   0b##A7##A6##A5##A4##A3##A2##A1##A0



#endif  /* DIO_INT_H_ */
