#include <stdio.h>

int main() {
	FILE *fp1, *fp2;
	if ((fp1 = fopen("titi.txt", "r")) != NULL) {
		if ((fp2 = fopen("titibis.txt","w")) != NULL) {
			int c = 0; //= getc(fp1);
			int p = 0;
			while (c!=EOF && p!=EOF){ //BONNE FAÇON DE FAIRE ! Valeurs de retour
					c = getc(fp1);
					p = putc(c, fp2);
					printf("%c:%c\n",p,c);
					printf("%d:%d\n",p,c);
			}
		}
	}
	if (fp1 != NULL) fclose(fp1);
	if (fp2 != NULL) fclose(fp2);
}
