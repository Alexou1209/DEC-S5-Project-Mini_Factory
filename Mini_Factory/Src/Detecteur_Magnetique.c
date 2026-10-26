#include "Detecteur_Magnetique.h"

bool bDetecteur_Metal(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSMAPI, hi2c1) & 0x04);
}