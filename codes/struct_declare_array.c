#include <stdio.h>
#include <stdlib.h>

struct date {
	int j, m, a;
};

/* README:
   DO NOT MODIFY LINE NUMBERS, USED IN CM3
*/

int main()
{
	/*Date *pDate = (Date *) malloc(sizeof(Date));*/
	printf("Structure array\n");

	int n;
	struct date *pt; // tableau !
	printf("Taille : ");
	scanf("%d", &n);
	pt = malloc(n * sizeof(struct date));
	//pt = malloc(n * sizeof *pt); // Alternative!

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &pt[i].j,
										&pt[i].m,
										&pt[i].a // ou &((*(pt+0)).a)
		);
	}
	//printf("Date %d/%d/%d\n", pt[0].j, pt[0].m, pt[0].a);
	free(pt);
	pt = NULL;
}
