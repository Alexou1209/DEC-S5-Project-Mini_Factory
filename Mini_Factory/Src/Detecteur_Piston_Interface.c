#include "Detecteur_Piston_Interface.h"

bool bDetecteur_Piston_Sortie(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSMAPI, hi2c1) & 0x20);
}

bool bDetecteur_Piston_Entree(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSMAPI, hi2c1) & 0x10);
}