/*Source Code From Laure Gonnord*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"


int main(){
  Tree mt1,mt2,mt3;
  mt1 = mkEmptyTree();
  mt2 = mkEmptyTree();

  if (isEmpty(mt1)) printf("mt1 empty\n"); 
  mt3 = cons(42,mt1,mt2);
  print_lvr(mt3);

  printf("\n -- \n");
  FILE* fp = fopen("samples/balanced.txt","r");

  Tree abr1= mkEmptyTree();

  load_tree(fp, &abr1);

  //Only values
  print_lvr(abr1);
  printf("\n -- \n");
  //father->son
  //print_rec_edges(abr1);
  printf("\n -- \n");

  return 0;
}
