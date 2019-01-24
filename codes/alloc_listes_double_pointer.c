#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int j,m,a,k,l,n,i;
} Date;

/* README:
   DO NOT MODIFY LINE NUMBERS, USED IN CM3
*/

int main(){

typedef Date * PtDate;

typedef struct {
	PtDate * espace;//vecteur de PtDate alloué dynamiquement
	int dernier;
} Liste;

int n; Liste l;
l.dernier = -1;

scanf("%d", &n); //nb de pointeurs à Date

l.espace = malloc (n * sizeof *l.espace);
/* Alternative
l.espace = malloc (n * sizeof (PtDate)); */

printf("\nSizeof : %lu %lu %lu %lu\n", sizeof l.espace,sizeof *l.espace, sizeof **l.espace, sizeof (PtDate));
/*printf("Address : %p %d %d %p\n", l.espace,(l.espace[0]->j),((*l.espace)->j),(&l.espace));*/

printf("Date sizeof : %lu \n", sizeof (Date));
printf("PtDate sizeof : %lu \n", sizeof (PtDate));
printf("n sizeof : %lu : ", sizeof n); printf("%p\n", &n);
printf("l sizeof : %lu : ", sizeof l); printf("%p\n", &l);
printf("&l.espace    sizeof : %lu : ", sizeof &l.espace); printf("%p\n", &l.espace);
printf("l.espace     sizeof : %lu : ", sizeof l.espace); printf("%p\n", l.espace);
printf("*l.espace    sizeof : %lu : ", sizeof *l.espace); printf("%p", *l.espace);
printf("\n*(l.espace)  sizeof : %lu : ", sizeof *(l.espace)); printf("%p", *l.espace);
printf("\n**l.espace   sizeof : %lu : ", sizeof *l.espace); //printf("%p", **l.espace);
printf("\n*(*l.espace) sizeof : %lu : ", sizeof *l.espace); //printf("%p", *(*l.espace));*/

printf("\nAllocate:\n");
for(int i=0 ; i<n ; i++){
	l.dernier+=1;
	l.espace[l.dernier] = malloc(sizeof **l.espace);
/*l.espace[l.dernier] = malloc(sizeof(Date));*/
	l.espace[l.dernier]->j=i;
	l.espace[l.dernier]->m=i;
	l.espace[l.dernier]->a=i;
}
printf("\nIndice du dernier : %d\n", l.dernier);
for(int i=0 ; i<=l.dernier ; i++){
	printf("Date[%d] %d/%d/%d\n",i,l.espace[i]->j,
                                 l.espace[i]->m,
                                 l.espace[i]->a);
}
}
