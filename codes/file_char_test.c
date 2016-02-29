#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef unsigned char mychar;
/*typedef char mychar;*/

void print_char(mychar c){
	printf("c: %c %d %x\n",c,c,c);
}

int main() {

	char *buffer = malloc(1024);

	printf("Sizeof buffer %d %d %d %d \n", sizeof(buffer), sizeof buffer, sizeof * buffer, malloc_usable_size(buffer));

	/*while ((bytes=fread(buffer, 1, sizeof(buffer), infile)) > 0)*/
    /*fwrite(buffer, 1, bytes, outfile);*/


	mychar c;

	c = 0;
	print_char(c);

	c = 126;
	print_char(c);

	c = 127;
	print_char(c);

	c = 128;
	print_char(c);

	c = 129;
	print_char(c);

	c = 220;
	print_char(c);

	c = 255;
	print_char(c);

	c = 256;
	print_char(c);

	c = 257;
	print_char(c);

	c = 258;
	print_char(c);

	for (int i = 0; i < 256; i++)
    	printf("%d:%c ", i,i);
	printf("\n");
	return 0;
}
