#include <stdio.h>
#include <stdlib.h>


struct node {
	int val;
	struct node *gauche;
	struct node *droite;
};

void init_arbre(struct node **ptr_arbre) {
	*ptr_arbre = NULL;
}

int vide(struct node *arbre) {
	return arbre == NULL;
}

void cons_arbre(struct node **parbre, int v, struct node *g, struct node *d)
{
	*parbre = malloc(sizeof(struct node));

	if (*parbre == NULL)
		exit(EXIT_FAILURE);

	(*parbre)->val = v;
	(*parbre)->gauche = g;
	(*parbre)->droite = d;
}

void ajout(struct node **parbre, int v)
{
	if (*parbre == NULL) {
		cons_arbre(parbre, v, NULL, NULL);
		return;
	}
	if (v <= (*parbre)->val)
		ajout(&((*parbre)->gauche), v);
	else
		ajout(&((*parbre)->droite), v);
}

int existe(struct node *arbre, int v)
{
	if (vide(arbre))
		return 0;

	if (v == arbre->val)
		return 1;

	if (v < arbre->val)
		return existe(arbre->gauche, v);
	else
		return existe(arbre->droite, v);
}

int existe_iteratif(struct node *arbre, int v)
{
	// printf("Iteratif\n");
	while (!vide(arbre)) {
		if (v == arbre->val)
			return 1;

		if (v < arbre->val)
			arbre = arbre->gauche;
		else
			arbre = arbre->droite;
	}

	return 0;
}
void free_arbre(struct node *arbre)
{
	if (vide(arbre))
		return;

	// GDR
	free_arbre(arbre->gauche);
	free_arbre(arbre->droite);
	free(arbre); // inverse du malloc
	return;
}

int main(void)
{
	struct node *arbre;
	init_arbre(&arbre);
	printf("vide ? : %d\n", vide(arbre));
	ajout(&arbre, 42);
	ajout(&arbre, 30);
	ajout(&arbre, 55);
	ajout(&arbre, 56);
	int e = existe(arbre, 30);
}
