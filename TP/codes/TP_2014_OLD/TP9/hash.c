/*Source Code From Laure Gonnord, 2012*/
/*Adapted from Bernard Carre, 2011*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*List library : reminder, the word have maximal size  MAXSIZE*/
#include "listechaines.h"

/*Size of the hashtables */
#define TABLE_SIZE 308

/**Hash functions**/
int asciis(char *word)
{
  int i=0;
  int h=0;
  while(word[i]!='\0')
    {
      h=h+(word[i]-96);
      i++;
    }
  return h;
}

int hash(char *word)
{
  return (asciis(word) % TABLE_SIZE);
}

//TODO : write the following functions

/*Declaration of type Hashtable */
//!!! Wrong type, please modify!
typedef int Hashtable;


/*Initialisation of a given Hashtable*/
void init_ht(Hashtable ht) {
  //TODO
}

/*Update of the hashtable : add the given word in the table!*/
void update_ht(char *word, Hashtable ht) {
  //TODO
}

/*Load the file in the internal structure ht */
void load_ht(FILE *fp, Hashtable ht) {
  //TODO
}

/*Count the collisions*/
void collisions(Hashtable ht) {
  //TODO
}

/*Maximal hash of the words of the given file*/
/*returns max_word such that hash(max_word)=hmax*/
void max_hash(FILE *fp, char *max_word, int *hmax) {
  //TODO
}

/*Main function*/
int main (int argc, char *argv[]) {
  if (argc < 2) { // text file is missing ?
    fprintf(stderr, "usage: hash <file_name>\n");
  } else {
    FILE *fp;
    fp=fopen(argv[1], "r");
    if (fp==NULL) {
      fprintf(stderr, "no such file, or unreachable: %s\n", argv[1]);
    } else {
      //using lists !
      Liste mylist = NULL;
      charge_fichier(fp,&mylist);
      //      afficherListe(mylist);


      // replace by declaration and use of hashtables!
      //TODO !


      printf("Fin de traitement!\n");
    }//end of else
  }

  return 0;
}
