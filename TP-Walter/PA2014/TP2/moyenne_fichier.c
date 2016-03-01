/*Source code from B. Carre modif by Laure Gonnord*/
/*Calcule la moyenne des entiers lus dans le fichier "entiers.txt"*/

/*compilation : gcc -o moyenne_fichier moyenne_fichier.c -Wall

/*utilisation ./moyenne_fichier */

#include <stdio.h> 

int main(void) {
  int i; /* nbre lu */
  float somme=0.0; /* la somme des nombres lus */
  int nbre=0; /* le nombre d'entiers lus */

  FILE* fd ;
  fd = fopen("entiers.txt","r"); // ouverture en lecture
  if (fd!=NULL) {
    //fichier ouvert avec succes !
    fscanf(fd,"%d", &i);
    while (!feof(fd)) {//feof APRES la premiere lecture.
      nbre=nbre+1;
      somme=somme+i;
      fscanf(fd,"%d", &i);
    }
    /*impression de la moyenne*/
    printf("la moyenne est : %f\n", somme/nbre);
    fclose(fd);//fermeture
  }

  return 0;
}
