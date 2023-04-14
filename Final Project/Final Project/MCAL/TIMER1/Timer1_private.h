/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 16/11/2022                      */
/*                      Module : TIMER_private                   */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/


#ifndef _TIMER1_PRIV
#define _TIMER1_PRIV

#define TIMSK      (*(volatile u8 * )(0x59))  // Timer/Counter Interrupt Mask Register
#define OCR1A      (*(volatile u16* )(0x4A))  // Output Compare Register A
#define OCR1B      (*(volatile u16* )(0x48))  // Output Compare Register B
#define TCCR1A     (*(volatile u8 * )(0x4F))  // Timer/Counter1 Control Register A
#define TCCR1B     (*(volatile u8 * )(0x4E))  // Timer/Counter1 Control Register B
#define TCNT1      (*(volatile u16* )(0x4C))  // Timer/Counter1
#define TIFR       (*(volatile u8 * )(0x58))  // Timer/Counter Interrupt Flag Register
#define ICR1       (*(volatile u16* )(0x46))  // Input Capture Register
 

/* TIMER1 MODES */
#define TIMER1_NORMAL 		                      1
#define TIMER1_PWM_PHASE_CORRECT_8_BIT 	          2
#define TIMER1_PWM_PHASE_CORRECT_9_BIT 	          3
#define TIMER1_PWM_PHASE_CORRECT_10_BIT           4
#define TIMER1_CTC       	                      5
#define TIMER1_FAST_PWM_8_BIT 	                  6
#define TIMER1_FAST_PWM_9_BIT 	                  7
#define TIMER1_FAST_PWM_10_BIT                    8
#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR1   9
#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR1A  10
#define TIMER1_PWM_PHASE_CORRECT_ICR1             11
#define TIMER1_PWM_PHASE_CORRECT_OCR1A            12
#define TIMER1_CTC_ICR1                           13
#define TIMER1_FAST_PWM_ICR1                      14
#define TIMER1_FAST_PWM_OCR1A                     15


#define ICU_NOISE_CANSELLER_ENABLE               0
#define ICU_NOISE_CANSELLER_DISABLE              1

#define  ICU_RAISING_EDGE                        0
#define  ICU_FALLING_EDGE                        1



#define TIMER1_DIV_BY_1			1
#define TIMER1_DIV_BY_8			5
#define TIMER1_DIV_BY_64		8
#define TIMER1_DIV_BY_256		10
#define TIMER1_DIV_BY_1024		15


#define TIMER1_NO_ACTION	   100
#define TIMER1_TOGGLE		   12
#define TIMER1_SET			   20
#define TIMER1_CLEAR		   25

#define TIMER1_INVERTED        1
#define TIMER1_NON_INVERTED    2

/* TCCR1A Register pins   */
#define TCCR1A_COM1A1          7 // Compare Output Mode for Compare unit A
#define TCCR1A_COM1A0          6 // Compare Output Mode for Compare unit A
#define TCCR1A_COM1B1          5 // Compare Output Mode for Compare unit B
#define TCCR1A_COM1B0          4 // Compare Output Mode for Compare unit B
#define TCCR1A_FOC1A           3 // Force Output Compare for Compare unit A
#define TCCR1A_FOC1B           2 // Force Output Compare for Compare unit B
#define TCCR1A_WGM11           1 // Waveform Generation Mode
#define TCCR1A_WGM10           0 // Waveform Generation Mode

/* TCCR1B Register pins   */
#define TCCR1B_ICNC1          7 // Input Capture Noise Canceler
#define TCCR1B_ICES1          6 // Input Capture Edge Select
#define TCCR1B_WGM13          4 // Waveform Generation Mode
#define TCCR1B_WGM12          3 // Waveform Generation Mode
#define TCCR1B_CS12           2 // Clock Select
#define TCCR1B_CS11           1 // Clock Select
#define TCCR1B_CS10           0 // Clock Select

/* TIMSK Register pins   */
#define TIMSK_TICIE1           5 // Input Capture Interrupt Enable
#define TIMSK_OCIE1A           4 // Output Compare A Match Interrupt Enable
#define TIMSK_OCIE1B           3 // Output Compare B Match Interrupt Enable
#define TIMSK_TOIE1            2 // Overflow Interrupt Enable

/* TIFR Register pins   */
#define TIFR_ICF1              5 // Input Capture Flag
#define TIFR_OCF1A             4 // Output Compare A Match Flag
#define TIFR_OCF1B             6 // Output Compare B Match Flag
#define TIFR_TOV1              2 // Overflow Flag

#endif
