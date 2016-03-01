/*
 *  listepoints.c -  <METTEZ VOTRE NOM ICI>
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "listepoints.h"


// retourne -1 si p1<p2, 0 si p1=p2, 1 sinon
int compare_points(Point p1, Point p2){
  if (p1.abs < p2.abs) return -1;
  else if (p1.abs > p2.abs) return 1;
  else if (p1.ord < p2.ord) return -1;
  else if (p1.ord > p2.ord) return 1;
  else return 0;
}

//Implémenter ici les autres fonctions spécifiées dans listepoints.h
