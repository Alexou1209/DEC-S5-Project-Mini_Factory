//processusAscenceur:


//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "processusAscenceur.h"
#include "interfaceMoteur.h"
#include "processusTriac.h"

//Definitions privees



//Declarations de fonctions privees:

int RequeteAscenceur = 0; 
int SwitchBasFlag = 0;
int SwitchHautFlag = 0;

//Definitions de variables privees:
int TabHoraire[4] =  {0x08, 0x04, 0x02, 0x01};
int TabAntiHoraire[4] =  {0x01, 0x02, 0x04, 0x08};
int Timer10ms = 0;
int nbrStep = 0;
int valeurStepToSend = 0;


//********supprimer (juste pour enlever error)**********************

//******************************************************************



//Definitions de fonctions privees:
void processusAscenceur_Attends_Requete(void)
{
  if(RequeteAscenceur == REQUETEPOURMONTER)
  {
    RequeteAscenceur = REQUETETRAITEE;
    serviceBaseDeTemps_execute[PROCESSUSASCENCEUR_EN_FONCTION] =
      processusAscenceur_Monte_Ascenceur;
    return;
  }
  if(RequeteAscenceur == REQUETEPOURDESCENDRE)
  {
    RequeteAscenceur = REQUETETRAITEE;
    serviceBaseDeTemps_execute[PROCESSUSASCENCEUR_EN_FONCTION] =
      processusAscenceur_Descends_Ascenceur;
    return;
  }
  
}

void processusAscenceur_Descends_Ascenceur(void)
{
 
  if(Timer10ms == 20)
  {
     Timer10ms = 0;
     valeurStepToSend = TabAntiHoraire[nbrStep];
     interfaceMoteur_ActualiseMoteur(valeurStepToSend);
     nbrStep++;
     if(nbrStep > 3)
     {
       nbrStep = 0;
     }
  }
  Timer10ms++;
  if(SwitchBasFlag == BAS)
  {
    FlagLumOFF = 1;
    SwitchBasFlag = 0;
    nbrStep = 0;
    Timer10ms = 0;
    serviceBaseDeTemps_execute[PROCESSUSASCENCEUR_EN_FONCTION] =
      processusAscenceur_Attends_Requete;
  }
}


void processusAscenceur_Monte_Ascenceur(void)
{
    if(Timer10ms == 20) 
  {
     Timer10ms = 0;
     valeurStepToSend = TabHoraire[nbrStep];
     interfaceMoteur_ActualiseMoteur(valeurStepToSend);
     nbrStep++;
     if(nbrStep > 3)
     {
       nbrStep = 0;
     }
  }
  Timer10ms++;
  if(SwitchHautFlag == HAUT)
  {
    FlagLumON = 1;
    SwitchHautFlag = 0;
    nbrStep = 0;
    Timer10ms = 0;
    serviceBaseDeTemps_execute[PROCESSUSASCENCEUR_EN_FONCTION] =
      processusAscenceur_Attends_Requete;
  }
}


//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void processusMoteur_initialise(void)
{

  serviceBaseDeTemps_execute[PROCESSUSASCENCEUR_EN_FONCTION] =
      processusAscenceur_Attends_Requete;
  
}
