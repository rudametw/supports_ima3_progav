#include <stdio.h>

int main(void) {
  int i; /* nbre lu */
  float somme = 0.0; /* la somme des nombres lus */
  int nbre=0; /* le nombre d'entiers lus */
  while (scanf("%d", &i) != EOF) {
    nbre = nbre+1;
    somme = somme+i;
  }
  /* impression de la moyenne */
  printf("la moyenne est : %.2f\n", somme/nbre);
  return 0;
}
