#ifndef PILOTEIOMOTEUR_H
#define PILOTEIOMOTEUR_H

//MODULE: piloteIOMoteur
//DESCRIPTION: pour commander la sortie du moteur
//HISTORIQUE:
// 2018-09-30, Yves Roy, creation

//DEFINITIONS REQUISES PAR LE MODULE:



//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
// pas de dépendances logicielles

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void piloteIOMoteur_initialise(void);
void piloteIOMoteur1_metLaSortieA(unsigned char Valeur);
void piloteIOMoteur2_metLaSortieA(unsigned char Valeur);
void piloteIOMoteur3_metLaSortieA(unsigned char Valeur);
void piloteIOMoteur4_metLaSortieA(unsigned char Valeur);

//Variables publiques:
// pas de variables publiques

#endif
