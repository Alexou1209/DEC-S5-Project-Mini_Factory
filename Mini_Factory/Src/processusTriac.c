//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "processusTriac.h"
#include "Triac_interface.h"

int FlagLumON = 0;
int FlagLumOFF = 0;


//Definitions privees



//Declarations de fonctions privees:

//Definitions de variables privees:

//********supprimer (juste pour enlever error)**********************

//******************************************************************



//Definitions de fonctions privees:

// 0 TRIACALLUME 1 ETEINT
void processusTriac_Varie_Triac(void)
{
 if(FlagLumON)
 {
   vTriac(0);
   FlagLumON = 0;
 }
 if(FlagLumOFF)
 {
   vTriac(1);
   FlagLumOFF = 0;
 }
}


//Definitions de fonctions publiques:
void processusTriac_initialise(void)
{

  serviceBaseDeTemps_execute[PROCESSUSTRIAC_EN_FONCTION] =
      processusTriac_Varie_Triac;
  
}
