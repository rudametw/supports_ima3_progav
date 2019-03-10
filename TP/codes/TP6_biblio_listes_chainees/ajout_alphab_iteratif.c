 
void ajout_alphab(struct cell ** p, char *mot) {
    struct cell * l = *p;

    if (l == NULL) {
        ajout_tete(p, mot);
        return;
    }
    while (l->suiv != NULL && l->val < mot) {
        p = &l->suiv;
        l = l->suiv;
    }
    int ret = strcmp(l->val, mot);
    if (ret == 0) {
        return;
    } else if (ret < 0) {
        p = &l->suiv;
    }
    ajout_tete(p, mot);
}

