#ifndef CARTE_LUMIERE_INTERFACE_H
#define CARTE_LUMIERE_INTERFACE_H

#include "Carte_Lumiere_Pilote.h"
#include "stdbool.h"

void vEteint_Tout(void);
void vLumiere_Rouge(bool bEtat);
void vLumiere_Jaune(bool bEtat);
void vLumiere_Verte(bool bEtat);
void vBuzzer(bool bEtat);

#endif