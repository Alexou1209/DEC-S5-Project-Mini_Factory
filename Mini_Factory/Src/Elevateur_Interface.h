#ifndef ELEVATEUR_INTERFACE_H
#define ELEVATEUR_INTERFACE_H

#include "main.h"
#include "I2C_Pilote.h"
#define PCF8574_ADDRESS_WRITECARTE3  0x39// Adresse I2C du PCF8574 pour écrire  001 / 0x72 

void vActive_Elevateur(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1);
void vArrete_Elevateur(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1);

#endif