//PA, fichiers fournis pour le tp7.

//ajout d'un mot dans une liste chainee triee
void ajout_alphab(Liste *pl, char mot[MAXSIZE])
{
    if ( (*pl==NULL) || (strcmp(mot, (*pl)->val) < 0) ) { // empty list or mot < head => new head
        ajout_tete(pl,mot);
    }
    else
    {
        if (strcmp(mot, (*pl)->val) > 0) // mot > head => add in next's
        {
            ajout_alphab(&(*pl)->suiv,mot);
        } // else mot already in list
    }
}


//chargement à partir d'un fichier de mots. -> liste ordonnee
void charge_fichier(FILE *fp, Liste *pl)
{
    char mot[MAXSIZE];
    fscanf(fp, "%s", mot);

    while (!feof(fp))
    {
        ajout_alphab(pl,mot);
        fscanf(fp, "%s", mot);
    }
}
