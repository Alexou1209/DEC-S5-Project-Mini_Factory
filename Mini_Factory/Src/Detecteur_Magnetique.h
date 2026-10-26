#ifndef DETECTEUR_MAGNETIQUE_H
#define DETECTEUR_MAGNETIQUE_H

#include "stdbool.h"
#include "main.h"
#include "I2C_Pilote.h"

#define PCF8574A_ADDRESSMAPI 0x38 // Adresse I2C du PCF8574 de Mapi 000

bool bDetecteur_Metal(I2C_HandleTypeDef *hi2c1);

#endif