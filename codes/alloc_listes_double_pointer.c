#include <stdio.h>
#include <stdlib.h>

struct date {
	int j,m,a,k,l,n,i;
};

/* README:
   DO NOT MODIFY LINE NUMBERS, USED IN CM3
*/

int main(){

//start slide here!
struct lcontigue {
	struct date ** espace; //vecteur de struct date *
	                       //alloué dynamiquement
	int dernier;
};

int n;
struct lcontigue l;
l.dernier = -1;

printf("Saisi le nb de dates : "); scanf("%d", &n);

l.espace = malloc (n * sizeof(struct date));
/* Alternative
l.espace = malloc (n * sizeof *l.espace); */

printf("\nSizeof : %lu %lu %lu %lu\n", sizeof l.espace,sizeof *l.espace, sizeof **l.espace, sizeof (struct date));
/*printf("Address : %p %d %d %p\n", l.espace,(l.espace[0]->j),((*l.espace)->j),(&l.espace));*/

printf("Date sizeof : %lu \n", sizeof (struct date));
//printf("PtDate sizeof : %lu \n", sizeof (PtDate));
printf("n sizeof : %lu : ", sizeof n); printf("%p\n", &n);
printf("l sizeof : %lu : ", sizeof l); printf("%p\n", &l);
printf("&l.espace    sizeof : %lu : ", sizeof &l.espace); printf("%p\n", &l.espace);
//printf("l.espace     sizeof : %lu : ", sizeof l.espace); printf("%p\n", l.espace);
//printf("*l.espace    sizeof : %lu : ", sizeof *l.espace); printf("%p", *l.espace);
//printf("\n*(l.espace)  sizeof : %lu : ", sizeof *(l.espace)); printf("%p", *l.espace);
printf("\n**l.espace   sizeof : %lu : ", sizeof *l.espace); //printf("%p", **l.espace);
printf("\n*(*l.espace) sizeof : %lu : ", sizeof *l.espace); //printf("%p", *(*l.espace));*/

//slide2
printf("\nAllocate:\n");
for(int i=0 ; i<n ; i++){
	l.dernier+=1;
	l.espace[l.dernier] = malloc(sizeof(struct date));
	                        //ou sizeof **l.espace
	l.espace[l.dernier]->j=i;
	l.espace[l.dernier]->m=i;
	l.espace[l.dernier]->a=i;
}
printf("\nIndice du dernier : %d\n", l.dernier);
for(int i=0 ; i<=l.dernier ; i++){
	printf("Date[%d] %d/%d/%d\n",i,
	    l.espace[i]->j, l.espace[i]->m, l.espace[i]->a);
}
for(int i=0 ; i<=l.dernier ; i++){
	free(l.espace[i]); //libère date[i]
}
free(l.espace); //libère tableau de struct date *
}
