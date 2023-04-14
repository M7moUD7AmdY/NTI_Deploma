/*
 * LCD_Driver.h
 *
 * Created: 12/3/2022 12:00:45 PM
 *  Author: imahm
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_
#ifndef _sbit_h_
#define _sbit_h_

struct bits {
	uint8_t b0:1;
	uint8_t b1:1;
	uint8_t b2:1;
	uint8_t b3:1;
	uint8_t b4:1;
	uint8_t b5:1;
	uint8_t b6:1;
	uint8_t b7:1;
} __attribute__((__packed__));


#define SBIT(port,pin) ((*(volatile struct bits*)&port).b##pin)

#endif

#include <avr/io.h>

void lcdinit();
void lcdcmd(unsigned char);
void lcdchar(unsigned char);
void lcdstr(char *);
void latch(void);
void lcdgoto(uint8_t , uint8_t );
void lcdclear();void LCD_intgerToString(uint32_t data);

#define Error   13

int get_num(unsigned char);
unsigned char get_func(unsigned char);
void DispError(int);
void disp_num(int);
#endif /* LCD_DRIVER_H_ */


