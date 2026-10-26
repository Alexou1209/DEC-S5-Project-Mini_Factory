
#ifndef PROCESSUSCLIGNOTE_H
#define PROCESSUSCLIGNOTE_H

//DEFINITIONS REQUISES PAR LE MODULE:
#define CLIGNOTE 1
#define REQUETETRAITEE 0
#define STOP 1
#define ON 1
#define OFF 0
//Dependances logicielles

//Fonctions publiques:
void processusClignote_initialise(void);
void processus_Clignote(void);


//Variables publiques:
extern int FlagONOFF;
extern int FlagStop;
//pas de variables publiques

#endif
