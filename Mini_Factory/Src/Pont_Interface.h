#ifndef PONT_INTERFACE_H
#define PONT_INTERFACE_H

#include "stdbool.h"
#include "main.h"
#include "I2C_Pilote.h"
#define PCF8574_ADDRESS_WRITECARTE3  0x39// Adresse I2C du PCF8574 pour écrire  001 / 0x72 
#define PCF8574_ADDRESS_WRITECARTE2  0x3C// Adresse I2C du PCF8574 pour écrire  100 / 0x79
#define PCF8574A_ADDRESSSHAD 0x3D // Adresse I2C du PCF8574 de Shad 101

void vMonte_Ventouse(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1);
void vDescend_Ventouse(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1);
void vActive_Vacuum(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1);
void vArrete_Vacuum(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1);
void vPont_Home(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1);
void vPont_Va_A(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1, unsigned char ucPosition);
bool bMotion_Complete(I2C_HandleTypeDef *hi2c1);
void vReset_Start(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1);
#endif