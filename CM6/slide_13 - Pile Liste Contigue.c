#include <stdio.h>
#include <stdlib.h>


/*
 * Piles Listes contigues
 * Slide __13__.
 *
 */

//UPDATE PILE WITH PAPER SLIDE13.
//USE MALLOC INSTEAD OF FIXED ARRAY.

//slide 13 pile liste_contigue

#define MAX_PILE 1000

typedef unsigned int element;

struct pile_contigue {
    element espace[MAX_PILE] ;
    int dernier; //sommet
};

void init_pile(struct pile_contigue * pile)
{
	pile->dernier = -1;
}

int pile_vide(struct pile_contigue * pile)
{
	return pile->dernier == -1 ;
}

int pile_pleine(struct pile_contigue * pile)
{
	return pile->dernier == MAX_PILE -1;
}

element dépiler(struct pile_contigue * pile)
{
	return pile->espace[pile->dernier--];
}

void empiler(struct pile_contigue * pile, element e)
{
	pile->espace[++pile->dernier] = e ;
}

element sommet(struct pile_contigue * pile)
{
	return pile->espace[pile->dernier];
}

int main() {
    struct pile_contigue p;
    init_pile(&p);

    empiler(&p, 3);
    empiler(&p, 13);
    empiler(&p, 31);
    empiler(&p, 17);
    empiler(&p, 25);

    while(!pile_vide(&p))
        printf("%d\n", dépiler(&p));

    return 0;
}
