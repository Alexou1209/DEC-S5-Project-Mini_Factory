#include "Detecteur_Capacitif_Interface.h"

bool bDetecteur_Capacitif(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSMAPI, hi2c1) & 0x08);
}