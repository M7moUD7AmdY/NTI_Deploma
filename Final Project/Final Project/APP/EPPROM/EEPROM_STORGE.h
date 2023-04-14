/*
 * EEPROM_STORGE.h
 *
 * Created: 1/3/2023 1:28:39 AM
 *  Author: Moamen
 */ 


#ifndef EEPROM_STORGE_H_
#define EEPROM_STORGE_H_

void EEPROM_voidStorgeTempInit(void);
void TEMP_voidStoreValue(u8 Copy_u8TempHigh,u8 Copy_u8TempLow);
void TEMP_voidReadValue(u8 Copy_u8TempHigh,u8 Copy_u8TempLow);

#endif /* EEPROM_STORGE_H_ */