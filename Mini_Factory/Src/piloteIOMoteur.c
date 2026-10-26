//piloteIOT1:
//Historique: 
// 2018-09-30, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteIOMoteur.h"

//Definitions privees
//pas de définitions privees

//Declarations de fonctions privees:
//pas de fonction privees

//Definitions de variables privees:
//pas de variables privees

//Definitions de fonctions privees:
//pas de fonctions privees

//Definitions de variables publiques:
// pas de variables publiques

//Definitions de fonctions publiques:
void piloteIOMoteur1_metLaSortieA(unsigned char Valeur)
{
  HAL_GPIO_WritePin(Pin1Moteur_GPIO_Port, Pin1Moteur_Pin, (GPIO_PinState)Valeur);  
}

void piloteIOMoteur2_metLaSortieA(unsigned char Valeur)
{
  HAL_GPIO_WritePin(Pin2Moteur_GPIO_Port, Pin2Moteur_Pin, (GPIO_PinState)Valeur);  
}

void piloteIOMoteur3_metLaSortieA(unsigned char Valeur)
{
  HAL_GPIO_WritePin(Pin3Moteur_GPIO_Port, Pin3Moteur_Pin, (GPIO_PinState)Valeur);  
}

void piloteIOMoteur4_metLaSortieA(unsigned char Valeur)
{
  HAL_GPIO_WritePin(Pin4Moteur_GPIO_Port, Pin4Moteur_Pin, (GPIO_PinState)Valeur);  
}


void piloteIOMoteur_initialise(void)
{
  HAL_GPIO_WritePin(Pin1Moteur_GPIO_Port, Pin1Moteur_Pin, GPIO_PIN_RESET);  
  HAL_GPIO_WritePin(Pin2Moteur_GPIO_Port, Pin2Moteur_Pin, GPIO_PIN_RESET);  
  HAL_GPIO_WritePin(Pin3Moteur_GPIO_Port, Pin3Moteur_Pin, GPIO_PIN_RESET);  
  HAL_GPIO_WritePin(Pin4Moteur_GPIO_Port, Pin4Moteur_Pin, GPIO_PIN_RESET);  
}




