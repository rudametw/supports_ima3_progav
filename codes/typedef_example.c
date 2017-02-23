#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct S { int x; };
typedef struct S S;

void f(struct S argument) { // struct is required here
	printf("F1 Argument.x: %d\n",argument.x);
}
void f2(S argument) { // struct keyword no longer needed
	printf("F2 Argument.x: %d\n",argument.x);
}

void copyCharArrays(){
	char array1[18] = {"abcdefg"};
	char array2[18];

	size_t destination_size = sizeof (array2);

	strncpy(array2, array1, destination_size);
	array2[destination_size - 1] = '\0';
}

int printArrayAddresses(){
  char buf[1];
  printf("&buf     == %p\n", &buf);
  printf(" buf     == %p\n",  buf);  // 'buf' implicitly converted to pointer
  printf("&buf[0]  == %p\n", &buf[0]);

  char* mbuf = buf;
  printf(" mbuf    == %p\n",  mbuf);
  printf(" mbuf    == %p Pointer's address\n", &mbuf);
  printf("&mbuf[0] == %p\n", &mbuf[0]);

  printf("\n&mbuf(%p) != &buf(%p)\n", &mbuf, &buf);

  return 0;
}


int testint[5] = {1, 2, 3, 4, 5};

#define SIZE 55
typedef struct {
    int numero;
    char titre[SIZE];
    char * titre2;
} Ouvrage;

typedef struct {int jour, mois, annee;} Date;      /* option 2 */
typedef struct Date2 {int jour, mois, annee;} Date2; /* option 1 */

void structureImbriques() {
	typedef struct Fiche {
		Ouvrage emprunt ;
		Date date ;
	} Fiche ;

	/*Ouvrage e = {23, {"Pott"}, "Test"};*/
	//Fiche f = {{23,"H. Potter", "Test"}, {12,5,2006} }
	Fiche f = {{23,"H. Potter", "Test"}, {12,5,2006} };

	Fiche tableau_fiches [3] = {
			{{23,"H. Potter"}, {15,7,2006}},
			{{30,"Hamlet"}, {12,5,2006}},
			{{35,"Don Quichotte"}, {12,5,2006}}
	};
	Fiche tableau_fiches2[3];
	Fiche f1,f2,f3; Ouvrage o1,o2,o3; Date d1,d2,d3;
	//F1
	d1.jour=12 ; d1.mois=5; d1.annee=2006;
	o1.numero=23; strcpy(o1.titre,"H. Potter");
	f1.emprunt=o1; f1.date=d1;
	//F2
	f2 = (Fiche) {{23,"H. Potter"}, {15,7,2006}};//À partir de C99
	//F3
	f3 = (Fiche) {{30,"Hamlet"}, {12,5,2006}};
	tableau_fiches2[0]=f1; tableau_fiches2[1]=f2;	tableau_fiches2[2]=f3;
			/*{{30,"Hamlet"}, {12,5,2006}},*/
			/*{{35,"Don Quichotte"}, {12,5,2006}}*/
	/*};*/

	printf("\n%s\n", tableau_fiches[2].emprunt.titre);
}


void testOuvrage(){
	/*char *str = "string";*/
	/*printf("%s This next instruction will segfault...", str);*/
	/*str[0] = 'z';*/ //cannot modify string literal which is stored in read only memory
	/*printf("%s", str);*/

	Ouvrage x = {23,"12345"};
	Ouvrage y ;

	printf("\n\nTest char array copies:\n");
	printf("\nTitreX:%s   sizeof:%lu",x.titre, strlen(x.titre));
	printf("\nTitreY:%s   sizeof:%lu\n\n",y.titre, strlen(y.titre));
	strncpy(y.titre, x.titre, 10);
	/*strcpy(y.titre, "XX3456789012345678901234567890123456789012345678901");//one more character crashes this!*/
	//y.titre[SIZE] = '\0';
	printf("\nTest char pointer copies:\n");
	printf("\nTitreX:%s   sizeof:%lu",x.titre, strlen(x.titre));
	printf("\nTitreY:%s   sizeof:%lu\n\n",y.titre, strlen(y.titre));
	strncpy(y.titre, x.titre, 10);
	/*strcpy(y.titre, "XX3456789012345678901234567890123456789012345678901");//one more character crashes this!*/
	//y.titre[SIZE] = '\0';
	//x.titre2 = "Los lobos cantan";
	char * titre_tmp = "Los lobos cantan";//string literal cannot be changed. You can also put into array so you can change it!!!!
	char titre_tmp2 [] = "Los lobos cantan";//can be changed because in array
	/*titre_tmp[2] = '$';*/ //causes segfault
	titre_tmp2[2] = '$';
	printf("titre_tmp:%s\n",titre_tmp);
	printf("titre_tmp2:%s\n",titre_tmp2);
	printf("size of string literal: %lu\n",sizeof (titre_tmp2));//can't sizeof titre_tmp cause it's a pointer, could use strlen though!
	x.titre2 = malloc(sizeof (titre_tmp2));//makes memory zone modifiable!
	strncpy(x.titre2,titre_tmp2,sizeof(titre_tmp2));


	char test[4] = "Test";//problem, not null terminated!
	printf("Test:%s   sizeof:%lu strlen:%d\n\n",test, sizeof(test),strlen(test));
	/*test[4] = '\0';*/

	y = x;//works too
	/*y.titre2 = x.titre;//works*/
	/*y.titre2 = x.titre2;//works too*/
	printf("\nTitreX:%s   sizeof:%lu",x.titre, strlen(x.titre));
	printf("\nTitreY:%s   sizeof:%lu\n",y.titre, strlen(y.titre));
	printf("Titre2X:%s   sizeof:%lu strlen:%lu\n",x.titre2, sizeof(x.titre2),strlen(x.titre2));
	printf("Titre2Y:%s   sizeof:%lu strlen:%lu\n",y.titre2, sizeof(y.titre2),strlen(y.titre2));

	Ouvrage z; z = x;
	printf("\nTitreZ:%s   sizeof:%lu\n",z.titre, strlen(z.titre));
	printf("Titre2Z:%s   sizeof:%lu strlen:%lu\n",z.titre2, sizeof(z.titre2),strlen(z.titre2));
	printf("Arrays ↓ Ouvrage.titre Pointers ↓ Ouvrage.titre2 \
			\nXt1:%p     Xt2:%p \
			\nYt1:%p     Yt2:%p \
			\nZt1:%p     Zt2:%p\n",&x.titre[0],&x.titre2[0],y.titre,x.titre2,z.titre,z.titre2);

	z.titre[0]  = 'Z' ;
	*z.titre2 = 'Z' ;
	printf("\nTitreX:%s   sizeof:%lu",x.titre, strlen(x.titre));
	printf("\nTitreY:%s   sizeof:%lu\n",y.titre, strlen(y.titre));
	printf("TitreZ:%s   sizeof:%lu\n",z.titre, strlen(z.titre));
	printf("Titre2X:%s   sizeof:%lu strlen:%lu\n",x.titre2, sizeof(x.titre2),strlen(x.titre2));
	printf("Titre2Y:%s   sizeof:%lu strlen:%lu\n",y.titre2, sizeof(y.titre2),strlen(y.titre2));
	printf("Titre2Z:%s   sizeof:%lu strlen:%lu\n",z.titre2, sizeof(z.titre2),strlen(z.titre2));

	free(x.titre2);

	return;

	int * testintptr = testint; //valid!!!
	printf("\nsizeof testint (gives size in bytes!): %lu\n", sizeof testint);
	for (int i = 0 ; i < sizeof(testint)/sizeof(testint[0]) ; i++) {
		printf("%d ",*(testintptr+i));
	}
	printf("\n\n");

	printArrayAddresses();

}


void copyStructsWithArray(){
	struct Sarray {
		int p[3];
	};
	struct Sarray sa1, sa2;
	sa1.p[0] = 10; sa1.p[1] = 20; sa1.p[2] = 30;

	printf("Sarray...\n");
	printf("pointer array sa1.p:%p, sa1.p[0]:%p\n",&sa1.p, &sa1.p[0]);
	printf("pointer array sa2.p:%p, sa2.p[0]:%p\n",&sa2.p, &sa2.p[0]);
	printf("values sa1.p: %d, %d, %d\n",sa1.p[0],sa1.p[1],sa1.p[2]);
	printf("values sa2.p: %d, %d, %d\n",sa2.p[0],sa2.p[1],sa2.p[2]);
	sa2 = sa1;
	printf("pointer array sa1.p:%p, sa1.p[0]:%p\n",&sa1.p, &sa1.p[0]);
	printf("pointer array sa2.p:%p, sa2.p[0]:%p\n",&sa2.p, &sa2.p[0]);
	printf("values sa1.p: %d, %d, %d\n",sa1.p[0],sa1.p[1],sa1.p[2]);
	printf("values sa2.p: %d, %d, %d\n",sa2.p[0],sa2.p[1],sa2.p[2]);

	//OR
	struct Spointer {
		int * p;
	};
	struct Spointer sp1, sp2;
	sp1.p = malloc(3*sizeof (*sp1.p)); printf("***** Pointer vs pointee sizes : %lu %lu", sizeof (sp1.p), sizeof (*sp1.p));
	sp1.p[0] = 10;
	sp1.p[1] = 20;
	sp1.p[2] = 30;

	printf("\nSpointer...\n");
	/*printf("pointer sizes sp1:%lu, sp2:%lu\n",sizeof sp1.p, sizeof sp2.p);*/
	printf("pointer array sp1.p:%p, sp1.p[0]:%p\n",&sp1.p, &sp1.p[0]);
	printf("pointer array sp2.p:%p, sp2.p[0]:%p\n",&sp2.p, &sp2.p[0]);
	printf("values sp1.p: %d, %d, %d\n",sp1.p[0],sp1.p[1],sp1.p[2]);
	//segfaults
	//printf("values sp2.p: %d, %d, %d\n",sp2.p[0],sp2.p[1],sp2.p[2]);
	sp2 = sp1;
	printf("pointer array sp1.p:%p, sp1.p[0]:%p\n",&sp1.p, &sp1.p[0]);
	printf("pointer array sp1.p:%p, sp1.p[0]:%p\n",&sp1.p, sp1.p);
	printf("pointer array sp2.p:%p, sp2.p[0]:%p\n",&sp2.p, &sp2.p[0]);
	printf("pointer array sp2.p:%p, sp2.p[0]:%p\n",&sp2.p, sp2.p);
	printf("values sp1.p: %d, %d, %d\n",sp1.p[0],sp1.p[1],sp1.p[2]);
	printf("values sp2.p: %d, %d, %d\n",sp2.p[0],sp2.p[1],sp2.p[2]);
	/*printf("pointer sizes sp1:%lu, sp2:%lu\n",sizeof *sp1.p, sizeof sp2.p);*/

	free(sp1.p);
	printf("pointer array sp1.p:%p, sp1.p[0]:%p\n",&sp1.p, &sp1.p[0]);
	printf("pointer array sp1.p:%p, sp1.p[0]:%p\n",&sp1.p, sp1.p);
	printf("pointer array sp2.p:%p, sp2.p[0]:%p\n",&sp2.p, &sp2.p[0]);
	printf("pointer array sp2.p:%p, sp2.p[0]:%p\n",&sp2.p, sp2.p);
	printf("values sp1.p: %d, %d, %d\n",sp1.p[0],sp1.p[1],sp1.p[2]);
	printf("values sp2.p: %d, %d, %d\n",sp2.p[0],sp2.p[1],sp2.p[2]);
}

int main(int argc, char *argv[]) {
	Date d1 = {18,5,2012} ; Date d2 = {24,12,2015}; /* variables */
	printf("size dates: %lu, %lu\n",sizeof(Date), sizeof (Date2)); /* taille de la structure Date = 3*sizeof(int) */
	printf("size d1 d2: %lu, %lu\n",sizeof(d1), sizeof (d2));
	printf("d1 d2: %d, %d\n",d2,d1);
	printf("d1: %d, %d, %d\n",d1.jour, d1.mois, d1.annee);
	printf("d2: %d, %d, %d\n",d2.jour, d2.mois, d2.annee);

	Date tmp ; tmp = d1 ; d1 = d2 ; d2 = tmp ;
	printf("d1: %d, %d, %d\n",d1.jour, d1.mois, d1.annee);
	printf("d2: %d, %d, %d\n",d2.jour, d2.mois, d2.annee);

	char string1[] = "test";
	char *string2 = &string1[0] ;
	char *string3 = "hola" ;
	//char string4[] = "qsdf" ;
	printf("Strings: %s:%s\n",string1, string2);
	string2[0] = 'x';
	*(string2+1) = 'y';
	printf("Strings: %s:%s\n",string1, string2);


	char str[] = "Hello0"; /* sizeof == 7, Explicit + Implicit NUL */
	char str1[] = "Hello1\0"; /* sizeof == 7, Explicit + Implicit NUL */
	char str2[5]= "Hello2"; /* sizeof == 5, str is "Hello" with no NUL (no longer a C-string, just an array of char). This may trigger compiler warning */
	char str22[5]= "HelloX\0"; /* sizeof == 5, str is "Hello" with no NUL (no longer a C-string, just an array of char). This may trigger compiler warning */
	printf("Hello Strings: %s:%lu, %s:%lu, %s:%lu, %s:%lu\n",str, sizeof str, str1, sizeof str1, str2, sizeof str2, str22, sizeof str22);//initializing an array with a string that's too long is accepted, extra characters are ignored!
	char str3[6]= "Hello3\0"; /* sizeof == 6, Explicit NUL only */
	char str4[7]= "Hello4\0"; /* sizeof == 7, Explicit + Implicit NUL */
	char str5[8]= "Hello5\0"; /* sizeof == 8, Explicit + two Implicit NUL */

	printf("Hello Strings: %s:%lu, %s:%lu, %s:%lu, %s:%lu, %s:%lu, %s:%lu, %s:%lu\n\n",str, sizeof str, str1, sizeof str1, str2, sizeof str2, str22, sizeof str22, str3, sizeof str3, str4, sizeof str4, str5, sizeof str5);

	printf("String3: %s\n",string3);
	//free(string3);
	string3 = string2;
	/*&string4 = &string1 ;*/// NOT POSSIBLE!!! because arrays are not assignable
	printf("String3: %s\n",string3);

	struct S s1;
	S s2;
	s1.x = 1;
	s2.x = 2;

	f(s1); f2(s1);
	f(s2); f2(s2);

	typedef struct {
		int x,y;
	} Point ;

	struct Coordonees {
		int x,y;
	};
	typedef struct Coordonees coordy ;

	struct Coordonees coord1;
	coordy cc;
	cc.x = 55; cc.y = 9;
	S qsdf; qsdf.x=88;
	coord1.x=199 ; coord1.y=982;

	Point point ;
	point.x=20 ; point.y=30 ;

	/* Définition et déclaration de variables */
	struct Complexe {float reelle, imag;} c1;

	/* Accès aux champs */
	c1.reelle=6 ; c1.imag=1 ;

	copyStructsWithArray();

	testOuvrage();
	structureImbriques();
	return 0;
}
