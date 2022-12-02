#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_CHAINE 30

struct cmd_pizza {
	int id;
	int nb_pizzas;
	char type_pizza[SIZE_CHAINE];
	char nom_client[SIZE_CHAINE];
	float prix;
};

struct cell {
	struct cmd_pizza cmd;
	struct cell *suiv;
};

struct cmd_pizza créer_cmd_pizza(int id, int nb_pizzas, char *type_pizza, char *nom_client, float prix)
{
	// cette cmd_pizza c éxiste dans la fonction et donc elle est stocké dans la pile d'appels !
	struct cmd_pizza c;
	c.id = id;
	c.nb_pizzas = nb_pizzas;
	strcpy(c.type_pizza, type_pizza);
	strcpy(c.nom_client, nom_client);
	c.prix = prix;
	// ↑ la nouvelle commande c est initialisé

	// on revnoie une **copie** de la commande !
	// C'est important car c est détruit à la fonction mais elle est copié avant.
	return c;
}

void print_cmd_pizza(struct cmd_pizza c)
{
	printf("\t%d | ", c.id);
	printf("%d | ", c.nb_pizzas);
	printf("%s | ", c.type_pizza);
	printf("%s | ", c.nom_client);
	printf("%.2f\n", c.prix);
}

void print_liste_cmd_pizza(struct cell *l)
{
	printf("\nCommandes de pizza :\n");
	if (l == NULL)
		printf("\tvide\n");

	while (l != NULL) {
		print_cmd_pizza(l->cmd); // encore une copie de c
		l = (*l).suiv;
	}
}

void ajout_tete(struct cell **pL, struct cmd_pizza c)
{
	struct cell *pt;
	pt = malloc(sizeof *pt);
	pt->cmd = c; // copie de la commande entière
	pt->suiv = *pL;
	*pL = pt;
}

void sup_tete(struct cell **pL)
{
	struct cell *pt;
	pt = *pL;
	*pL = (*pL)->suiv;
	free(pt);
	return;
}

void insertion_ordonnée(struct cell **pl, struct cmd_pizza c)
{
	while (*pl != NULL) {
		if ((*pl)->cmd.id > c.id)
			break;
		pl = &(*pl)->suiv;
	}
	ajout_tete(pl, c);
}

void free_liste_cmd_pizza(struct cell **pl)
{
	while (*pl != NULL) {
		struct cell *tmp = *pl;
		*pl = (*pl)->suiv;
		free(tmp);
	}
}

//Implémenter du ou 3 types de concat !
void concat_listes_cmd_pizza_merge(struct cell **pl1, struct cell **pl2)
{
}
//TD suivante :
//Recherche pour TD2
//Imprimer une liste
//Libérer une liste
//Comparer deux listes pour savoir si elles sont idéntiques
//etc. etc.

int main()
{
	// Liste de commandes de pizza
	struct cell *l = NULL;

	// Une variable qui permet de stocker différentes commandes
	struct cmd_pizza c;
	print_liste_cmd_pizza(l);
	c = créer_cmd_pizza(17, 2, "Pepperoni", "Walter", 17.32);
	insertion_ordonnée(&l, c);
	print_liste_cmd_pizza(l);
	c = créer_cmd_pizza(13, 1, "Margarita", "Pedro", 9.0);
	insertion_ordonnée(&l, c);
	print_liste_cmd_pizza(l);
	c = créer_cmd_pizza(15, 4, "Végétarien", "Maria", 7.0);
	insertion_ordonnée(&l, c);
	print_liste_cmd_pizza(l);
	c = créer_cmd_pizza(8, 1, "Montagnarde", "Julio", 10.50);
	insertion_ordonnée(&l, c);
	print_liste_cmd_pizza(l);

	//libérer la mémoire
	free_liste_cmd_pizza(&l);
	return 0;
}
