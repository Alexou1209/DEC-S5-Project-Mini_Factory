#include "Triac_interface.h"

void vTriac(bool bEtat)
{
  if(bEtat == 1) {vWrite_CTRL(1);}
  else           {vWrite_CTRL(0);}
}

bool bZero_Cross(void)
{
  return bReturn_Zero_Cross();
}