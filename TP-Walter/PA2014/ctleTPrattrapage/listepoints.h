/*
 *  listepoints.h <METTEZ VOTRE NOM ICI>
 */

// déclaration du type Point
typedef struct {
  int abs, ord;
} Point;


// déclaration de la liste chainee 
// Déclarer ici les types : Cellule, PtCellule, Liste :
// Le type Cellule est une structure à 2 champs : val et suiv
// Le champs val est de type Point
// Les types PtCellule et Liste sont définis comme le type "pointeur de cellule"
//TODO


// retourne -1 si p1<p2, 0 si p1=p2, 1 sinon
int compare_points(Point p1, Point p2);

//ins�re un point � sa place dans la liste tri�e
void insere_point(Liste* pl, Point p);

// construit une liste de points par insertion dans la liste triee
// à partir du fichier donn� 
void construction(FILE* fp, Liste* pl);

// Affiche la liste à l'écran
void affich(Liste l);

// teste si le point p est dans la liste
int recherche (Liste l, Point p);

// Détruit la liste
void detruire (Liste* pl);
