#ifndef DETECTEUR_ELEVATEUR_INTERFACE_H
#define DETECTEUR_ELEVATEUR_INTERFACE_H

#include "stdbool.h"
#include "main.h"
#include "I2C_Pilote.h"

#define PCF8574A_ADDRESSMAPI 0x38 // Adresse I2C du PCF8574 de Mapi 000

bool bDetecteur_Elevateur_Haut(I2C_HandleTypeDef *hi2c1);
bool bDetecteur_Elevateur_Bas(I2C_HandleTypeDef *hi2c1);

#endif