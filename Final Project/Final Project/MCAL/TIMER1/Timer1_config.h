/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 16/11/2022                      */
/*                      Module : TIMER_config                    */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/

#ifndef _TIMER1_CONFIG_H
#define _TIMER1_CONFIG_H

/*TIMER ON MODE SELECTION
TIMER1_NORMAL
TIMER1_PWM_PHASE_CORRECT_8_BIT
TIMER1_PWM_PHASE_CORRECT_9_BIT
TIMER1_PWM_PHASE_CORRECT_10_BIT
TIMER1_CTC
TIMER1_FAST_PWM_8_BIT
TIMER1_FAST_PWM_9_BIT
TIMER1_FAST_PWM_10_BIT
TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR1
TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR1A
TIMER1_PWM_PHASE_CORRECT_ICR1
TIMER1_PWM_PHASE_CORRECT_OCR1A
TIMER1_CTC_ICR1
TIMER1_FAST_PWM_ICR1
TIMER1_FAST_PWM_OCR1A
*/

#define TIMER1_MODE     TIMER1_FAST_PWM_ICR1
#define TIMER1B_MODE    TIMER1_NORMAL
#define TIMER1ICU_MODE  TIMER1_NORMAL
/*Range
#define TIMER1_DIV_BY_1			
#define TIMER1_DIV_BY_8			
#define TIMER1_DIV_BY_64		
#define TIMER1_DIV_BY_256		
#define TIMER1_DIV_BY_1024		
*/
#define TIMER1_PRESCALER     TIMER1_DIV_BY_8
#define TIMER1B_PRESCALER    TIMER1_DIV_BY_8
#define TIMER1ICU_PRESCALER  TIMER1_DIV_BY_64

/*Range
#define TIMER1_NO_ACTION	
#define TIMER1_TOGGLE		
#define TIMER1_SET			
#define TIMER1_CLEAR		
*/

/*
Fast PWM
#define TIMER1_INVERTED
#define TIMER1_NON_INVERTED
*/

#define TIMER1_COM_EVENT      TIMER1_NON_INVERTED
#define TIMER1B_COM_EVENT     TIMER1_NON_INVERTED


/*
** options ICR NOISE ** 
ICU_NOISE_CANSELLER_ENABLE
ICU_NOISE_CANSELLER_DISABLE
*/
#define TIMER1ICU_NOISE_CANSELLER_MODE    ICU_NOISE_CANSELLER_ENABLE
/*
** ICU EDGE SELECT
ICU_RAISING_EDGE
ICU_FALLING_EDGE
*/
#define TIMER1ICU_EDGE_SELECT     ICU_RAISING_EDGE


#endif
