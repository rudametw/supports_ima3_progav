#include <stdio.h>

int main() {
	FILE *fp1, *fp2;
	if ((fp1 = fopen("titi.txt", "r")) != NULL) {
		if ((fp2 = fopen("titibis.txt","w")) != NULL) {
			int c = getc(fp1);
			while (!feof(fp1)){
					putc(c, fp2);
					c = getc(fp1);
			}
		}
	}
	if (fp1 != NULL) fclose(fp1);
	if (fp2 != NULL) fclose(fp2);
}
