#include "Detecteur_Poussoir_Magasin_Interface.h"

bool bDetecteur_Poussoir_Magasin_Sortie(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSALEX, hi2c1) & 0x02);
}

bool bDetecteur_Poussoir_Magasin_Entree(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSALEX, hi2c1) & 0x01);
}