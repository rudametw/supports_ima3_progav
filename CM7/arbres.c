#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *gauche;
	struct node *droite;
} Node, *PtNode, *Tree; //majuscules indiquent un pointeur

int vide(struct node * arbre) {
	return arbre == NULL ;
}

int valeur(struct node * arbre) {
	return arbre->val ;
}

struct node * gauche(struct node * arbre) {
	return arbre->gauche ;
}

struct node * droite(struct node * arbre) {
	return arbre->droite ;
}

void init_arbre(struct node ** pt_arbre) {
	*pt_arbre = NULL ;
}

void cons_arbre(struct node ** pt_arbre,
				int v,
				struct node * g,
				struct node * d) {
	if(*pt_arbre != NULL)
		printf("Error, going to overwrite existing node\n");

	*pt_arbre = malloc(sizeof(struct node)) ;
	(*pt_arbre)->val = v;
	(*pt_arbre)->gauche = g;
	(*pt_arbre)->droite = d;
}

void put_valeur(struct node ** pt_arbre, int v) {
	(*pt_arbre)->val = v;
}

void put_gauche(struct node ** pt_arbre, struct node * g) {
	(*pt_arbre)->gauche = g;
}

void put_droite(struct node ** pt_arbre, struct node * d) {
	(*pt_arbre)->droite = d;
}

void print_arbre(struct node * arbre) {
	if (vide(arbre)) return ;

	print_arbre(gauche(arbre));
	printf("%d ",arbre->val);
	print_arbre(droite(arbre));
}
void pretty_print_arbre(struct node * arbre) {
	printf("----------\n");
	printf("Arbre : ");
	print_arbre(arbre);
	printf("\n----------\n");
}

void free_arbre(struct node * arbre) {
	if (vide(arbre)) return ;

	free_arbre(gauche(arbre));
	free_arbre(droite(arbre));
	printf("Freeing %p\n", arbre);
	free(arbre);
}

void ajout(struct node ** pt_arbre, int v) {
	if(*pt_arbre == NULL) {
		cons_arbre(pt_arbre, v, NULL, NULL);
		return;
	}

	if (v <= (*pt_arbre)->val)
		ajout(&(*pt_arbre)->gauche, v);
	else {
		// DOESN'T WORK, CAN'T GET VARIABLE ADDRESS FOR RETURN ADDRESS
		//ajout(&(droite(*pt_arbre)), v);
		ajout(&(*pt_arbre)->droite, v);
	}
}

int existe(struct node *arbre, int v) {
	if (vide(arbre)) return 0;
	if (v == arbre->val) return 1;

	if (v <= arbre->val)
		return existe(arbre->gauche, v);
	else
		return existe(arbre->droite, v);
}

void pretty_print_existe(struct node * arbre, int v) {
	printf("%d ==> ",v);
	if (existe(arbre, v))
		printf("existe");
	else
		printf("n'existe pas");
	printf("\n");
}

int main(){
	struct node * arbre ;

	init_arbre(&arbre);
	pretty_print_arbre(arbre);
	cons_arbre(&arbre, 10, NULL, NULL);
	pretty_print_arbre(arbre);
	cons_arbre(&arbre->gauche, 8, NULL, NULL);
	pretty_print_arbre(arbre);
	cons_arbre(&arbre->droite, 11, NULL, NULL);
	pretty_print_arbre(arbre);

	free_arbre(arbre);
	arbre = NULL;

	printf("\n\n**************\n");
	printf(    "*** ARBRE2 ***");
	printf(  "\n**************\n\n");

	/* ARBRE 2 */
	arbre = NULL;
	pretty_print_arbre(arbre);
	pretty_print_existe(arbre,6);
	ajout(&arbre, 7);
	pretty_print_arbre(arbre);
	ajout(&arbre, 8);
	pretty_print_arbre(arbre);

	pretty_print_existe(arbre,6);
	pretty_print_existe(arbre,7);
	pretty_print_existe(arbre,8);

	ajout(&arbre, 6);
	pretty_print_arbre(arbre);
	ajout(&arbre, 7);
	pretty_print_arbre(arbre);

	pretty_print_existe(arbre,-1);
	pretty_print_existe(arbre,5);
	pretty_print_existe(arbre,6);
	pretty_print_existe(arbre,7);
	pretty_print_existe(arbre,8);
	pretty_print_existe(arbre,9);

	free_arbre(arbre);
	arbre = NULL;
	free_arbre(arbre);

	return 0;
}
