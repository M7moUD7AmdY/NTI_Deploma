/*
 * keypad_Driver1.h
 *
 * Created: 12/2/2022 10:25:34 AM
 *  Author: imahm
 */ 


#ifndef KEYPAD_DRIVER1_H_
#define KEYPAD_DRIVER1_H_

#include "../../MCAL/DIO/DIO.h"#define KEYPAD_PORT 'd'#define NO_ROWS 4#define NO_COLS 4//PINS OF ROWS#define ROW1 4#define ROW2 5#define ROW3 6#define ROW4 7//PINS OF COLS#define COL1 4#define COL2 5#define COL3 6#define COL4 7//#define KEYPAD4X3#ifdef KEYPAD4X3#define KEYS_VALUES {{'1','2','3'},\{'4','5','6'},\{'7','8','9'},\{'*','0','#'}}#else#define KEYS_VALUES {{'7','8','9','/'},\{'4','5','6','*'},\{'1','2','3','-'},\{'c','0','=','+'}}#endif//initialization functionvoid KPD_init(void);//function to get the pressed keyuint8_t KPD_getKey(void);
//uint8_t keypad_u8check_press(void);





#endif /* KEYPAD_DRIVER1_H_ */