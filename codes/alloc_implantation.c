#include <stdio.h>
#include <stdlib.h>
/* UTILISÉ DANS CM3!!!!*/

//Définition
struct cellule {
	int valeur;
	struct cellule *suivant;
};


void main2(){
/* liste vide */
struct cellule * l;
l = NULL;

/* accès aux champs */
struct cellule * p  = NULL; //N'oubliez pas de l'initialiser
p = malloc(sizeof(struct cellule));
(*p).valeur  = 17;   /* ou */ p->valeur  = 17 ;
(*p).suivant = NULL; /* ou */ p->suivant = NULL;
}

//Fonction qui alloue une cellule en mémoire
struct cellule * allouer(){
	return( (struct cellule *) malloc(sizeof(struct cellule)) ) ;
}

struct cellule * allouer_sans_typedef_ni_cast(){
	return( malloc(sizeof(struct cellule)) ) ;
}

void use_cellule(){
//Allocation d'une cellule
/*avec typedef*/ struct cellule * p2 = allouer();
/*sans*/  struct cellule * p1 = allouer_sans_typedef_ni_cast();

//Allocation et liason manuel de deux cellules
struct cellule * pc1 = malloc(sizeof(struct cellule));
struct cellule * pc2 = malloc(sizeof(struct cellule));

pc1->valeur = 6;
pc2->valeur = 9;

pc1->suivant = pc2;
pc2->suivant = NULL;

//Libération de deux cellules
free(pc1);
free(pc2);
}

//Rappel:  une liste ==> struct cellule *

//Recherche avec un drapeau booléen
int recherche_bool(struct cellule * l, int x) {
	int existe ;
	struct cellule * p;
	p = l;

	while ( (p != NULL) && (p->valeur != x) ) {
		p = p->suivant;
	}

	existe = (p!=NULL);
	return (existe);
}

//Recherche avec un return (meilleur IMHO)
int recherche_return(struct cellule * l, int x) {

	struct cellule * p;
	p = l;

	while (p != NULL){
		if (p->valeur == x)
			return 1; //trouvé
		p = p->suivant;
	}

	return 0; //fini le parcours, pas trouvé
}

//Rappel:  pointeur vers une liste ==> struct cellule **
void ajout_tete (struct cellule **pL, int x){    // pL en D/R
	struct cellule * tmp;
	tmp = malloc(sizeof(struct cellule));
	tmp->valeur = x;
	tmp->suivant = *pL;
	*pL = tmp;
}

//Rappel:  une liste ==> struct cellule *
void imprimer_liste(struct cellule * l) {
	struct cellule * p;
	p = l;
	while (p != NULL) {
		printf ("%d -> ", p->valeur);
		p = p->suivant;
	}
	printf("\n");
	return;
}

void free_liste2(struct cellule ** pl) {
	while (*pl != NULL) {
		struct cellule *p;
		p = *pl;
		pl=&(*pl)->suivant;
		free(p);
	}
	return;
}

void sup_tete(struct cellule ** pl) {
	struct cellule *p;
	p = *pl;
	*pl=(*pl)->suivant;
	free(p);
}
void free_liste(struct cellule ** pl) {
	while (*pl != NULL) {
		sup_tete(pl);
	}
}

int main(){
	struct cellule * l=NULL;

	int x=1 ;
	while (x > 0) { //lisez un 0 pour sortir
		printf("Insert : ");
		scanf("%d", &x);
		ajout_tete(&l, x);
	}

	imprimer_liste(l);
	printf("Rech b : %d\n", recherche_bool(l,6));
	printf("Rech r : %d\n", recherche_return(l,6));
	free_liste(&l); //VOUS SAURIEZ FAIRE ?
}

