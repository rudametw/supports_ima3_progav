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
	PtDate espace; /* vecteur de PtDate alloué dynamiquement */
	int dernier;
} Liste;

int n; Liste l;
l.dernier = 0;

//scanf("%d", &n);
n=10;
l.espace = malloc (n * sizeof *l.espace);

printf("\nSizeof : %lu %lu %lu %lu\n", sizeof l.espace,sizeof *l.espace, sizeof *(l.espace), sizeof (*l.espace));
printf("Address : %p %d %d %p\n", l.espace,(l.espace[0]).m,(*l.espace).a,(&l.espace));

printf("Date sizeof : %lu \n", sizeof (Date));
printf("PtDate sizeof : %lu \n", sizeof (PtDate));
printf("n sizeof : %lu : ", sizeof n); printf("%p\n", &n);
printf("l sizeof : %lu : ", sizeof l); printf("%p\n", &l);
printf("l.espace     sizeof : %lu : ", sizeof l.espace); printf("%p\n", l.espace);
printf("*l.espace    sizeof : %lu : ", sizeof *l.espace); printf("%p", &l.espace);
printf("\n*(l.espace)  sizeof : %lu : ", sizeof *(l.espace)); printf("%p", &*(l.espace));
printf("\n**l.espace   sizeof : %lu : ", sizeof *l.espace); //printf("%p", **l.espace);
printf("\n*(*l.espace) sizeof : %lu : ", sizeof *l.espace); //printf("%p", *(*l.espace));*/
printf("\n");

for(int i=0 ; i<n ; i++){
	l.espace[i].j=i;
	l.espace[i].m=i;
	l.espace[i].a=i;
}

for(int i=0 ; i<n ; i++){
	printf("Date[%d] %d/%d/%d\n", i,l.espace[i].j, l.espace[i].m, l.espace[i].a);
}
}
void print_size_and_address(){

}
