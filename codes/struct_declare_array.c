#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int j,m,a;
} Date;

/* README:
   DO NOT MODIFY LINE NUMBERS, USED IN CM3
*/

int main(){
	/*Date *pDate = (Date *) malloc(sizeof(Date));*/
	printf("Structure array\n");

	int n;
	Date *pt;
	scanf("%d", &n);
	/*pt = (Date *) malloc( n * sizeof(Date));*/
	pt = malloc(n * sizeof *pt);

	/*utilisation: notation equivalent*/
	scanf("%d%d%d", &(pt[0].j),
                  &((*(pt+0)).m),
                  &pt[0].a);
	printf("Date %d/%d/%d\n", pt[0].j, pt[0].m, pt[0].a);
	free(pt); pt = NULL;
}
