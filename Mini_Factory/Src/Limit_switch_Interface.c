#include "Limit_Switch_Interface.h"

bool bLimit_switch_Haut(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSSHAD, hi2c1) & 0x80);
}

bool bLimit_switch_Bas(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSALEX, hi2c1) & 0x80);
}