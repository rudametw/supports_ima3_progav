#include <stdio.h>
#include <stdlib.h>

struct date {
	int j,m,a;
};

int main(){
	struct date * pDate = malloc(sizeof *pDate);

	printf("sizeof Date:%lu | sizeof *pDate:%lu\n",
						sizeof(struct date), sizeof *pDate);

	/*example d'utilisation :*/
	scanf("%d%d%d",&(pDate->j),
				   &(pDate->m),
				   &(pDate->a));

	printf("Date %d/%d/%d\n", pDate->j,
							  pDate->m,
							  pDate->a);
	free(pDate);
	pDate = NULL;
}
