#include <stdio.h>

typedef struct{
	char nom[30];
	int age;
} Personne;

//NEEDS TO BE FIXED. MAYBE PERSONNS FILE IS NO GOOD

int main(){
	Personne P;
	FILE * fich = fopen("personnes" ,"rb");
	if(fich!=NULL){
		int nb_a_lire = 1;
		int nb_lus = fread(&P, sizeof(Personne), nb_a_lire, fich);
		//int nb_lus = 1;
		while (nb_lus == nb_a_lire) {
			printf("xxx%s %d %d\n", P.nom, P.age, nb_lus);
			nb_lus = fread(&P, sizeof(Personne), nb_a_lire, fich);
			printf("xxx%s %d %d\n", P.nom, P.age, nb_lus);
		}
		fclose(fich);
	}
}
