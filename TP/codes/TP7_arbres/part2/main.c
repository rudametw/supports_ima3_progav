/*Source Code From Bernard Carré and Laure Gonnord */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"


// Main -- Do not modify !

// iterate the process: load, print (Part 1) and then generate_dot (Part 2) on the n files_names
void handle(int n, char *file_names[]);

// main - usage: main <file_name_1> <file_name_2> <file_name_3>...
int main (int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage: main <file_names (.txt files)>\n");
  } else {
    handle(argc-1, &argv[1]); // handle the files
  }
  return 0;
}

// utility: build a new file name dest from src whose extension is replaced by the parameter ext
// for example : file.txt -> file.dot
void build_name(char *src, char *dest, char *ext);

// iterate the process: load, print (Part 1) and then generate_dot (Part 2) on the n files_names
void handle(int n, char *file_names[]) {
  Tree t;
  FILE *fp;
  int i;
  for (i=0; i<n; i++) {
    fp=fopen(file_names[i], "r");
    if (fp==NULL) {
      fprintf(stderr, "no such file, or unreachable: %s\n", file_names[i]);
    } else {
      // Part 1
      t=NULL;
      load_tree(fp, &t);
      fclose(fp);
      printf("---------------\n%s:\n", file_names[i]);
      print_lvr(t); // on std output
      printf("\n");
      
      //Part 2
      
      char dot_file_name[MAX_STRING], pdf_file_name[MAX_STRING], command[MAX_STRING];
      
      // new name for he dot file = file_name in which ".txt" is replaced by ".dot"
      build_name(file_names[i], dot_file_name, ".dot");
      fp=fopen(dot_file_name, "w");
      if (fp == NULL) {
	fprintf(stderr, "unreachable: %s\n", dot_file_name);
      } else {
	generate_dot(t,fp); // Call to the printing function 
	printf("dot file %s has been generated\n",dot_file_name);
	fclose(fp);
	// new name for the pdf file = file_name in which ".txt" is replaced by ".pdf"
	build_name(file_names[i], pdf_file_name, ".pdf");
	// transform to .pdf with the dot system command
	sprintf(command, "dot -Tpdf %s -o %s", dot_file_name, pdf_file_name);
	system(command);
	printf("pdf file %s has been generated\n", pdf_file_name);
      }
      
    }
  }
}

// utility: build a new file name dest from src whose extension is replaced by the parameter ext
// for example : file.txt -> file.dot
void build_name(char *src, char *dest, char *ext) {
  strcpy(dest, src);
  strcpy(&dest[strlen(src)-4], ext);
}
