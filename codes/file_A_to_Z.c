#include <stdio.h>

/*typedef unsigned char mychar;*/
typedef char mychar;

void print_char(mychar c){
	printf("c: %c %d %x\n",c,c,c);
}

int main() {

	mychar c;

	for (c = 65; c < 70; c++)
    	printf("%d:%c ", c,c);
	printf("\n\n\n");

	FILE *fp1;
	if ((fp1 = fopen("file_A_to_Z.txt", "wb")) != NULL) {
		for (c = 65; c < 70; c++)
			fwrite(&c,1,1,fp1);
		long deux = 75;
		fwrite(&deux,sizeof deux,1,fp1);
		fwrite("xxx\n",1,4,fp1);
	}
	if (fp1 != NULL) fclose(fp1);

	return 0;
}
