#ifndef ADC_RESSORT_INTERFACE_H
#define ADC_RESSORT_INTERFACE_H

#include "stdbool.h"
#include "main.h"
#include "I2C_Pilote.h"

#define ADC_ADDRESS 0x4D // Adresse I2C du PCF8574 de Shad 101

int iLire_Ressort(I2C_HandleTypeDef *hi2c1);
#endif