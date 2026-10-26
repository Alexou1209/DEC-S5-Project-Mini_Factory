#include "Lumiere_Verte_Usine.h"

void vAllume_Lumiere_Usine(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 & 0xFE;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}

void vEteint_Lumiere_Usine(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 | 0x01;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}