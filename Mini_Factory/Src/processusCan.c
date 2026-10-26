//processusPasserelleCan637:


//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "piloteCAN1.h"
#include "interfaceS0008.h"
#include "processusCan.h"
#include "serviceProtocole637.h"

//Definitions privees

extern CAN_RxHeaderTypeDef piloteCAN1_reception;



//Declarations de fonctions privees:
void processusCAN_Read(void);
void processusCAN_Requete_Send(void);
void processusCan_initialise(void);


//Definitions de variables privees:

unsigned char CanDataSend[3]; 

unsigned int FirstDataRecu = 0;
unsigned int testCan = 0;
unsigned char CanDataRecu[3];
int flagBoutonRougeCan = 0;

unsigned int TimerCanSend;

int FlagOperation = 0;
int FlagAbort = 0;
int FlagEnBas = 0;
//Definitions de fonctions privees:
void processusCAN_Read(void)
{
  testCan = piloteCAN1_messageDisponible();
  if(testCan != 0)
  {
    if(piloteCAN1_litUnMessageRecu(CanDataRecu))
    {
      if((piloteCAN1_reception.StdId & 0x0FF) == 0x001)
      {
        FlagAbort = 1;
        CanDataSend[0] = 0x41;
        CanDataRecu[0] = 0;
      }
      if((piloteCAN1_reception.StdId & 0x0FF) == 0x034)
      {
        CanDataSend[0] = CanDataRecu[0]; 
//        CanDataSend[1] = CanDataRecu[1]; 
        CanDataSend[2] = CanDataRecu[2];
        
        if(CanDataRecu[0] == 0x40)
        {
          FlagOperation = 1;
          CanDataRecu[0] = 0;
        }
        if(CanDataRecu[0] == 0x41)
        {
          FlagAbort = 1;
          CanDataRecu[0] = 0;
        }
      }
      if((piloteCAN1_reception.StdId & 0x0FF) == 0x032)
      {
        if(CanDataRecu[0] == 0x36)
        {
          FlagEnBas = 1;
          CanDataRecu[0] = 0;
        }
      }
    }
  }
}


void processusCAN_Requete_Send(void)
{
    if(TimerCanSend >= 1000)
    {
      TimerCanSend = 0;
      if(flagBoutonRougeCan == 0)
      {
        piloteCAN1_transmetDesDonnes(0x034, CanDataSend, 3);       //piloteCAN1_transmetDesDonnes(AdresseCan, CanDataSend, 3);
      }
      if(flagBoutonRougeCan == 1)
      {
        flagBoutonRougeCan = 0;
        CanDataSend[0] = 0x41;
        piloteCAN1_transmetDesDonnes(0x001, CanDataSend, 3);       //piloteCAN1_transmetDesDonnes(AdresseCan, CanDataSend, 3);
      }

    }
   TimerCanSend++;
}


//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void processusCan_initialise(void)
{
  CanDataSend[0] = 0x39;
  CanDataSend[1] = 0x60;
  CanDataSend[2] = 0x80;
  serviceBaseDeTemps_execute[PROCESSUSCAN_RECEIVE] =
      processusCAN_Read;
  
  serviceBaseDeTemps_execute[PROCESSUSCAN_SEND] =
      processusCAN_Requete_Send;
}
