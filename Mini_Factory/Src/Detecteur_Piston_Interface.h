#ifndef DETECTEUR_PISTON_INTERFACE_H
#define DETECTEUR_PISTON_INTERFACE_H

#include "stdbool.h"
#include "main.h"
#include "I2C_Pilote.h"

#define PCF8574A_ADDRESSMAPI 0x38 // Adresse I2C du PCF8574 de Mapi 000

bool bDetecteur_Piston_Sortie(I2C_HandleTypeDef *hi2c1);
bool bDetecteur_Piston_Entree(I2C_HandleTypeDef *hi2c1);

#endif