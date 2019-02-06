#include <stdio.h>

int main() {
	FILE *fp1, *fp2;
	if ((fp1 = fopen("titi.txt", "r")) != NULL) {
		if ((fp2 = fopen("titibis.txt","w")) != NULL) {
			int c = 0; //= getc(fp1);
			int p = 0;
			//while (!feof(fp1)){   //MAUVAIS FAÇON DE FAIRE!
			//		putc(c, fp2);
			//		c = getc(fp1);
			//}
			while (c!=EOF && p!=EOF){
					p = putc(c, fp2);
					c = getc(fp1);
					//printf("p:%d , c:%d\n",p,c);
			}
		}
	}
	if (fp1 != NULL) fclose(fp1);
	if (fp2 != NULL) fclose(fp2);
}
