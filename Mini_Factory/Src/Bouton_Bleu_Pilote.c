#include "Bouton_Bleu_Pilote.h"

bool bEtat_Bouton_Bleu(void)
{
  if (HAL_GPIO_ReadPin(GPIOA, B1_Pin) == GPIO_PIN_SET) {return 0;} 
  else                                                     {return 1;} 
}