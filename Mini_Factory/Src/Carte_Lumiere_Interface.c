#include "Carte_Lumiere_Interface.h"
unsigned char ucValeurLum;

void vBuzzer(bool bEtat)
{
  if(bEtat == 1){ucValeurLum = ucValeurLum | 0x01;}
  else          {ucValeurLum = ucValeurLum & 0xFE;}   
  vWrite_Pin(ucValeurLum);
}

void vLumiere_Jaune(bool bEtat)
{
  if(bEtat == 1){ucValeurLum = ucValeurLum | 0x02;}
  else          {ucValeurLum = ucValeurLum & 0xFD;}   
  vWrite_Pin(ucValeurLum);
}

void vLumiere_Rouge(bool bEtat)
{
  if(bEtat == 1){ucValeurLum = ucValeurLum | 0x04;}
  else          {ucValeurLum = ucValeurLum & 0xFB;}   
  vWrite_Pin(ucValeurLum);
}

void vLumiere_Verte(bool bEtat)
{
  if(bEtat == 1){ucValeurLum = ucValeurLum | 0x08;}
  else          {ucValeurLum = ucValeurLum & 0xF7;}   
  vWrite_Pin(ucValeurLum);
}

void vEteint_Tout(void)
{
  ucValeurLum = 0x00;
  vWrite_Pin(ucValeurLum);
}