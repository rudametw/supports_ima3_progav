#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Travailleur {
    char *nom;
    char *prenom;
    int salaire;

    void (*destroy)(struct Travailleur*);
    void (*credite_salaire)(struct Travailleur*, int);
    void (*affiche_salaire)(struct Travailleur*);
} Travailleur;

void Travailleur_Free(Travailleur* this)
{
    free(this->prenom);
    free(this->nom);
    free(this);
}

void Travailleur_init(Travailleur* this, char* prenom, char* nom)
{
    this->prenom = (char *)malloc(strlen(prenom) * sizeof(char) + 1);
    this->nom = (char *)malloc(strlen(nom) * sizeof(char) + 1);
    strcpy(this->prenom, prenom);
    strcpy(this->nom, nom);
    this->salaire = 0;
}

void Travailleur_credite_salaire(Travailleur* this, int somme)
{
    this->salaire += somme;
}

void Travailleur_affiche_salaire(Travailleur* this)
{
    printf("Le salaire de %s %s est: %d\n", this->prenom, this->nom, this->salaire);
}

Travailleur* Travailleur_New(char* prenom, char* nom)
{
    Travailleur* this = (Travailleur *)malloc(sizeof(Travailleur));
    // On init la nouvelle "instance"
    Travailleur_init(this, prenom, nom);
    this->destroy = &Travailleur_Free;
    this->credite_salaire = &Travailleur_credite_salaire;
    this->affiche_salaire = &Travailleur_affiche_salaire;
    return this;
}


int main(void)
{
    Travailleur *t1 = Travailleur_New("John", "Doe");
    t1->affiche_salaire(t1);
    t1->credite_salaire(t1, 1000);
    t1->affiche_salaire(t1);
    t1->destroy(t1);
    return 0;
}
