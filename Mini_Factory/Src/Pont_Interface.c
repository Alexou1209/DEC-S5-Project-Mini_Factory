#include "Pont_Interface.h"

void vMonte_Ventouse(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 & 0xFB;
  *DataCarte3 = *DataCarte3 | 0x02;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}

void vDescend_Ventouse(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 & 0xFD;
  *DataCarte3 = *DataCarte3 | 0x04;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}

void vActive_Vacuum(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 & 0xF7;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}

void vArrete_Vacuum(uint8_t *DataCarte3, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte3 = *DataCarte3 | 0x08;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE3, hi2c1, DataCarte3);
}

void vPont_Home(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1)
{
//  *DataCarte2 = *DataCarte2 | 0xFC;
//  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE2, hi2c1, DataCarte2);
//  HAL_Delay(50); // CHANGER LE DELAI
  *DataCarte2 = *DataCarte2 & 0x3F;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE2, hi2c1, DataCarte2);
}
void vReset_Start(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1)
{
  *DataCarte2 = *DataCarte2 | 0x9C;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE2, hi2c1, DataCarte2);
}
void vPont_Va_A(uint8_t *DataCarte2, I2C_HandleTypeDef *hi2c1, unsigned char ucPosition)
{
  switch(ucPosition)
  {
  case 0:
    *DataCarte2 = *DataCarte2 | 0x1C;
    *DataCarte2 = *DataCarte2 & 0xFF;
    break;
    
  case 1:
    *DataCarte2 = *DataCarte2 | 0x1C;
    *DataCarte2 = *DataCarte2 & 0xFB;
    break;
    
  case 2:
    *DataCarte2 = *DataCarte2 | 0x1C;
    *DataCarte2 = *DataCarte2 & 0xF7;
    break;
    
  case 3:
    *DataCarte2 = *DataCarte2 | 0x1C;
    *DataCarte2 = *DataCarte2 & 0xF3;
    break;
    
  case 4:
    *DataCarte2 = *DataCarte2 | 0x1C;
    *DataCarte2 = *DataCarte2 & 0xEF;
    break;
  }
  *DataCarte2 = *DataCarte2 & 0x7F;
  writeDigitalInputsI2C(PCF8574_ADDRESS_WRITECARTE2, hi2c1, DataCarte2);
}

bool bMotion_Complete(I2C_HandleTypeDef *hi2c1)
{
  return(readDigitalInputsI2C(PCF8574A_ADDRESSSHAD, hi2c1) & 0x02);
}