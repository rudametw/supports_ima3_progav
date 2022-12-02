#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personne {
	char nom[28];
	int age;
};

int write_personnes() {
	printf("Fonction write_personnes\n");

	FILE *f = NULL;
	f = fopen("personnes", "wb");

	if(f == NULL) return EXIT_FAILURE; // clause de garde

	struct personne p_tab[3] = { {"Walter", 75}, {"Pierre Garcia", 22}, {"Camille", 55 } };

	printf("\t\tsizeof(struct personne)=%ld, \
		\n\t\tsizeof(p_tab)=%ld,         \
		\n\t\tsizeof(p_tab[0])=%ld,      \
		\n\t\t(sizeof p_tab / sizeof p_tab[0])=%ld\n",\
		sizeof(struct personne), sizeof(p_tab), sizeof(p_tab[0]),(sizeof p_tab / sizeof p_tab[0]));

	//int nb = fwrite(p_tab, sizeof(struct personne), 1, f);
	int nb = fwrite(&p_tab, sizeof(struct personne), (sizeof p_tab / sizeof p_tab[0]), f);
	fflush(f);//Oblige le fichier à vider son tampon en mémoire.

	printf("\tnb=%d\n",nb);

	//Utilisation des tests pour vérifier l'état du fichier avant la fermeture.
	if (feof(f)) {
		printf("\tWrite: pointer at EOF.\n");
	}

	//Les cas d'erreurs sont particulierement importants.
	if (ferror(f)) {
		printf("\tWrite: failed.\n\n");
	}else{
		printf("\tWrite: no errors detected.\n\n");
	}

	fclose(f); //Voilà, manquait le close!

	return EXIT_SUCCESS;
}

int read_personnes(){
	printf("Fonction read_personnes\n");

	struct personne p;

	FILE * fich = fopen("personnes" ,"rb");

	printf("\tRead personnes fich=%p\n",(void *) fich);
	if(fich == NULL) return EXIT_FAILURE;

	int nb_lus = fread(&p, sizeof(struct personne), 1, fich);

	while (nb_lus == 1) {
		printf("\t\t%s %d\n", p.nom, p.age);
		nb_lus = fread(&p, sizeof(struct personne), 1, fich);
	}

	//Utilisation des tests pour vérifier l'état du fichier avant la fermeture.
	if (feof(fich)) {
		printf("\tRead: pointer at EOF.\n");
	}else {
		printf("\tRead: pointer is NOT at EOF!\n");
	}

	//Les cas d'erreurs sont particulierement importants.
	if (ferror(fich)) {
		printf("\tRead: failed.\n");
	}else{
		printf("\tRead: no errors detected.\n\n");
	}
	fclose(fich);

	return EXIT_SUCCESS;
}

int main(){
	int w, r;
	w = write_personnes();
	r = read_personnes();

	if(r == EXIT_FAILURE || w == EXIT_FAILURE) {
		fprintf(stderr, "Failure, something went wrong !\n");
		return EXIT_FAILURE;
	}
	else {
		fprintf(stdout, "Program success !\n");
		return EXIT_SUCCESS;
	}
}
