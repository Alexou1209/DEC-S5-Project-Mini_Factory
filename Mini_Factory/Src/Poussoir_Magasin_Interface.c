#include "Poussoir_Magasin_Interface.h"

void vActive_Poussoir_Magasin(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 & 0xFE;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE2, hi2c1, DataCarte3);
}

void vArrete_Poussoir_Magasin(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 | 0x01;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE2, hi2c1, DataCarte3);
}