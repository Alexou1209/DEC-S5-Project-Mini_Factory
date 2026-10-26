#ifndef DETECTEUR_POUSSOIR_MAGASIN_INTERFACE_H
#define DETECTEUR_POUSSOIR_MAGASIN_INTERFACE_H

#include "stdbool.h"
#include "main.h"
#include "I2C_Pilote.h"

#define PCF8574A_ADDRESSALEX 0x3F // Adresse I2C du PCF8574 d'Alex 111

bool bDetecteur_Poussoir_Magasin_Sortie(I2C_HandleTypeDef *hi2c1);
bool bDetecteur_Poussoir_Magasin_Entree(I2C_HandleTypeDef *hi2c1);

#endif