#include <stdlib.h>
#include <stdio.h>

int dicho_implem (struct lcont *l, int x, int gauche, int droite) {
    int mid ;

    //clauses de garde !
    //gauche <= droit
    if (gauche > droite ) return 0;
    
    //calcul l'index du milieu
    mid = (gauche + droite) / 2;
    
    //test si on a la valeur dans espace[mid]
    if (x == l->espace[mid]) return 1 ; //condition terminaison
    
    //cas généraux
    if (x < l->espace[mid])
        return dicho(l, x, gauche, mid-1);
    else 
        return dicho(l, x, mid+1,  droite);
}
//fonction chapeau pour dicho_implem
int dicho (struct lcont *l, int x) {
       return dicho_implem(l, 5, 0, l.dernier);//initialiser valeurs du premier appel.
}

int main() {
    struct lcont liste ;
    liste.dernier = -1 ;
    
    ajout_ordonnée(&liste, 4);
    ajout_ordonnée(&liste, 17);
    ajout_ordonnée(&liste, 5);
    ajout_ordonnée(&liste, 22);
    ajout_ordonnée(&liste, 9);
    
    int existe ;
    
    existe = dicho(&liste, 5);
}


