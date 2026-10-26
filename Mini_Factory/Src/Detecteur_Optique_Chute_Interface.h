#ifndef DETECTEUR_OPTIQUE_CHUTE_INTERFACE_H
#define DETECTEUR_OPTIQUE_CHUTE_INTERFACE_H

#include "stdbool.h"
#include "main.h"
#include "I2C_Pilote.h"

#define PCF8574A_ADDRESSALEX 0x3F // Adresse I2C du PCF8574 d'Alex 111

bool bDetecteur_Optique_Chute(I2C_HandleTypeDef *hi2c1);

#endif