#include <stdio.h>

int main() {
	FILE *fp1, *fp2;
	if ((fp1 = fopen("titi.txt", "r")) != NULL) {
		if ((fp2 = fopen("titibis.txt","w")) != NULL) {
			int c = 0; //= getc(fp1);
			int p = 0;
			while (c!=EOF && p!=EOF){ //BONNE FAÇON DE FAIRE !
				c = getc(fp1);
				p = putc(c, fp2);
				printf("%c:%c   |   %d:%d\n",c,p,c,p);
			}
		}
	}
	if (fp1 != NULL) fclose(fp1);
	if (fp2 != NULL) fclose(fp2);
}
