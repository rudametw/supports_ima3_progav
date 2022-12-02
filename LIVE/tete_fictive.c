#include<stdio.h>
#include<stdlib.h>

struct cell {
    int valeur ;
    struct cell * suiv ;
};


int suppression_lchainee(struct cell ** pL, int x) {

	if (*pL == NULL) return 0;

	if ( (*pL)->valeur == x) {
		struct cell * tmp = *pL;
		*pL = (*pL)->suiv ;
		free(tmp);
		return 1;
	}


	struct cell *tmp;
	tmp = *pL;

	while(tmp->suiv != NULL) {
		if(tmp->suiv->valeur == x) {
			struct cell * p = tmp->suiv ;
			tmp->suiv = tmp->suiv->suiv;
			free(p);
			return 1;
		}
		tmp = tmp->suiv;
	}
	//cas où x n'est pas dans la liste chainée.
	return 0;
}


int suppression_lchainee_tete_fictive(struct cell * l, int x) {

	struct cell *tmp;
	tmp = l;

	while(tmp->suiv != NULL) {
		if(tmp->suiv->valeur == x) {
			struct cell * p = tmp->suiv ;
			tmp->suiv = tmp->suiv->suiv;
			free(p);
			return 1;
		}
		tmp = tmp->suiv;
	}
	//cas où x n'est pas dans la liste chainée.
	return 0;
}

struct cell {
    int valeur ;
    struct cell * suiv ;
};
