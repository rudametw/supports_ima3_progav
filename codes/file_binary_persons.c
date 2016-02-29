#include <stdio.h>

typedef struct{
	char nom[30];
	int age;
} Personne;

int main(){
	Personne P;
	FILE * fich = fopen("personnes" ,"rb");
	if(fich!=NULL){
		fread(&P, sizeof(Personne), 1, fich);
		while (!feof(fich)) {
			printf("%s %d\n", P.nom, P.age);
			fread(&P, sizeof(Personne), 1, fich);
		}
		fclose(fich);
	}
}
