/*
 * Acompagnement du TP, code exemple pour vous aider.
*/

//ajout d'un mot dans une liste chainee triée
void ajout_alphab(struct cell ** pl, char * mot)
{
	// liste vide ou mot < mot prochain => ajout en tête
    if ( (*pl == NULL) || (strcmp(mot, (*pl)->val) < 0) )
    {
        ajout_tete(pl,mot);
    }
    else
    {
    	// mot > mot prochain => ajouter après dans la liste
        if (strcmp(mot, (*pl)->val) > 0)
        {
            ajout_alphab(&(*pl)->suiv,mot);
        }
        //else => mot déjà dans la liste, ne rien faire?
    }
}


//construit une liste triee a partir d'un fichier
void charge_fichier(FILE * fp, struct cell ** pl)
{
    char mot[MAXSIZE];

	//Nb d'elements à lire dans chaque fscanf
    const int NB_A_LIRE = 1;

	//`man fscanf` pour comprendre les valeurs de retour!!!
    while (fscanf(fp, "%s", mot) == NB_A_LIRE)
    {
        ajout_alphab(pl, mot);
    }

    //On peut tester la bonne ou mauvaise terminaison de la lecture
    if(feof(fp))    printf("Fin normal de lecture\n");
    if(ferror(fp))  printf("ERREUR de lecture\n");

}
