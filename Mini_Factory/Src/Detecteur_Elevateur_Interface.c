#include "Detecteur_Elevateur_Interface.h"

bool bDetecteur_Elevateur_Haut(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSMAPI, hi2c1) & 0x80);
}

bool bDetecteur_Elevateur_Bas(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSMAPI, hi2c1) & 0x40);
}