#include<stdio.h>
#include<stdlib.h>

//#define MAX_PILE 10000

typedef int element;

typedef
struct pile_contigue {
	element * espace ;
	int dernier;
	int taille;
}pile_contigue;

void init_pile(pile_contigue * pp, int taille) {
	pp->dernier = -1;
	pp->taille = taille ;
	pp->espace = malloc(taille * sizeof(element));
}

void empiler(pile_contigue * pp, int v) {
	//tester si pleine
	pp->dernier = pp->dernier + 1;
	pp->espace[pp->dernier] = v;
}

//void dépiler2(pile_contigue *pp, element *v) {
//}

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
	return pp->dernier == pp->taille -1;
}


int main() {
	pile_contigue p2;
	init_pile(&p2, 10);

	pile_contigue p;
	init_pile(&p, 10000);

	empiler(&p, 45);
	if (!pile_pleine(&p))
		empiler(&p, 5);
	empiler(&p, 4);
	empiler(&p, 25);

	while(!pile_vide(&p)) {
		printf("%d\n",dépiler(&p));
	}
	empiler(&p2, 17);

	free(p.espace);
	free(p2.espace);
}

