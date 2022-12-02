#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp1, *fp2;
	if ((fp1 = fopen("titi.txt", "r")) == NULL) {
		fprintf(stderr, "Erreur ouverture titi.txt\n");
		return EXIT_FAILURE;
	}

	if ((fp2 = fopen("titibis.txt","w")) == NULL) {
		fprintf(stderr, "Erreur ouverture titibis.txt\n");
		fclose(fp1);
		return EXIT_FAILURE;
	}
	//Les deux fichiers sont ouverts !
	int c = 0;
	int p = 0;
	while (c!=EOF && p!=EOF){
		c = getc(fp1);
		p = putc(c, fp2);
		printf("%c:%c   |   %d:%d\n",c,p,c,p);
	}
	fclose(fp1);
	fclose(fp2);
}
