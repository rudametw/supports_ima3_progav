
#include<stdio.h>
#include<stdlib.h>


struct cell {
    int valeur ;
    struct cell * suiv ;
};


void print_liste_circulaire_with_while(struct cell * liste)
{
	if (liste == NULL ) return ;

	//option 1
	struct cell * tmp = liste->suiv ;
	do {
		printf("%d\n", tmp->valeur);
	}while(tmp != liste) ;
}



void print_liste_circulaire_with_for(struct cell * liste)
{
	if (liste == NULL ) return ;

	//option 1
	//struct cell * tmp = liste->suiv ;

	printf("%d\n", liste->valeur);

	for (struct cell * tmp = liste->suiv ; tmp != liste ; tmp = tmp->suiv) {
		printf("%d\n", tmp->valeur);
	}

}

