/*Source Code From Laure Gonnord*/

//à tester avec ./ldc, ./ldc toto, ./ldc toto 3, ...

#include <stdio.h>

int main(int argc, char* argv[]){

  int i=0;
  printf("bonjour, il y a %d argument(s) à cette commande! \n",argc);
  
  while(i<argc){
    printf("argument %d : %s\n",i,argv[i]);
    i++;
  }

  printf("c'est fini !\n");
  return 0;
}
