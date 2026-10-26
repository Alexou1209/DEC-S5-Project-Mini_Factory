//interfaceT1:
//Historique: 
// 2018-09-30, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteIOMoteur.h"
#include "interfaceMoteur.h"

//Definitions privees
//pas de definitions privees

//Declarations de fonctions privees:
//pas de fonction privees

//Definitions de variables privees:
unsigned int ValeurMasquer = 0;

//Definitions de fonctions privees:
//pas de fonctions privees

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void interfaceMoteur_ActualiseMoteur(unsigned int ValeurPhase)
{
  if((ValeurPhase & 0x01) > 0)
  {
    piloteIOMoteur1_metLaSortieA(1);
  }
  else
  {
    piloteIOMoteur1_metLaSortieA(0);
  }
  
  if((ValeurPhase & 0x02) > 0)
  {
    piloteIOMoteur2_metLaSortieA(1);
  }
  else
  {
    piloteIOMoteur2_metLaSortieA(0);
  }
  
  if((ValeurPhase & 0x04) > 0)
  {
    piloteIOMoteur3_metLaSortieA(1);
  }
  else
  {
    piloteIOMoteur3_metLaSortieA(0);
  }
  
  if((ValeurPhase & 0x08) > 0)
  {
    piloteIOMoteur4_metLaSortieA(1);
  }
  else
  {
    piloteIOMoteur4_metLaSortieA(0);
  }


}


void interfaceMoteur_initialise(void)
{
  piloteIOMoteur1_metLaSortieA(0);
  piloteIOMoteur2_metLaSortieA(0);
  piloteIOMoteur3_metLaSortieA(0);
  piloteIOMoteur4_metLaSortieA(0);
}


