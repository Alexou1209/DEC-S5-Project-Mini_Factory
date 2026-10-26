#include "Convoyeur_Interface.h"


void vActive_Convoyeur(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte2 = *DataCarte2 & 0xFD;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE2, hi2c1, DataCarte2);
}

void vArrete_Convoyeur(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte2 = *DataCarte2 | 0x02;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE2, hi2c1, DataCarte2);
}