#include<stdio.h>
#include<stdlib.h>

#define MAX_PILE 10000

typedef unsigned char element;

typedef
struct pile_contigue {
	element espace[10000] ;
	int dernier;
}pile_contigue;

void init_pile(pile_contigue * pp) {
	pp->dernier = -1;
}

void empiler(pile_contigue * pp, int v) {
	//tester si pleine
	pp->dernier = pp->dernier + 1;
	pp->espace[pp->dernier] = v;
}

void dépiler2(pile_contigue *pp, element *v) {
}

element dépiler(pile_contigue * pp) {
	return pp->espace[pp->dernier--];
}

int sommet(pile_contigue *pp) {
	return pp->espace[pp->dernier];
}

int pile_vide(pile_contigue *pp) {
	return pp->dernier < 0;
}

int pile_pleine(pile_contigue *pp) {
	return pp->dernier == MAX_PILE -1;
}


int main() {
	pile_contigue p;
	init_pile(&p);

	empiler(&p, 45);
	if (!pile_pleine(&p))
		empiler(&p, 5);
	empiler(&p, 4);
	empiler(&p, 25);

	while(!pile_vide(&p)) {
		printf("%d\n",dépiler(&p));
	}
}
