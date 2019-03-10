#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 30

//Declaration de liste chainee de chaines de caracteres
typedef struct cell {
  char val[MAXSIZE];
  struct cell * suiv;
} Cellule, *Ptcellule, *Liste;

//Affichage de la liste en ligne
void afficher_liste(Liste);

//Ajout d'un mot en tete de la liste
void ajout_tete(Liste *, char *mot);

//Suppression du mot en tete de la liste
void supp_tete(Liste *);

//Ajout un mot dans une liste supposee
// triee dans l'ordre alphabetique
void ajout_alphab(Liste *, char *);

//Dit si un mot donne est dans la liste
//pas forcement triee
bool appartient(Liste ,char *);

//Donne la taille de la liste.
int taille(Liste);

//construit une liste triee a partir d'un fichier
void charge_fichier(FILE *, Liste *);

//Destruction de Liste.
void detruire_liste(Liste*);

