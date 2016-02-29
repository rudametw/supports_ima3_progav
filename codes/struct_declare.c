#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int j,m,a;
} Date;

int main(){
	/*Date *pDate = (Date *) malloc(sizeof(Date));*/
	Date *pDate = malloc(sizeof *pDate);

	printf("sizeof Date:%lu | sizeof *pDate:%lu\n",
								sizeof(Date), sizeof *pDate);

	/*ex. utilisation :*/
	scanf("%d%d%d",&(pDate->j),
				   &(pDate->m),
				   &(pDate->a));

	printf("Date %d/%d/%d\n", pDate->j,
							  pDate->m,
							  pDate->a);
	free(pDate); pDate = NULL;
}
