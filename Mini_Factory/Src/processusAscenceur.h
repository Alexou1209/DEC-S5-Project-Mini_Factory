
#ifndef PROCESSUSASCENCEUR_H
#define PROCESSUSASCENCEUR_H


//MODULE: ProcessusPasserelleCan637
//DESCRIPTION: 


//HISTORIQUE:


//DEFINITIONS REQUISES PAR LE MODULE:
#define REQUETEPOURMONTER 1
#define REQUETEPOURDESCENDRE 2
#define REQUETETRAITEE 0
#define HAUT 1
#define BAS 1

//Dependances logicielles



//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void processusMoteur_initialise(void);
void processusAscenceur_Attends_Requete(void);
void processusAscenceur_Descends_Ascenceur(void);
void processusAscenceur_Monte_Ascenceur(void);

//Variables publiques:
extern int RequeteAscenceur;
extern int SwitchBasFlag;
extern int SwitchHautFlag;
//pas de variables publiques

#endif
