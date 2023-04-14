/*
 * Final_project.c
 *
 * Created: 1/6/2023 10:37:55 AM
 *  Author: imahm
 */ 
#include "Final project.h"

volatile static uint8_t data=0;
uint8_t maxtemp=40,mintemp=20;
 void app_init()
 {
	 DIO_init_pin('a',0,0);
	 
	 //led init
	  DIO_init_pin('b',0,1);
	  DIO_init_pin('b',1,1);
	  DIO_init_pin('b',2,1);
	  DIO_init_pin('b',4,1);
	 
	 
	 // ADC and LCD init 
	  ADC_init();
	  lcdinit();

	 //timer and led pins init
	 timer0_init(FAST_PWM_MODE,NO_PRESCALAR);
	 
     // interrupt init 
	DIO_init_pin('d',3,0);
	EXT_INT_1_init(0);
	 
	 //keypad init 
	 KPD_init();
	 
	 //eeprom init  & i2C init
	 EEPROM_INIT();
	 i2c_init();
	 i2c_start();
	 
	 
	//UART init
	UART_Init(9600);
	//UART_setCallBack(fucn_RXC_ISR(void));
	UART_RXC_interruptEnable();
 
	 
 }
 
 
 void app_start()
 {
	 lcdclear();
	 lcdgoto(1 , 1);
	 lcdstr("Enter ur choice");
	 lcdgoto(1 , 2 );
	 lcdstr("1-temp 2-set 3-show");
	 _delay_ms(2000);
	 
show_func();	
	
		
	

 }
 // home INT
 ISR(INT1_vect)
 {
	 lcdclear();
	 app_start();
	 
 }
 
 //UART INT
 ISR(USART_RXC_vect)
 {
	 data = UDR;
 }
 
 
 void wellcom_func()
 {
	  // welcome screan
	  lcdgoto(4 , 1 );
	  lcdstr("Mahmoud Hamdi");
	  lcdgoto(2 , 2 );
	  lcdstr("NTI>>Final Project");
	  _delay_ms(1000);
	  lcdclear();
	 
	  app_start();
	  
	  
 }
 
 // ADC , LCD & UART
  void temp_func()
  {      uint16_t T=0;
	    
	  while (1)
	  {
	  lcdclear();
	  T=(ADC_read(0)-2)/2;
	  lcdstr("T= ");
	  LCD_intgerToString(T);
	  _delay_ms(500);
	  lcdstr("   C");
	   lcdgoto(2,2);
	   if (T<=mintemp)
	   {
		   lcdstr("LOW");
		  	   // timer0_start(ONE_MILLSECOND_MARK,PRESCALER_8);

//		   timer0_dutyCycle(FAST_PWM_MODE,0);
		   UART_sendString("LOW");
		   _delay_ms(1000);
		   DIO_write_pin('b',0,0);
		   DIO_write_pin('b',1,0);
		   DIO_write_pin('b',2,1);
		   DIO_write_pin('b',4,0);

	   }
	   else if (T>20&&T<30)
	   {
		   	    timer0_start(ONE_MILLSECOND_MARK,PRESCALER_8);

		     timer0_dutyCycle(FAST_PWM_MODE,100);
		   		   lcdstr("NORMAL");
				UART_sendString("NORMAL");

					  _delay_ms(1000);
					   DIO_write_pin('b',0,0);
					   DIO_write_pin('b',1,1);
					   DIO_write_pin('b',2,0);
					   DIO_write_pin('b',4,0);

	   }
	   else if (T>=30 && T<maxtemp)
	   {
		        	    timer0_start(ONE_MILLSECOND_MARK,PRESCALER_8);
      
					   timer0_dutyCycle(FAST_PWM_MODE,200);
		   		       lcdstr("HIGH");
						  		   UART_sendString("HIGH");

					  _delay_ms(1000);
					   DIO_write_pin('b',0,1);
					   DIO_write_pin('b',1,0);
					   DIO_write_pin('b',2,0);
					   DIO_write_pin('b',4,0);

	   }
	   else
	   {
		     timer0_start(ONE_MILLSECOND_MARK,PRESCALER_8);
		     timer0_dutyCycle(FAST_PWM_MODE, 200);
		    lcdstr("DANGER");
			UART_sendString("DANGER");

		    _delay_ms(1000);
		    DIO_write_pin('b',0,0);
		    DIO_write_pin('b',1,0);
		    DIO_write_pin('b',2,0);
			DIO_write_pin('b',4,1);
	   }
	   
	   
	   
	   
	  }
	  
  }
  //EEPROM +I2c
  void set_func()
  {
	  lcdclear();
	  lcdstr("ENTER mintemp");
	  _delay_ms(100);
	  while(mintemp!='=')
	  {
	
	  mintemp=KPD_getKey();
	  }
	  EEPROM_write(0,0xa0,mintemp);
	  lcdclear();
	  lcdstr("Enter maxtemp");
	  _delay_ms(100);
	  while (maxtemp!='=')
	  {
		  	  maxtemp=KPD_getKey();

	  }
	  EEPROM_write(1,0xa0,maxtemp);

	
	  
	  
  }
  //EEPROM +I2c
  void show_func()
  {
	  
	  lcdclear();
	  lcdgoto(2,1);
	  lcdstr(" MAX TEMP =");
	  LCD_intgerToString(40);
	  lcdgoto(2,2);
	  lcdstr(" MIN TEMP =");
	  LCD_intgerToString(20);
	  _delay_ms(100);
	  set_func();
	  
  }