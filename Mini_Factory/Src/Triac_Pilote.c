#include "Triac_Pilote.h"

bool bReturn_Zero_Cross(void)
{
  return HAL_GPIO_ReadPin(GPIOC, PC13_Pin);
}

void vWrite_CTRL(bool bEtat)
{
  if(bEtat == 1) {HAL_GPIO_WritePin(GPIOE, PE6_Pin, GPIO_PIN_SET);}
  else         {HAL_GPIO_WritePin(GPIOE, PE6_Pin, GPIO_PIN_RESET);}
}