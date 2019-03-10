/* Source Code From Bernard Carré and Laure Gonnord
 * Adapted by Walter Rudametkin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trees.h"

#define MAX_STRING 511

// Main -- Do not modify !

// iterate the process: load, print (Part 1) and then generate_dot (Part 2) on the n files_names
void handle(int n, char *file_names[]);

void build_name(char *src, char *dest, char *ext);

// main - usage: main <file_name_1> <file_name_2> <file_name_3>...
int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "usage: main <file_names (.txt files)>\n");
		return EXIT_FAILURE;
	}

	// Handle the files.
	// The first string is always the name of the exe program,
	// so we avoid it and start at the second argument
	handle(argc-1, &argv[1]);

	return EXIT_SUCCESS;
}

// iterate the process: load, print (Part 1) and then generate_dot (Part 2) on the n files_names
void handle(int n, char *file_names[])
{
	for (int i=0; i<n; i++)
	{
		FILE *fp=fopen(file_names[i], "r");
		if (fp==NULL)
		{
			fprintf(stderr, "cannot read: %s\n", file_names[i]);
			//return;
			continue; //this file is no good, go to next file
		}

		// Part 1
		struct node *tree=NULL;
		load_tree(fp, &tree);
		fclose(fp);

		printf("------------------------------------------------------\n%s:\n", file_names[i]);
		print_tree(tree); // on std output
		printf("\n");


		//Part 2
		char dot_file_name[MAX_STRING/2-16];
		char pdf_file_name[MAX_STRING/2-16];
		char command[MAX_STRING];//must contain both dot and pdf filenames, plus the dot command

		// new name for he dot file = file_name in which ".txt" is replaced by ".dot"
		build_name(file_names[i], dot_file_name, ".dot");

		fp=fopen(dot_file_name, "w");
		if (fp == NULL)
		{
			fprintf(stderr, "cannot write: %s\n", dot_file_name);
			continue; //move to next file in for loop
		}

		generate_dot(tree,fp); // Call to the printing function
		free_tree(&tree);
		fclose(fp);
		printf("dot file %s has been generated\n",dot_file_name);

		// new name for the pdf file = file_name in which ".txt" is replaced by ".pdf"
		build_name(file_names[i], pdf_file_name, ".pdf");

		// transform to .pdf with the dot system command
		/*snprintf(command, MAX_STRING, "dot -Tpdf %s -o %s", dot_file_name, pdf_file_name);*/
		sprintf(command, "dot -Tpdf %s -o %s", dot_file_name, pdf_file_name);
		system(command);
		printf("pdf file %s has been generated\n", pdf_file_name);
	}
}

// utility: build a new file name dest from src whose extension is replaced by the parameter ext
// for example : file.txt -> file.dot
void build_name(char *src, char *dest, char *ext)
{
	strcpy(dest, src);
	strcpy(&dest[strlen(src)-4], ext);
}

