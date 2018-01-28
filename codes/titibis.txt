#include <stdio.h>
#include <stdlib.h>
/* UTILISÉ DANS CM3!!!!*/
//Définition
typedef struct cellule {
	int valeur;
	struct cellule *suivant;
} Cellule;

typedef Cellule *Liste, *Ptcellule;

void main2(){
/* liste vide */
Liste l; l = NULL;

/* accès aux champs */
Ptcellule p ; //N'oubliez pas de l'initialiser
//...
(*p).valeur;  /* ou */ p->valeur ;
(*p).suivant; /* ou */ p->suivant ;

}

//Fonction pour allouer des Cellules
Ptcellule allouer2(){
	return( malloc(sizeof(Cellule)) ) ;
}

//Fonction qui alloue une cellule en mémoire
Ptcellule allouer(){
	return( (Ptcellule) malloc(sizeof(Cellule)) ) ;
}

void use_cellule(){
//Allocation d'une cellule
Ptcellule p = allouer();

//Libération d'une cellule
free(p);
}



//Exemple
int recherche(int x, Liste l) {
	int existe ; Ptcellule p;
	p = l;
	while ( (p != NULL) && (p->valeur != x) ) {
		p = p->suivant;
	}
	existe = (p!=NULL);
	return (existe);
}



void ajout_tete (int x, Liste *pL){
	/* pL en D/R */
	Ptcellule p;
	p = allouer();
	p->valeur = x;
	p->suivant = *pL;
	*pL = p;
}
int main(){
	int x ; Liste l=NULL;
	scanf("%d", &x);
	while (x > 0) {
		ajout_tete(x, &l);
		scanf("%d", &x);
	}
}
