#include <stdio.h>

int main() {
	printf("size data types\n");
	printf("char:        %zu\n",sizeof(char));
	printf("short:       %lu\n",sizeof(short));
	printf("int:         %lu\n",sizeof(int));
	printf("long int:    %lu\n",sizeof(long int));
	printf("float:       %lu\n",sizeof(float));
	printf("double:      %lu\n",sizeof(double));
	printf("long double: %lu\n",sizeof(long double));
	printf("void:        %lu\n",sizeof(void));

	printf("\nsize pointers\n");
	printf("char *:        %lu\n",sizeof(char *));
	printf("short *:       %lu\n",sizeof(short *));
	printf("int *:         %lu\n",sizeof(int *));
	printf("long int *:    %lu\n",sizeof(long int *));
	printf("float *:       %lu\n",sizeof(float *));
	printf("double *:      %lu\n",sizeof(double *));
	printf("long double *: %lu\n",sizeof(long double *));
	printf("void *:        %lu\n",sizeof(void *));

	return 0;
}

