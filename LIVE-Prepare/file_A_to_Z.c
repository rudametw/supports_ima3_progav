#include <stdio.h>

/*typedef unsigned char mychar;*/
typedef char mychar;

void print_char(mychar c){
	printf("c: %c %d %x\n",c,c,c);
}

int main() {

	mychar c;
	unsigned long huit_bytes ;

	for (c = 65; c < 95; c++){
        	printf("%d:%c ", c,c);
	}
	printf("\n\n\n");

	FILE *fp1;
	if ((fp1 = fopen("file_A_to_Z.dat", "w+")) != NULL) {
		for (c = 65; c < 95; c++)
			fwrite(&c,1,1,fp1);
		/*fseek(fp1,0,SEEK_SET);*/
		/*long deux = 75;*/
		huit_bytes = 16705; //Ajoute deux A (01000001)
		huit_bytes = 02024050120240501; //Ajoute deux 5
		huit_bytes = 1094795585 ; //Équivalent 4xA
		huit_bytes = 0x4141414141414141 ; //Équivalent 8xA
		printf("Variable huit_bytes prends %lu bytes en mémoire with value %ld %lx \n",sizeof huit_bytes, huit_bytes, huit_bytes);
		fwrite(&huit_bytes,sizeof huit_bytes,1,fp1);
		fwrite("xxx\n",1,4,fp1);
	}
	if (fp1 != NULL) fclose(fp1);

	return 0;
}
