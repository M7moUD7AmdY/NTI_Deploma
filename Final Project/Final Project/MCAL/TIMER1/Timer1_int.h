/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 16/11/2022                      */
/*                      Module : TIMER_int                       */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/

#ifndef _TIMER1_INT_H
#define _TIMER1_INT_H

/*  TIMER1A   FUNCTIONS  */
void TIMER1A_voidInit(void);                                       // to initialized
													             
void TIMER1A_voidSetCompareVal(u16 Copy_u16Val);                   // to set OCR1A
													             
void TIMER1A_voidEnableCTCInt(void);                               // to enable interrupt
													             
void TIMER1A_voidDisableCTCInt(void);                              // to disable interrupt

void TIMER1A_voidSetCTCCallBack(void (*Copy_ptr) (void) );         // call back function for timer 1A

/***********************************************/


/*  TIMER1B   FUNCTIONS  */
void TIMER1B_voidInit(void);                                       // to initialized
													              
void TIMER1B_voidSetCompareVal(u16 Copy_u16Val);                   // to set OCR1B
													              
void TIMER1B_voidEnableCTCInt(void);                               // to enable interrupt
													              
void TIMER1B_voidDisableCTCInt(void);                              // to disable interrupt

void TIMER1B_voidSetCTCCallBack(void (*Copy_ptr) (void) );         // call back function for timer 1B

/***********************************************/

/*  TIMER1   ICR   FUNCTIONS  */
void TIMER1ICU_voidInit(void);

void TIMER1ICU_voidSetICRVal(u16 Copy_u16Val);

u16 TIMER1ICU_u16ReadICRVal(void);

void TIMER1ICU_voidEnableCTCInt(void);

void TIMER1ICU_voidDisableCTCInt(void);

void TIMER1ICU_voidSetCallBack(void (*Copy_ptr) (void) );

/***********************************************/

/* Over Flow  */
void TIMER1_voidEnableOVInt(void);                                 // to OV enable interrupt

void TIMER1_voidDisableOVInt(void);                               // to OV disable interrupt

void TIMER1_voidSetOVCallBack(void (*Copy_ptr) (void) );
/***********************************************/


/* to set TCNT1  */
void TIMER1_voidSetTimerReg(u16 Copy_u16Val);                          
/***********************************************/

/* get number of counts (TCNT1) */
u16 TIMER1_u16GetTimerReading(void);
/***********************************************/


#endif