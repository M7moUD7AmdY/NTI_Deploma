/*
 * motor.c
 *
 * Created: 24/11/2022 15:26:06
 *  Author: Ayaya
 */ 

#include "motor.h"

//Initialization of motor
void motor_init()
{
	DIO_init_pin(MOTOR_REG, CW_PIN, OUTPUT);
	DIO_init_pin(MOTOR_REG, ANTI_CW_PIN, OUTPUT);
}
//Rotate the motor
void motor_rotate(EN_rotation_t rot)
{
	switch (rot)
	{
		case closkwise:
			DIO_write_pin(MOTOR_REG, ANTI_CW_PIN, LOW);
			DIO_write_pin(MOTOR_REG, CW_PIN , HIGH);
			break;
		case anti_clockwise:
			DIO_write_pin(MOTOR_REG, CW_PIN, LOW);
			DIO_write_pin(MOTOR_REG, ANTI_CW_PIN , HIGH);
			break;
		default:
			break;
	}
}
//Stop the motor
void motor_stop()
{
	DIO_write_pin(MOTOR_REG, ANTI_CW_PIN, LOW);
	DIO_write_pin(MOTOR_REG, CW_PIN, LOW);
}