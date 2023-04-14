#include <avr/io.h>
#include <util/delay.h>
#include "LCD_Driver.h"

#define E (1<<PA3)
#define RW (1<<PA2)
#define RS (1<<PA1)

void lcdinit(){
	
	//initialize PORTs for LCD
	DDRA |= (1<<PA1) | (1<<PA2) | (1<<PA3) | (1<<PA4) | (1<<PA5) | (1<<PA6) | (1<<PA7);  //make output for E,RW,RS and 4 bit Data
	
	//Send Pulse to Latch the data
	
	latch();
	_delay_ms(2);  //delay for stable power
	// Command to set up the LCD
	lcdcmd(0x33);
	_delay_us(100);
	lcdcmd(0x32);
	_delay_us(100);
	lcdcmd(0x28);	// 2 lines 5x7 matrix dot
	_delay_us(100);
	//lcdcmd(0x0E);  // display ON, Cursor ON
	lcdcmd(0x0C);  // display ON, Cursor ON
	_delay_us(100);
	lcdcmd(0x01);	//clear LCD
	_delay_ms(20);	//wait
	lcdcmd(0x06);	//shift cursor to right
	_delay_ms(100);
	
}

void latch(void){
	PORTA |= E;		//send high
	_delay_us(500);		//wait
	PORTA &= ~E;		//send low
	_delay_us(500);		//wait
}

void lcdcmd(unsigned char cmd){
	
	PORTA = (PORTA & 0x0F) | (cmd & 0xF0);  // send high nibble
	PORTA &= ~RW;	//send 0 for write operation
	PORTA &= ~RS;	//send 0 to select command register
	latch();			//latch the data
	
	PORTA = (PORTA & 0x0F) | (cmd<<4);	//send low nibble
	latch();			//latch the data
	
}

void lcdchar(unsigned char data){
	
	PORTA = (PORTA & 0x0F) | (data & 0xF0);  // send high nibble
	PORTA &= ~RW;	//send 0 for write operation
	PORTA |= RS;	//send 1 to select data register
	latch();
	
	PORTA = (PORTA & 0x0F) | (data<<4);  // send high nibble
	latch();
	
}

void lcdstr(char *str){
	unsigned char k=0;
	while(str[k] != 0){
		lcdchar(str[k]);
		k++;
	}
}

void lcdgoto(unsigned char x, unsigned char y){
	unsigned char firstcharadr[] = {0x80, 0xC0, 0x94, 0xD4};
	lcdcmd(firstcharadr[y-1] + x-1);
	_delay_us(1000);
}

void lcdclear(){
	lcdcmd(0x01);
	_delay_ms(10);
}

int get_num(unsigned char ch)         //convert unsigned char into int
{
	int num = 0;
	switch(ch)
	{
		case '0':
		num = 0;
		break;
		case '1':
		num = 1;
		break;
		case '2':
		num = 2;
		break;
		case '3':
		num = 3;
		break;
		case '4':
		num = 4;
		break;
		case '5':
		num = 5;
		break;
		case '6':
		num = 6;
		break;
		case '7':
		num = 7;
		break;
		case '8':
		num = 8;
		break;
		case '9':
		num = 9;
		break;
		case 'C':
		lcdcmd(0x01);
		num = Error;
		break;  //this is used as a clear screen and then reset by setting error
		default:
		DispError(0);
		num = Error;
		break;       //it means wrong input
	}
	return num;
}

unsigned char get_func(unsigned char chf)            //detects the errors in inputted function
{
	if(chf=='C')                   //if clear screen then clear the LCD and reset
	{
		lcdcmd(0x01);             //clear display
		return 'e';
	}
	if( chf != '+' && chf != '-' && chf != 'x' && chf != '/' )  //if input is not from allowed funtions then show error
	{
		DispError(1);
		return 'e';
	}
	return chf;                        //function is correct so return the correct function
}


void DispError(int numb)           //displays differet error messages
{
	unsigned char msg1[] = {"Wrong Input"};
	unsigned char msg2[] = {"Wrong Function"};

	lcdcmd(0x01);              //clear display
	switch(numb)
	{
		case 0:
		lcdstr(msg1);
		break;
		case 1:
		lcdstr(msg2);
		break;
		default:
		lcdstr(msg1);
		break;
	}
}

void disp_num(int numb)            //displays number on LCD
{
	unsigned char UnitDigit  = 0;  //It will contain unit digit of numb
	unsigned char TenthDigit = 0;  //It will contain 10th position digit of numb

	if(numb<0)    {
		numb = -1*numb;          // Make number positive
		lcdchar('-');   // Display a negative sign on LCD
	}
	TenthDigit = (numb/10);                    // Find out Tenth Digit

	if( TenthDigit != 0)                    // If it is zero, then don't display
	lcdchar(TenthDigit+0x30);    // Make Char of TenthDigit and then display it on LCD
	UnitDigit = numb - TenthDigit*10;
	lcdchar(UnitDigit+0x30);    // Make Char of UnitDigit and then display it on LCD
}
//****************************************




void LCD_intgerToString(uint32_t data)
{
	uint8_t str[16];
	uint8_t i, rem, len = 0; uint32_t n;
	
	n = data;
	if(data == 0)
	len=1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	if(len >=15)
	return;
	for (i = 0; i < len; i++)
	{
		rem = data % 10;
		data = data / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	
	lcdstr(str);
}