#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 30

//Declaration de liste chainee de chaines de caracteres
struct cell {
  char val[MAXSIZE];
  struct cell * suiv;
};

//OPTIONNEL: vous pouvez utiliser ces typedefs si vous voulez !
typedef struct cell   Cellule;
typedef struct cell * Liste;
typedef struct cell * ptCellule;

//Affichage de la liste en ligne
void afficher_liste(struct cell *);

//Ajout d'un mot en tete de la liste
void ajout_tete(struct cell **, char *);

//Suppression du mot en tete de la liste
void supp_tete(struct cell **);

//Ajout un mot dans une liste supposee
// triee dans l'ordre alphabetique
void ajout_alphab(struct cell **, char *);

//Dit si un mot donne est dans la liste
//pas forcement triee
bool appartient(struct cell *, char *);

//Donne la taille de la liste.
int taille(struct cell *);

//construit une liste triee a partir d'un fichier
void charge_fichier(FILE *, struct cell **);

//Destruction de Liste.
void detruire_liste(struct cell **);

