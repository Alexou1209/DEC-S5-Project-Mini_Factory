#include "Carte_Lumiere_Pilote.h"

void vWrite_Pin(unsigned char ucValeur)
{
  if(ucValeur & 0x01){HAL_GPIO_WritePin(GPIOE, PE0_Pin, GPIO_PIN_SET);}
  else             {HAL_GPIO_WritePin(GPIOE, PE0_Pin, GPIO_PIN_RESET);}
  
  if(ucValeur & 0x02){HAL_GPIO_WritePin(GPIOA, PA5_Pin, GPIO_PIN_SET);}
  else              {HAL_GPIO_WritePin(GPIOA, PA5_Pin, GPIO_PIN_RESET);}
  
  if(ucValeur & 0x04){HAL_GPIO_WritePin(GPIOA, PA6_Pin, GPIO_PIN_SET);}
  else              {HAL_GPIO_WritePin(GPIOA, PA6_Pin, GPIO_PIN_RESET);}
  
  if(ucValeur & 0x08){HAL_GPIO_WritePin(GPIOA, PA7_Pin, GPIO_PIN_SET);}
  else              {HAL_GPIO_WritePin(GPIOA, PA7_Pin, GPIO_PIN_RESET);}
}