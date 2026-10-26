#include "Detecteur_Optique_Chute_Interface.h"

bool bDetecteur_Optique_Chute(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSALEX, hi2c1) & 0x08);
}