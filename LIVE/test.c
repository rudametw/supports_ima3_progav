
#include<stdio.h>
#include<stdlib.h>


//typedef struct personne mon_type;

struct cell {
	int valeur ;
	struct cell * suiv ;
};

typedef struct cell * pile;


void init_pile(pile * pp) {
	*pp = NULL;
}


void ajout_tete(struct cell ** pL, int x) {
	struct cell * pt;
	pt = malloc(sizeof *pt);
	pt->valeur = x;
	pt->suiv = *pL;
	*pL = pt;
}

void sup_tete(struct cell ** pL){
	struct cell * pt;
	pt = *pL ;
	*pL = (*pL)->suiv ;
	free(pt);
	return ;
}


void empiler(pile * pp, int v) {
	ajout_tete(pp, v);
}

void dépiler2(pile *pp, int *v) {
	//pas testé si la pile est vide !!!
	*v = (*pp)->valeur ;
	sup_tete(pp) ;
}


int dépiler(pile * pp) {
	//pas testé si la pile est vide !!!
	int v = (*pp)->valeur ;
	sup_tete(pp) ;
	return v;
}

int sommet(pile p) {
	//pas testé si la pile est vide !!!
	int v = p->valeur ;
	return v;
}

int pile_vide(pile p) {

	//if (p == NULL) return 1;
	//else return 0;

	return p == NULL;
}

int pile_pleine(pile p) {
	return 0;
}


int main(){
	pile p;
	init_pile(&p);

	empiler(&p, 45);
	empiler(&p, 5);
	empiler(&p, 4);
	empiler(&p, 25);

	int t;
	t = dépiler(&p);
	//dépiler2(&p, &t);

	printf("%d\n", t);

	while (!pile_vide(p)) {
		printf("%d\n", dépiler(&p));
	}
}


int test(void){
	// This is a test... please work:
}
