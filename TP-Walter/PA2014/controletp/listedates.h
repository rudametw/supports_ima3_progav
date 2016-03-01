/*
 *  listedates.h <METTEZ VOTRE NOM ICI>
 */

// déclaration du type Date
typedef struct {
  int jj,mm,aa;
} Date;


// déclaration de la liste chainee 
// Déclarer ici les types : Cellule, PtCellule, Liste :
// Le type Cellule est une structure à 2 champs : val et suiv
// Le champs val est de type Date
// Les types PtCellule et Liste sont définis comme le type "pointeur de cellule"
//TODO

// retourne -1 si d1<d2, 0 si d1=d2, 1 sinon
int compare_dates(Date d1 ,Date d2);

//ajoute une date en tête de la liste
void ajout_tete(Liste* pl, Date d);

// construit une liste de dates par simple AJOUT EN TETE 
// à partir du fichier donné (on ne demande pas de construire une liste triée)
void construction(FILE* fp, Liste* pl);

// Affiche la liste à l'écran
void affich(Liste l);

//teste si la liste est triée par ordre croissant sur les dates. 
// retourne 1 si la liste est triée, 0 sinon
int liste_triee(Liste l);

// Détruit la liste
void detruire (Liste* pl);
