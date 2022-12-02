#include <stdio.h>
#include <stdlib.h>

//TODO: Convert to guard clauses, add error treatment

int main() {
	FILE *fp1, *fp2;
	if ((fp1 = fopen("titi.txt", "r")) == NULL) {
		fprintf(stderr, "Le fichier titi.txt n'est pas ouvert\n");
		//return EXIT_FAILURE ;
		exit(EXIT_FAILURE);
	}


	if ((fp2 = fopen("titibis.txt","w")) == NULL) {
		fclose(fp1);
		fprintf(stderr, "Le fichier titibis.txt n'est pas ouvert\n");
		return EXIT_FAILURE ;
	}

	printf("Tout va bien, faisons le copie\n");

	int c = 0; //= getc(fp1);
	int p = 0;
	while (c!=EOF && p!=EOF) { //BONNE FAÇON DE FAIRE !
		c = getc(fp1);
		p = putc(c, fp2);
		printf("%c:%c   |   %d:%d\n",c,p,c,p);
	}

	fclose(fp1);
	fclose(fp2);
}
