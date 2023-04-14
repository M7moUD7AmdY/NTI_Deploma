/*
 * Final_project.h
 *
 * Created: 1/6/2023 10:38:16 AM
 *  Author: imahm
 */ 

#ifndef FINAL_PROJECT_H_
#define FINAL_PROJECT_H_

#include "../HAl/EEPROM/EEPROM_MT.h"
#include "../HAl/KEY_PAD/keypad_driver1.h"
#include "../HAl/Mottor/motor.h"
#include "../service_layer/MCU_config.h"
#include "../MCAL/TIMER/timer0.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/INTERRUPT/external_interrupts.h"
#include "../service_layer/MCU_config.h"
#include "../HAL/LCD/LCD_Driver.h"
#include "../MCAL/UART!/UART.h"
#include "../MCAL/I2C/i2c_MT.h"

void fucn_RXC_ISR();
  void temp_func();
  void set_func();
  void show_func();
  void app_init();
  void app_start();
   void wellcom_func();


#endif /* FINAL PROJECT_H_ */