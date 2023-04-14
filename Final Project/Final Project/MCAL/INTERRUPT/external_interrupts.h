/*
 * external_interrupts.h
 *
 * Created: 11/26/2022 11:34:45 AM
 *  Author: Mohamed Taha Gabriel
 */ 


#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

#include "../../service_layer/MCU_config.h"
#include "../../service_layer/interrupts.h"

typedef enum{
	low_level_sense,
	anyLogicChange_sense,
	falling_edge_sense,
	rising_edge_sense
	}EN_interrupt_sense_t;

// external interrupt 0 initialization 
void EXT_INT_0_init(EN_interrupt_sense_t sense);
// external interrupt 1 initialization
void EXT_INT_1_init(EN_interrupt_sense_t sense);
// external interrupt 2 initialization
void EXT_INT_2_init(EN_interrupt_sense_t sense);




#endif /* EXTERNAL_INTERRUPTS_H_ */