#ifndef PROCESSUSCAN_H
#define PROCESSUSCAN_H


//MODULE: ProcessusCAN
//DESCRIPTION: 


//HISTORIQUE:


//DEFINITIONS REQUISES PAR LE MODULE:


//Dependances logicielles



//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void processusCan_initialise(void);

//Variables publiques:
extern unsigned char CanDataRecu[3];
extern unsigned char CanDataSend[3];
extern int flagBoutonRougeCan;

extern int FlagOperation;
extern int FlagAbort;
extern int FlagEnBas;
//pas de variables publiques

#endif
