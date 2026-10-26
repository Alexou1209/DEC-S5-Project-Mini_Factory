#ifndef TOUT_OFF_INTERFACE_H
#define TOUT_OFF_INTERFACE_H


#include "I2C_Pilote.h"
#define PCF8574_ADDRESS_WRITECARTE3  0x39// Adresse I2C du PCF8574 pour écrire  001 / 0x72 

void Met_Tout_A_Off(I2C_HandleTypeDef *hi2c1, uint8_t *DataCarte3);

#endif