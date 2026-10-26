//processusPasserelleCan637:


//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "piloteCAN1.h"
#include "interfaceS0008.h"
#include "ProcessusPasserelleCan637.h"
#include "serviceProtocole637.h"

//Definitions privees

extern CAN_RxHeaderTypeDef piloteCAN1_reception;



//Declarations de fonctions privees:
void processusPasserelleCan637_Attente_Message_Can(void);
void processusPasserelleCan637_Lecture_Message_Can(void);
void processusPasserelleCan637_Envoie_Can_Sur_637(void);


//Definitions de variables privees:
unsigned char CanDataRecu[9];
unsigned char SerieDataRecu[INTERFACES0008_NOMBRE_D_OCTETS_A_RECEVOIR]; 
unsigned char AdressRecuSerie;
unsigned int TimerCanSend = 0;
unsigned int TimerTest = 0;
unsigned int FlagNewData = 0;
unsigned int bTestLed = 0;
unsigned int bTestLed2 = 0;
unsigned int NbrDataCan = 0;
unsigned int FirstDataRecu = 0;
unsigned int testCan = 0;



//Definitions de fonctions privees:
void processusPasserelleCan637_Attente_Message_Can(void)
{
  testCan = piloteCAN1_messageDisponible();
  if(testCan != 0)
  {
    serviceBaseDeTemps_execute[PROCESSUSPASSERELLECAN637_CAN_TO_637] =
    processusPasserelleCan637_Lecture_Message_Can;
  }
//*************test port série*********************
//  if(TimerTest >= 1000)
//  {
//    TimerTest = 0;
//    for (int i = 0; i < 5; i++)
//      {
//        interfaceS0008.octetsATransmettre[i+1] = ('A'+i);
//      }
//      interfaceS0008.octetsATransmettre[0] = 0x34;
//      interfaceS0008.NombreOctet = 6;
//      interfaceS0008.requete = REQUETE_ACTIVE;
//
//  }
//  TimerTest++;
//*****************************************
}

void processusPasserelleCan637_Lecture_Message_Can(void)
{
  if(piloteCAN1_litUnMessageRecu(CanDataRecu))
  {
    for (int i = 0; i < piloteCAN1_reception.DLC; i++)
    {
      interfaceS0008.octetsATransmettre[i+1] = CanDataRecu[i];
    }
    interfaceS0008.octetsATransmettre[0] = (piloteCAN1_reception.StdId & 0x0FF);
    interfaceS0008.NombreOctet = (piloteCAN1_reception.DLC + 1);
    interfaceS0008.requete = REQUETE_ACTIVE;
  }
  serviceBaseDeTemps_execute[PROCESSUSPASSERELLECAN637_CAN_TO_637] =
      processusPasserelleCan637_Attente_Message_Can;
}



void processusPasserelleCan637_Attente_637(void)
{
  if(interfaceS0008.information == INFORMATION_DISPONIBLE)
  {
    interfaceS0008.information = INFORMATION_TRAITEE;
    
    if(interfaceS0008.octetsRecus[0] == AdressRecuSerie)
    {
      FlagNewData = 0;
    }
    else
    {
      FlagNewData = 1;
    }
    
    if(FlagNewData == 1)
    {
      
      FlagNewData = 0;
      for (int i = 0; i < INTERFACES0008_NOMBRE_D_OCTETS_A_RECEVOIR; i++)
      {
        SerieDataRecu[i] = interfaceS0008.octetsRecus[i+1];
      }
      AdressRecuSerie = interfaceS0008.octetsRecus[0];
      for (int i = 0; i < 15; i++)
      {
        serviceProtocole637.octetsRecus[i] = 0;
      }
      FirstDataRecu = 1;
    }
 
  }
  if(FirstDataRecu == 1)
  {
    if(TimerCanSend >= 1000)
    {
      TimerCanSend = 0;
      NbrDataCan = (INTERFACES0008_NOMBRE_D_OCTETS_A_RECEVOIR - 1);
      piloteCAN1_transmetDesDonnes(AdressRecuSerie, SerieDataRecu, NbrDataCan);
    }
   TimerCanSend++;
  }
}


//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void processusPasserelleCan637_initialise(void)
{

  serviceBaseDeTemps_execute[PROCESSUSPASSERELLECAN637_CAN_TO_637] =
      processusPasserelleCan637_Attente_Message_Can;
  
  serviceBaseDeTemps_execute[PROCESSUSPASSERELLECAN637_637_TO_CAN] =
      processusPasserelleCan637_Attente_637;
}
