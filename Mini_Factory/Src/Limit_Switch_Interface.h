#ifndef LIMIT_SWITCH_INTERFACE_H
#define LIMIT_SWITCH_INTERFACE_H

#include "stdbool.h"
#include "main.h"
#include "I2C_Pilote.h"

#define PCF8574A_ADDRESSSHAD 0x3D // Adresse I2C du PCF8574 de Shad 101
#define PCF8574A_ADDRESSALEX 0x3F // Adresse I2C du PCF8574 d'Alex 111

bool bLimit_switch_Haut(I2C_HandleTypeDef *hi2c1);
bool bLimit_switch_Bas(I2C_HandleTypeDef *hi2c1);

#endif