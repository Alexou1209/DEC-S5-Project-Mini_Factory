#include "Piston_Interface.h"

void vActive_Piston(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 & 0xBF;
  *DataCarte3 = *DataCarte3 | 0x80;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}

void vArrete_Piston(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 & 0x7F;
  *DataCarte3 = *DataCarte3 | 0x40;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}