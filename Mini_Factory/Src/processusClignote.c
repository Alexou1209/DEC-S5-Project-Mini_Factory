//processusAscenceur:


//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "processusClignote.h"

//Definitions privees



//Declarations de variables publiques
int FlagONOFF = 0;
int FlagStop =  0;


//Definitions de variables privees:

int Timer500ms = 0;


//Definitions de fonctions privees:

void processus_Clignote(void)
{
 
  if(Timer500ms == 1000)
  {
     Timer500ms = 0;
     if(FlagONOFF == 0){FlagONOFF = 1;}
     else              {FlagONOFF = 0;}
  }
  Timer500ms++;
}

//Definitions de fonctions publiques:
void processusClignote_initialise(void)
{

  serviceBaseDeTemps_execute[PROCESSUS_CLIGNOTE] =
      processus_Clignote;
  
}
