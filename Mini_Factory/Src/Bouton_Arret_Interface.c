#include "Bouton_Arret_Interface.h"

bool bBouton_Arret(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSALEX, hi2c1) & 0x20);
}