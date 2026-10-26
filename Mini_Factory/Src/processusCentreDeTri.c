//processusCentreDeTri:


//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "processusCentreDeTri.h"
#include "Convoyeur_Interface.h"
#include "Piston_Interface.h"
#include "Poussoir_Magasin_Interface.h"
#include "Elevateur_Interface.h"
#include "Pont_Interface.h"
#include "Detecteur_Magnetique.h"
#include "Detecteur_Optique_Interface.h"
#include "Detecteur_Ventouse_Interface.h"
#include "Detecteur_Capacitif_Interface.h"
#include "Detecteur_Piston_Interface.h"
#include "Detecteur_Elevateur_Interface.h"
#include "Detecteur_Poussoir_Magasin_Interface.h"
#include "Detecteur_Optique_Chute_Interface.h"
#include "Bouton_Depart_Interface.h"
#include "Bouton_Arret_Interface.h"
#include "ADC_Ressort_Interface.h"
#include "Carte_Lumiere_Interface.h"
#include "Lumiere_Verte_Usine.h"
#include "processusCentreDeTri.h"
#include "Limit_Switch_Interface.h"
#include "processusAscenceur.h"
#include "processusClignote.h"
#include "Bouton_Bleu_Interface.h"
#include "processusCan.h"
#include "processusTriac.h"
#include "Tout_Off_Interface.h"

//Definitions privees

I2C_HandleTypeDef *AdresseI2CSTM;


//Declarations de fonctions privees:
void processusCentreDeTri_Attends_Bouton(void);
void processusCentreDeTri_Mode_Fonctionnement_Phase1(void);
void processusCentreDeTri_Mode_Fonctionnement_Pousse_Puck(void);
void processusCentreDeTri_Mode_Fonctionnement_Identification(void);
void processusCentreDeTri_Mode_Fonctionnement_Attente_Monte_Puck(void);
void processusCentreDeTri_Mode_Fonctionnement_Attente_Puck_Sur_Convoyeur(void);
void processusCentreDeTri_Mode_Fonctionnement_Attente_Detecteur_Optique(void);
void processusCentreDeTri_Mode_Fonctionnement_Attente_Pont(void);
void processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Bas(void);
void processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Haut(void);
void processusCentreDeTri_Mode_Fonctionnement_Attente_Pont_Rendu(void);
void processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Bas_Quand_Rendu(void);
void processusCentreDeTri_Mode_Fonctionnement_Attente_Ascenceur_Bas(void);

void processusCentreDeTri_Mode_Test(void);
void processusCentreDeTri_Mode_Arret(void);


//Definitions de variables privees:


uint8_t DataCarte3 = 0xFF;
uint8_t DataCarte2 = 0xFF;
unsigned char ucPuck;
unsigned char ucPosition = 3;
unsigned char ucCompteurModeTest = 0;
int flagModeTestColonneLumineuse = 0;
int flagAncienneEtatBoutonVert = 1;
int flagNouvelleEtatBoutonVert = 1;
int TimerPousse = 0;
int TimerPont = 0;
int TimerAscenceur = 0;
int flagPistonSorti = 0;
int flagPontStart = 0;
int FirstTimeInPoussePuck = 0;
int FlagHome = 0;
int FlagBouton = 0;
int TimerPoussePuck = 0;
int TimerCharge = 0;
//Definitions de fonctions privees:
void processusCentreDeTri_Attends_Bouton(void)
{
  FlagLumOFF = 1;
  FlagEnBas = 0;
  CanDataSend[2] = 0x80;
  CanDataSend[1] = 0x60;
  CanDataSend[0] = 0x39;
  Met_Tout_A_Off(AdresseI2CSTM, &DataCarte3);
  if(bDetecteur_Ventouse_Haut(AdresseI2CSTM) == 0 && FlagHome == 0)
  {
    vReset_Start(&DataCarte2, AdresseI2CSTM);   
    flagPontStart = 1;
    if(flagPontStart == 1)
    {
      TimerPont ++;
      if(TimerPont == 100)
      {
        TimerPont = 0;
        flagPontStart = 0;
        vPont_Home(&DataCarte2, AdresseI2CSTM);
        FlagHome = 1;
      }
    }
  } 
  else
  {
    vMonte_Ventouse(&DataCarte3, AdresseI2CSTM);
  }
  if(FlagONOFF == ON){vLumiere_Verte(1);}
  else               {vEteint_Tout();}
  
  vEteint_Lumiere_Usine(&DataCarte3, AdresseI2CSTM);
  
  TimerPousse = 0;
  FirstTimeInPoussePuck = 0;
  if(bBouton_Depart(AdresseI2CSTM) == 1){FlagBouton = 0;}
  if(bBouton_Depart(AdresseI2CSTM) == 0 || FlagOperation == 1)
  {
    if(FlagBouton == 0)
    {
      FlagOperation = 0;
      serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
        processusCentreDeTri_Mode_Fonctionnement_Phase1;
      return;
    }
  }
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    FlagAbort = 0;
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bBouton_Bleu() == 0)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Test;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  if(bLimit_switch_Bas(AdresseI2CSTM) == 0)
  {
    SwitchBasFlag = 1;
  }
}

void processusCentreDeTri_Mode_Fonctionnement_Phase1(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  vEteint_Tout();
  if(bLimit_switch_Haut(AdresseI2CSTM))
  {
    SwitchHautFlag = 0;
    RequeteAscenceur = REQUETEPOURMONTER;
  }
  
  CanDataSend[0] = 0x40;
  CanDataRecu[0] = 0;
  
  vMonte_Ventouse(&DataCarte3, AdresseI2CSTM);
  vArrete_Vacuum(&DataCarte3, AdresseI2CSTM);
  vArrete_Convoyeur(&DataCarte2, AdresseI2CSTM);
  vArrete_Piston(&DataCarte3, AdresseI2CSTM);
  vArrete_Poussoir_Magasin(&DataCarte2, AdresseI2CSTM);
  
  
  vAllume_Lumiere_Usine(&DataCarte3, AdresseI2CSTM);
  vReset_Start(&DataCarte2, AdresseI2CSTM);   
  flagPontStart = 1;
  if(flagPontStart == 1)
  {
    TimerPont ++;
    if(TimerPont == 100)
    {
      TimerPont = 0;
      flagPontStart = 0;
      vPont_Va_A(&DataCarte2, AdresseI2CSTM,1);
      if(bDetecteur_Elevateur_Bas(AdresseI2CSTM))
      {
        vArrete_Elevateur(&DataCarte3, AdresseI2CSTM);
      }
      else
      {
        if(bDetecteur_Capacitif(AdresseI2CSTM))
        {
          serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
            processusCentreDeTri_Mode_Fonctionnement_Pousse_Puck;
          return;
        }
        serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
          processusCentreDeTri_Mode_Fonctionnement_Identification;
      }
    }
    
  }
  
  
}

void processusCentreDeTri_Mode_Fonctionnement_Pousse_Puck(void)
{
  
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  
  if(FirstTimeInPoussePuck == 0)
  {
    vActive_Poussoir_Magasin(&DataCarte2, AdresseI2CSTM);
    FirstTimeInPoussePuck = 1;
  }
  TimerPousse++;
  if(TimerPousse >= 2000)
  {
    FirstTimeInPoussePuck = 1;
    vArrete_Poussoir_Magasin(&DataCarte2, AdresseI2CSTM);
    TimerPoussePuck ++;
    if(TimerPoussePuck >= 500)
    {
      TimerPousse = 0;
      TimerPoussePuck = 0;
      serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Fonctionnement_Identification;
    }
  }     
}

void processusCentreDeTri_Mode_Fonctionnement_Identification(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  
  if(bDetecteur_Metal(AdresseI2CSTM) == 0)        
  {
    ucPuck = 'M';
    CanDataSend[1] = 0x63;
  }
  else if(bDetecteur_Optique(AdresseI2CSTM) == 0) 
  {
    ucPuck = 'O';
    CanDataSend[1] = 0x62;
  }  
  else
  {
    ucPuck = 'N';
    CanDataSend[1] = 0x61;
  }
  vActive_Elevateur(&DataCarte3, AdresseI2CSTM);
  
  if(ucPuck == 'O')                          {vLumiere_Jaune(1);}
  if(ucPuck == 'M')                          {vLumiere_Verte(1);}
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
    processusCentreDeTri_Mode_Fonctionnement_Attente_Monte_Puck;
}


void processusCentreDeTri_Mode_Fonctionnement_Attente_Monte_Puck(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  
  if(bDetecteur_Elevateur_Haut(AdresseI2CSTM) == 0)
  {
    vActive_Convoyeur(&DataCarte2, AdresseI2CSTM);
    vActive_Piston(&DataCarte3, AdresseI2CSTM);
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Fonctionnement_Attente_Puck_Sur_Convoyeur;
  }
}

void processusCentreDeTri_Mode_Fonctionnement_Attente_Puck_Sur_Convoyeur(void)
{
  
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  
  if(bDetecteur_Piston_Sortie(AdresseI2CSTM) == 0)
  {
    flagPistonSorti = 1;
  }
  if(flagPistonSorti == 1)
  {
    TimerPousse++;
    if(TimerPousse == 300)
    {
      TimerPousse = 0;
      flagPistonSorti = 0;
      vArrete_Elevateur(&DataCarte3, AdresseI2CSTM);
      vArrete_Piston(&DataCarte3, AdresseI2CSTM);
      serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
        processusCentreDeTri_Mode_Fonctionnement_Attente_Detecteur_Optique;
    }
  }
}

void processusCentreDeTri_Mode_Fonctionnement_Attente_Detecteur_Optique(void)
{
  
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  
  if(bDetecteur_Optique_Chute(AdresseI2CSTM) == 0)
  {
    vArrete_Convoyeur(&DataCarte2, AdresseI2CSTM);
    vReset_Start(&DataCarte2, AdresseI2CSTM); // uyruybgliugthiutruitr
    flagPontStart = 1;
    if(flagPontStart == 1)
    {
      TimerPont ++;
      if(TimerPont == 100)
      {
        TimerPont = 0;
        flagPontStart = 0;
        vPont_Va_A(&DataCarte2, AdresseI2CSTM,1);
        serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
          processusCentreDeTri_Mode_Fonctionnement_Attente_Pont;
      }
    }
  }
}

void processusCentreDeTri_Mode_Fonctionnement_Attente_Pont(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  
  if(bMotion_Complete(AdresseI2CSTM) == 0)
  {
    flagPontStart = 1;
    if(flagPontStart == 1)
    {
      TimerPont ++;
      if(TimerPont == 100)
      {
        TimerPont = 0;
        flagPontStart = 0;
        if(ucPuck == 'N')
        {
          vDescend_Ventouse(&DataCarte3, AdresseI2CSTM);
          serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
            processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Bas;
        }
        else if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
        {
          SwitchHautFlag = 1; 
          vDescend_Ventouse(&DataCarte3, AdresseI2CSTM);
          serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
            processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Bas;
        }
        else
        {
          SwitchHautFlag = 0;
          RequeteAscenceur = REQUETEPOURMONTER;
        }
      }
    }
  }
}

void processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Bas(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  
  if(bDetecteur_Ventouse_Bas(AdresseI2CSTM) == 0)
  {
    vActive_Vacuum(&DataCarte3, AdresseI2CSTM);
    vMonte_Ventouse(&DataCarte3, AdresseI2CSTM);
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Haut;
  }
  
}

void processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Haut(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  
  if(bDetecteur_Ventouse_Haut(AdresseI2CSTM) == 0)
  {
    switch(ucPuck)
    {
    case 'M' :
      ucPosition = 4;
      break;
      
    case 'O' :
      ucPosition = 4;
      break;
      
    case 'N':
      ucPosition = 2;
      break;
    }
    vReset_Start(&DataCarte2, AdresseI2CSTM); // huitghuiuirtythtoij
    flagPontStart = 1;
    if(flagPontStart == 1)
    {
      TimerPont ++;
      if(TimerPont == 100)
      {
        TimerPont = 0;
        flagPontStart = 0;
        vPont_Va_A(&DataCarte2, AdresseI2CSTM,ucPosition);
        serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
          processusCentreDeTri_Mode_Fonctionnement_Attente_Pont_Rendu;
      }
    }
  }
}

void processusCentreDeTri_Mode_Fonctionnement_Attente_Pont_Rendu(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  
  flagPontStart = 1;
  if(flagPontStart == 1)
  {
    TimerPont ++;
    if(TimerPont == 100)
    {
      TimerPont = 0;
      flagPontStart = 0;
      if(bMotion_Complete(AdresseI2CSTM) == 0)
      {
        vDescend_Ventouse(&DataCarte3, AdresseI2CSTM);
        serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
          processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Bas_Quand_Rendu;
      }
    }
  }
}

void processusCentreDeTri_Mode_Fonctionnement_Attente_Ventouse_Bas_Quand_Rendu(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
    FlagLumON = 1;
  }
  
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  
  if(bDetecteur_Ventouse_Bas(AdresseI2CSTM) == 0)
  {
    vArrete_Vacuum(&DataCarte3, AdresseI2CSTM);
    vMonte_Ventouse(&DataCarte3, AdresseI2CSTM);
    if(ucPuck == 'N')
    {
      vEteint_Tout();
      
      serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Attends_Bouton;
    }
    else
    {
      serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Fonctionnement_Attente_Ascenceur_Bas;
    } 
  }
}

void processusCentreDeTri_Mode_Fonctionnement_Attente_Ascenceur_Bas(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(FlagONOFF == ON && ucPuck == 'N')       {vLumiere_Jaune(1);}
  else if(ucPuck == 'N')                     {vLumiere_Jaune(0);}
  
  TimerAscenceur ++;
  if(TimerAscenceur >= 3000)
  {
    TimerAscenceur = 2999;
   if(bLimit_switch_Bas(AdresseI2CSTM) && FlagEnBas == 1)
  {
    FlagEnBas = 0;
    SwitchBasFlag = 0;
    RequeteAscenceur = REQUETEPOURDESCENDRE;
  }
   else if (bLimit_switch_Bas(AdresseI2CSTM) == 0)
   {
     if(TimerCharge <= 1000)
     {
       TimerCharge ++;
       CanDataSend[2] = 0x81;                    //peut prendre un delai avant
     }
     else
     {
       TimerCharge = 0;
       SwitchBasFlag = 1;
       SwitchHautFlag = 0;
       RequeteAscenceur = REQUETEPOURMONTER;
       TimerAscenceur = 0;
       CanDataRecu[0] = 0;
       FlagOperation = 0;
       vEteint_Tout();
       serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
         processusCentreDeTri_Attends_Bouton;
     }
   }
  }
}


void processusCentreDeTri_Mode_Test(void)
{
  if(bBouton_Arret(AdresseI2CSTM) == 0 || FlagAbort == 1)
  {
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Mode_Arret;
    return;
  }
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  if(bLimit_switch_Bas(AdresseI2CSTM) == 0)
  {
    SwitchBasFlag = 1;
  }
  
  FlagLumOFF = 1;
  
    if(FlagONOFF == ON){vAllume_Lumiere_Usine(&DataCarte3, AdresseI2CSTM);}
    else               {vEteint_Lumiere_Usine(&DataCarte3, AdresseI2CSTM);}
  
  
  
    flagNouvelleEtatBoutonVert = bBouton_Depart(AdresseI2CSTM) ;
    
    if(flagNouvelleEtatBoutonVert != flagAncienneEtatBoutonVert){
      flagAncienneEtatBoutonVert = flagNouvelleEtatBoutonVert;
      if(bBouton_Depart(AdresseI2CSTM) == 0)
      {
        flagNouvelleEtatBoutonVert = 0;
        ucCompteurModeTest ++ ;
      }
    }
    flagModeTestColonneLumineuse = 0;
    switch (ucCompteurModeTest)
    {
    case 1:
      //Test les entrees
      flagModeTestColonneLumineuse = 1;
      break;
    case 2: 
      // jecteur de bloc active
      flagModeTestColonneLumineuse = 0;
      vActive_Poussoir_Magasin(&DataCarte2, AdresseI2CSTM);
      break;
    case 3:
      // jecteur de bloc d sactive
      vArrete_Poussoir_Magasin(&DataCarte2, AdresseI2CSTM);
      break;
    case 4:
      //Monte  l vateur
      vActive_Elevateur(&DataCarte3, AdresseI2CSTM);
      break;
    case 5:
      //Descend  l vateur
      vArrete_Elevateur(&DataCarte3, AdresseI2CSTM);
      break;
    case 6:
      //Active Convoyeur 
      vActive_Convoyeur(&DataCarte2, AdresseI2CSTM);
      break;
    case 7:
      //D sactive Convoyeur
      vArrete_Convoyeur(&DataCarte2, AdresseI2CSTM);
      break;
    case 8:
      //Active Pistons
      vActive_Piston(&DataCarte3, AdresseI2CSTM);
      break;
    case 9:
      //D sactive Pistons
      vArrete_Piston(&DataCarte3, AdresseI2CSTM);
      break;
    case 10:
      //Active Ventouse
      vActive_Vacuum(&DataCarte3, AdresseI2CSTM);
      break;
    case 11:
      //D sactive Ventouse
      vArrete_Vacuum(&DataCarte3, AdresseI2CSTM);
      break;
    case 12:
      //Descend Ventouse
      vDescend_Ventouse(&DataCarte3, AdresseI2CSTM);
      break;
    case 13:
      //Monte Ventouse
      vMonte_Ventouse(&DataCarte3, AdresseI2CSTM);
      break;
    case 14:
      //      //Ventouse position 4
      if(bDetecteur_Ventouse_Haut(AdresseI2CSTM) == 0){ 
        vReset_Start(&DataCarte2, AdresseI2CSTM);   
        flagPontStart = 1;
        if(flagPontStart == 1)
        {
          TimerPont ++;
          if(TimerPont == 100)
          {
            TimerPont = 0;
            flagPontStart = 0;
            vPont_Va_A(&DataCarte2, AdresseI2CSTM,4);
          }
        }
      }
      
      break;
    case 15:
      //Ventouse position 1
      if(bDetecteur_Ventouse_Haut(AdresseI2CSTM) == 0){ 
        vReset_Start(&DataCarte2, AdresseI2CSTM);   
        flagPontStart = 1;
        if(flagPontStart == 1)
        {
          TimerPont ++;
          if(TimerPont == 100)
          {
            TimerPont = 0;
            flagPontStart = 0;
            vPont_Va_A(&DataCarte2, AdresseI2CSTM,1);
          }
        }
      }
      break;
    default: 
      ucCompteurModeTest = 0;
      break;
    }
  
  if(flagModeTestColonneLumineuse == 1)
  {
    if(bDetecteur_Metal(AdresseI2CSTM) == 0){ vEteint_Tout(); vLumiere_Jaune(1); }
    else{vLumiere_Jaune(0);}
    if(bDetecteur_Capacitif(AdresseI2CSTM) == 0){ vEteint_Tout(); vLumiere_Rouge(1); }
    else{vLumiere_Rouge(0);}
    if(bDetecteur_Optique(AdresseI2CSTM) == 0){ vEteint_Tout(); vLumiere_Verte(1); }
    else{vLumiere_Verte(0);}
    if(bDetecteur_Optique_Chute(AdresseI2CSTM) == 0){ vEteint_Tout(); vLumiere_Rouge(1); vLumiere_Verte(1); }
    else{vLumiere_Rouge(0); vLumiere_Verte(0);}
    //Erreur = Lumi re Rouge Clignote 
  }
  else
  { 
    vEteint_Tout();
  }
}


void processusCentreDeTri_Mode_Arret(void)
{
  FlagLumOFF = 1;
  vLumiere_Verte(0);
  vLumiere_Jaune(0);
  if(bBouton_Depart(AdresseI2CSTM) == 0|| FlagOperation == 1)
  {
    FlagOperation = 0;
    FlagBouton = 1;
    vEteint_Tout();
    serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
      processusCentreDeTri_Attends_Bouton;
    return;
  }
  
  CanDataRecu[0] = 0;
  
  if(bLimit_switch_Haut(AdresseI2CSTM) == 0)
  {
    SwitchHautFlag = 1;
  }
  if(bLimit_switch_Bas(AdresseI2CSTM) == 0)
  {
    SwitchBasFlag = 1;
  }
  
  FlagEnBas = 0;
  vArrete_Convoyeur(&DataCarte2, AdresseI2CSTM);
  flagBoutonRougeCan = 0x001;
  vLumiere_Rouge(1);
  SwitchHautFlag = 1;
  SwitchBasFlag = 1;
  TimerPont = 0;
  flagPontStart = 0;
  TimerPousse = 0;
  flagPistonSorti = 0;
  FirstTimeInPoussePuck = 0;
  vEteint_Lumiere_Usine(&DataCarte3, AdresseI2CSTM);
  vReset_Start(&DataCarte2, AdresseI2CSTM);   
  flagPontStart = 1;
  if(flagPontStart == 1)
  {
    TimerPont ++;
    if(TimerPont == 100)
    {
      TimerPont = 0;
      flagPontStart = 0;
      vPont_Home(&DataCarte2, AdresseI2CSTM);
    }
  }
}


//Definitions de variables publiques:


//Definitions de fonctions publiques:
void processusCentreDeTri_initialise(I2C_HandleTypeDef *AddI2C)
{
  AdresseI2CSTM = AddI2C;
  serviceBaseDeTemps_execute[PROCESSUSCENTREDETRI_EN_FONCTION] =
    processusCentreDeTri_Attends_Bouton;
  
}
