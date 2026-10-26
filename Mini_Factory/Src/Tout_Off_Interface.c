#include "Tout_Off_Interface.h"

void Met_Tout_A_Off(I2C_HandleTypeDef *hi2c1, uint8_t *DataCarte3)
{
  *DataCarte3 = *DataCarte3 | 0xFF;
  
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}