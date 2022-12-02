#include<stdlib.h>

/*
 * Dummy head linked list.
 * Slide 2.
 *
 */

struct cell {
    int valeur ;
    struct cell * suiv ;
};

void ajout_tete(struct cell ** pL, int x) {
    struct cell * pt;
    pt = malloc(sizeof *pt);
    pt->valeur = x;
    pt->suiv = *pL;
    *pL = pt;
}

void ajout_tete_dummy_head(struct cell * liste, int x) {
    struct cell * pt;
    pt = malloc(sizeof *pt);
    pt->valeur = x;
    pt->suiv = liste->suiv;
    liste->suiv = pt;
}

int find_and_delete_without_dummy_head(struct cell ** pL, int x) {

    if (*pL == NULL ) return 0 ;

    if ( (*pL)->valeur == x) {
        struct cell * tmp = *pL ;
        *pL = (*pL)->suiv ;
        free(tmp);
        return 1 ;
    }

    struct cell * p ;
    p = *pL ;

    while(p->suiv != NULL) {
        if(p->suiv->valeur == x) {
            struct cell * tmp = p->suiv ;
            p->suiv = p->suiv->suiv ;
            free(tmp);
            return 1 ;
        }
        p = p->suiv ;
    }
    return 0;
}


int find_and_delete_with_dummy_head(struct cell * liste, int x) {

    struct cell * p = liste ;

    while(p->suiv != NULL) {
        if(p->suiv->valeur == x) {
            struct cell * tmp = p->suiv ;
            p->suiv = p->suiv->suiv ;
            free(tmp);
            return 1 ;
        }
        p = p->suiv ;
    }
    return 0;
}
