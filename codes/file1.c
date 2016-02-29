#include <stdio.h>

int main(){
	FILE *fp = fopen("toto.txt", "r");
	if (fp == NULL) printf("toto.txt inaccessible: fp=%p\n",fp);
	else printf("toto.txt accessible: fp=%p\n",fp);

	if (fp != NULL){
		printf("Fermer toto\n");
		fclose(fp);
	}
}
