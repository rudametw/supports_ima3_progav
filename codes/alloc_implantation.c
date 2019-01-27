#include <stdio.h>
#include <stdlib.h>
/* UTILISÉ DANS CM3!!!!*/
//Définition
typedef struct cellule {
	int valeur;
	struct cellule *suivant;
} Cellule;

typedef Cellule *Liste, *Ptcellule; //optionnel

void main2(){
/* liste vide */
Liste l; l = NULL;

/* accès aux champs */
Ptcellule p ; //N'oubliez pas de l'initialiser
//...
(*p).valeur;  /* ou */ p->valeur ;
(*p).suivant; /* ou */ p->suivant ;

}

//Fonction qui alloue une cellule en mémoire
Ptcellule allouer(){
	return( (Ptcellule) malloc(sizeof(Cellule)) ) ;
}

struct cellule * allouer_sans_typedef(){
	return( malloc(sizeof(struct cellule)) ) ;
}

void use_cellule(){
//Allocation d'une cellule
/*avec typedef*/ Ptcellule p2 = allouer();
/*sans*/  struct cellule * p1 = allouer_sans_typedef();

//Libération d'une cellule
free(p1);
free(p2);
}


//Rappel:  Liste ==> struct cellule *

int recherche(int x, Liste l) {
	int existe ; Ptcellule p;
	p = l;
	while ( (p != NULL) && (p->valeur != x) ) {
		p = p->suivant;
	}
	existe = (p!=NULL);
	return (existe);
}


//Rappel:  Liste * ==> struct cellule **
void ajout_tete (int x, Liste *pL){    // pL en D/R
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
	imprimer_liste(l);
}

void imprimer_liste(Liste l) {
	Ptcellule p;
	p = l;
	while ( (p != NULL) ) {
		printf ("%d -> ", p->valeur);
		p = p->suivant;
	}
	printf("\n");
	return;
}


