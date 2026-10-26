#include "Elevateur_Interface.h"

void vActive_Elevateur(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 & 0xDF;
  *DataCarte3 = *DataCarte3 | 0x10;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}

void vArrete_Elevateur(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 & 0xEF;
  *DataCarte3 = *DataCarte3 | 0x20;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}