#include <stdio.h>
#include <stdlib.h>

#define TEST_VALUE 90
typedef struct TEST_ARRAY_DEF {
	int x,y;
	int test ;
	/*test = TEST_VALUE;*/
	/*const int SIZE = TEST_VALUE;//DOES NOT WORK TO INITIALIZE AN ARRAY*/
	/*int test_tableau[SIZE];*/
	struct TEST_ARRAY_DEF *tad ;
} TEST_ARRAY_DEF;

int * f() {
	int var_static ; //allocated on the stack
	return &var_static ;
}

void test_pointer_array(){
	int n; int *pt;
	n = 115 ;
	char * pt2;
	pt=&n;
	printf("\nSize of array : %d\n", n);
	printf("\nSizeofs : %lu %lu %lu %lu\n", sizeof n, sizeof &n, sizeof *pt2, sizeof pt);
	/*scanf("%d", &n);*/
	pt = (int *) malloc(n*sizeof(int));

	(*pt) = 42;
	*(pt+1) = 55;
	*(pt+2) = 66 ;
	*(pt+n-1) = 9876 ;
	printf("\nPointer to array\n");
	for (int i=0 ; i < n ; i++){
		printf("%d ", *(pt+i));
	}
	printf("\nEnd pointer to array\n");
	printf("\nPointer to array\n");
	for (int i=0 ; i < n ; i++){
		printf("%d ", pt[i]);
	}
	printf("\nEnd pointer to array\n");
}
void test_pointer_array2(){
	int n; int *pt;

	printf("\nSize of array : ");
	scanf("%d", &n);
	printf("\nScanned size : %d\n",n);
	pt = (int *) malloc(n*sizeof(int));

	printf("\nFill pointer to array\n");
	for (int i=0 ; i < n ; i++){
		printf("\nPosition: %d address: %p, value: ",i, (pt+i));
		scanf("%d", (pt+i));
		printf("Scanned:  %d", *(pt+i));
		fflush(stdout);
	}
	printf("\nEnd pointer to array\n");
	printf("\nPointer to array\n");
	for (int i=0 ; i < n ; i++){
		printf("%d ", pt[i]);
	}
	printf("\nEnd pointer to array\n");
}

/*int main(int argc, char *argv[]) {*/
int main() {

	/* Définition d'une structure */
	struct Coordonnees {
		int x,y;
	};

	/* Création d'une variable "point" de
	   type Coordonnees */
	struct Coordonnees point;

	/* Accès aux champs */
	point.x=20 ; point.y=30 ;

	/* Définition et déclaration de variables */
	struct Complexe {float reelle, imag;} c1, c2;

	/* Accès aux champs */
	c1.reelle=6 ; c1.imag=1 ;

	printf("remove warnings %f %f %d",c1.reelle, c2.reelle, point.x);

	test_pointer_array();
	test_pointer_array2();

	return 0;
}
