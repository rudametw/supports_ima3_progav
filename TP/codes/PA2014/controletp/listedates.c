/*
 *  listedates.c -  <METTEZ VOTRE NOM ICI>
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "listedates.h"



// retourne -1 si d1<d2, 0 si d1=d2, 1 sinon
int compare_dates(Date d1 ,Date d2){
  if (d1.aa < d2.aa) return -1;
  else if (d1.aa > d2.aa) return 1;
  else if (d1.mm < d2.mm) return -1;
  else if (d1.mm > d2.mm) return 1;
  else if (d1.jj < d2.jj) return -1;
  else if (d2.jj > d1.jj) return 1;
  else return 0;
}

//Implémenter ici les autres fonctions spécifiées dans listedates.h
