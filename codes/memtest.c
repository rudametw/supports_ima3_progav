#include <stdlib.h>
#include <stdio.h>

int main()
{
	int *p;
	long total = 0;
	printf("Allocating memory in 1 MiB increments\n");
	while(1)
	{
		int inc=1024*1024*sizeof(char);
		p=(int*) calloc(1,inc);

		total += inc;
		printf("Allocated %d bytes more, totaling %ld\n", inc, total);
		if(!p)
		{
			printf("NULL malloc pointer");
			 break;
		}
	}
	printf("\nTotal: %ld\n", total);
}
