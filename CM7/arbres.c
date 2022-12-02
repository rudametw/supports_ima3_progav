#include <stdio.h>
#include <stdlib.h>

/*
 * Slides non traités :
 *      S7 : nb_noeuds
 */


struct node {
	int val;
	struct node *gauche;
	struct node *droite;
};
//typedef struct node Node, *PtNode, *Tree; // majuscules indiquent un pointeur caché

int vide(struct node *arbre)
{
	return arbre == NULL;
}

int valeur(struct node *arbre)
{
	return arbre->val;
}

struct node *gauche(struct node *arbre)
{
	return arbre->gauche;
}

struct node *droite(struct node *arbre)
{
	return arbre->droite;
}

void init_arbre(struct node **pt_arbre)
{
	*pt_arbre = NULL;
}

void cons_arbre(struct node **pt_arbre, int v, struct node *g, struct node *d)
{
	if (*pt_arbre != NULL)
		printf("Error, going to overwrite existing node\n");

	*pt_arbre = malloc(sizeof(struct node));
	(*pt_arbre)->val = v;
	(*pt_arbre)->gauche = g;
	(*pt_arbre)->droite = d;
}

void put_valeur(struct node **pt_arbre, int v)
{
	(*pt_arbre)->val = v;
}

void put_gauche(struct node **pt_arbre, struct node *g)
{
	(*pt_arbre)->gauche = g;
}

void put_droite(struct node **pt_arbre, struct node *d)
{
	(*pt_arbre)->droite = d;
}

void print_arbre(struct node *arbre)
{
	if (vide(arbre))
		return;

	print_arbre(gauche(arbre));
	printf("%d ", arbre->val);
	print_arbre(droite(arbre));
}

void pretty_print_arbre(struct node *arbre)
{
	printf("----------\n");
	printf("Arbre : ");
	print_arbre(arbre);
	printf("\n----------\n");
}

void free_arbre(struct node *arbre)
{
	if (vide(arbre))
		return;

	free_arbre(gauche(arbre));
	free_arbre(droite(arbre));
	printf("Freeing %p\n", arbre);
	free(arbre);
}

void ajout(struct node **pt_arbre, int v)
{
	if (*pt_arbre == NULL) {
		cons_arbre(pt_arbre, v, NULL, NULL);
		return;
	}

	if (v <= (*pt_arbre)->val)
		ajout(&(*pt_arbre)->gauche, v);
	else {
		// DOESN'T WORK, CAN'T GET VARIABLE ADDRESS FOR RETURN ADDRESS
		// ajout(&(droite(*pt_arbre)), v);
		ajout(&(*pt_arbre)->droite, v);
	}
}

#ifdef REC
int existe(struct node *arbre, int v)
{
	// printf("Recursif\n");
	if (vide(arbre))
		return 0;

	if (v == arbre->val)
		return 1;

	if (v < arbre->val)
		return existe(arbre->gauche, v);
	else
		return existe(arbre->droite, v);
}
#else
int existe(struct node *node, int v)
{
	// printf("Iteratif\n");
	while (!vide(node)) {
		if (v == node->val)
			return 1;

		if (v < node->val)
			node = node->gauche;
		else
			node = node->droite;
	}

	return 0;
}
#endif

int supp_elem(struct node **parbre, int v)
{
	// printf("Recursif\n");
	if (*parbre == NULL)
		return 0;

	if (v == (*parbre)->val) {

		// on supprime la racine actuelle
		struct node *supp = *parbre;

		// si pas de sous-arbre gauche, on prend sous-arbre droite
		if ((*parbre)->gauche == NULL)
			*parbre = (*parbre)->droite; // peut valoir NULL

		// si pas de sous-arbre droite, on prend sous-arbre gauche
		else if ((*parbre)->droite == NULL)
			*parbre = (*parbre)->gauche; // peut valoir NULL

		//si on a sous-arbre droite et sous-arbre gauche, je choisi d'insérer le sous-arbre droite dans la gauche
		else {
			// pointeur qui cherche où insérer le sous-arbre droite
			struct node *tmp = (*parbre)->gauche;

			// cherche l'emplacement pour (*parbre)->droite
			while (tmp->droite != NULL)
				tmp = tmp->droite;

			// on est sur la feuille droite du sous arbre gauche, on insere ici
			tmp->droite = (*parbre)->droite;
			*parbre = (*parbre)->gauche;
		}
		free(supp);

		return 1;
	}

	if (v < (*parbre)->val)
		return supp_elem(&(*parbre)->gauche, v);
	else
		return supp_elem(&(*parbre)->droite, v);
}

void pretty_print_supp(struct node **parbre, int v)
{
	printf("%d ==> ", v);
	if (!existe(*parbre, v)) {
		printf("n'existe pas\n");
		return;
	}
	printf("%d dans l'arbre existe, on va supprimer\n", v);

	printf("supprimé ? %d\n", supp_elem(parbre, v));

	if (!existe(*parbre, v))
		printf("%d n'existe plus apparement\n", v);
	else
		printf("%d existe encore dans l'arbre\n", v);
}
void pretty_print_existe(struct node *arbre, int v)
{
	printf("%d ==> ", v);
	if (existe(arbre, v))
		printf("existe");
	else
		printf("n'existe pas");
	printf("\n");
}


int max_arbre(struct node *a)
{
	while (a->droite != NULL)
		a = a->droite;
	return a->val;
}

int max_arbre_rec(struct node *a)
{
	if (a->droite == NULL)
		return a->val;
	else
		return max_arbre_rec(a->droite);
}

int max2_arbre(struct node *a, int *max)
{
	if (a == NULL)
		return 0;

	while (a->droite != NULL)
		a = a->droite;

	*max = a->val;

	return 1;
}

int main()
{
	//struct node *arbre;
/*
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
	printf("*** ARBRE2 ***");
	printf("\n**************\n\n");
*/
	/* ARBRE 2 */
        struct node *arbre;
	arbre = NULL;
	int max = 0;
	int trouve = 0;
        init_arbre(&arbre);
	pretty_print_arbre(arbre);
	pretty_print_existe(arbre, 6);

	trouve = max2_arbre(arbre,&max);
	printf("MAXIMUM2: %d, trouvé =%d\n", max,trouve);

	ajout(&arbre, 7);

	printf("MAXIMUM : %d\n", max_arbre(arbre));
	printf("MAXIMUM_rec : %d\n", max_arbre_rec(arbre));
	trouve = max2_arbre(arbre,&max);
	printf("MAXIMUM2: %d, trouvé =%d\n", max,trouve);
	pretty_print_arbre(arbre);
	ajout(&arbre, 8);
	pretty_print_arbre(arbre);

	pretty_print_existe(arbre, 6);
	pretty_print_existe(arbre, 7);
	pretty_print_existe(arbre, 8);

	ajout(&arbre, 6);
	pretty_print_arbre(arbre);
	ajout(&arbre, 7);
	pretty_print_arbre(arbre);

	pretty_print_existe(arbre, -1);
	pretty_print_existe(arbre, 5);
	pretty_print_existe(arbre, 6);
	pretty_print_existe(arbre, 7);
	pretty_print_existe(arbre, 8);
	pretty_print_existe(arbre, 9);

	printf("MAXIMUM : %d\n", max_arbre(arbre));
	printf("MAXIMUM_rec : %d\n", max_arbre_rec(arbre));

	trouve = max2_arbre(arbre,&max);
	printf("MAXIMUM2: %d, trouvé =%d\n", max,trouve);

	printf("\nAvant suppression\n");
	pretty_print_arbre(arbre);
	pretty_print_supp(&arbre, 9);
	printf("Après suppression\n");
	pretty_print_arbre(arbre);

	printf("\nAvant suppression\n");
	pretty_print_arbre(arbre);
	pretty_print_supp(&arbre, 7);
	printf("Après suppression\n");
	pretty_print_arbre(arbre);


	printf("\nAvant suppression\n");
	pretty_print_arbre(arbre);
	pretty_print_supp(&arbre, 7);
	printf("Après suppression\n");
	pretty_print_arbre(arbre);


	printf("\nAvant suppression\n");
	pretty_print_arbre(arbre);
	pretty_print_supp(&arbre, 8);
	printf("Après suppression\n");
	pretty_print_arbre(arbre);


	printf("\nAvant suppression\n");
	pretty_print_arbre(arbre);
	pretty_print_supp(&arbre, 6);
	printf("Après suppression\n");
	pretty_print_arbre(arbre);


	printf("arbre vaut : %p\n",arbre);

	free_arbre(arbre);
	arbre = NULL;
	free_arbre(arbre);

	trouve = max2_arbre(arbre,&max);
	printf("MAXIMUM2: %d, trouvé =%d\n", max,trouve);

	return 0;
}


