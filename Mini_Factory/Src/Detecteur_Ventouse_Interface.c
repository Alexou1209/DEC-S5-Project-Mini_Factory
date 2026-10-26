#include "Detecteur_Ventouse_Interface.h"

bool bDetecteur_Ventouse_Haut(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSMAPI, hi2c1) & 0x01);
}

bool bDetecteur_Ventouse_Bas(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSMAPI, hi2c1) & 0x02);
}