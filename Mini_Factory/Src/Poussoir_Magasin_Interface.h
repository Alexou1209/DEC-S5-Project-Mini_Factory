#ifndef POUSSOIR_MAGASIN_INTERFACE_H
#define POUSSOIR_MAGASIN_INTERFACE_H

#include "main.h"
#include "I2C_Pilote.h"
#define PCF8574_ADDRESS_WRITECARTE2  0x3C// Adresse I2C du PCF8574 pour écrire  100 / 0x79

void vActive_Poussoir_Magasin(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1);
void vArrete_Poussoir_Magasin(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1);

#endif