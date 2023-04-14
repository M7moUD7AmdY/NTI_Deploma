/*
 * motor.h
 *
 * Created: 24/11/2022 15:26:25
 *  Author: Ayaya
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../MCAL/DIO/DIO.h"
#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0

#define MOTOR_REG 'd'

#define CW_PIN 6
#define ANTI_CW_PIN 7

typedef enum{
	closkwise,
	anti_clockwise
	}EN_rotation_t;

//Initialization of motor
void motor_init();
//Rotate the motor
void motor_rotate(EN_rotation_t rot);
//Stop the motor
void motor_stop();


#endif /* MOTOR_H_ */