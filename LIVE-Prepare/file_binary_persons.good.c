#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct personne{
	char nom[30];
	int age;
} Personne;

//NEEDS TO BE FIXED. MAYBE PERSONNS FILE IS NO GOOD

void read_personnes(){
	struct personne P;

	FILE * fich = fopen("personnes" ,"rb");
	if(fich!=NULL){
		int nb_a_lire = 1;
		int nb_lus = fread(&P, sizeof(Personne), nb_a_lire, fich);
		while (nb_lus == nb_a_lire) {
			printf("%s %d  nb_lus=%d\n", P.nom, P.age, nb_lus);
			nb_lus = fread(&P, sizeof(Personne), nb_a_lire, fich);
		}
		printf("Dehors boucle, nb_lus=%d\n",nb_lus);
		fclose(fich);
	}else{
		fprintf(stderr, "Erreur de lecture!!!");
	}
}

void write_personnes(){
	FILE * f = fopen("personnes" ,"wb");

	if(f==NULL) exit(EXIT_FAILURE);

	//créer un tableau de personnes
	struct personne p_tab[4] = { {"Walter Rudametkin", 75}, {"Pierre Garcia", 45}, {"Camille Sobrico", 28}, {"Alphonse Marquez", 43} };

	int nb = fwrite(&p_tab, sizeof(struct personne), (sizeof p_tab / sizeof p_tab[0]), f);

	printf("Sizeof p_tab=%ld, nb=%d\n",(sizeof p_tab / sizeof p_tab[0]), nb);
	fclose(f);
}

int main(){
	write_personnes();
	read_personnes();
}
