/**
 * Source Code by Walter Rudametkin
 * Modified from code by Laure Gonnord and Bernard Carré
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"

void test_empty_and_42();
void print_tree_from_file(char * filename);

int main() {
	test_empty_and_42();

	//Tester tous les fichiers .txt, un par un, dans samples/ !!!
	//Corrigez les Warnings et utilisez Valgrind.
	print_tree_from_file("samples/empty.txt");
	print_tree_from_file("samples/leaf.txt");
	print_tree_from_file("samples/balanced.txt");
	print_tree_from_file("samples/degenerated.txt");
	print_tree_from_file("samples/unspecified.txt");

	return 0;
}

void test_empty_and_42() {
	struct node *tree1;
	mk_empty_tree(&tree1);   //Initialize

	//Simple test to see if initialization is correct
	printf("\nTest 1: is_empty");
	printf("\n----------------\n");
	if (is_empty(tree1)) printf("empty\n");

	cons_tree(&tree1, 42, NULL, NULL); //Build a node

	printf("\nTest 2: 42");
	printf("\n----------\n");
	printf("print_tree(tree1) ==> ");
	print_tree(tree1);
	printf("\n\n");

	free_tree(&tree1);
}

void print_tree_from_file(char * filename) {
	FILE* fp = fopen(filename,"r");

	if(fp == NULL) return ; //File is not readable

	struct node *big_tree;
	mk_empty_tree(&big_tree);

	load_tree(fp, &big_tree);

	printf("\n\n===============================================================\n");
	printf("                 File: %s\n",filename);
	printf(    "===============================================================\n\n");

	//ordered print
	printf("Print tree values in-order (left, node, right) : print_tree(big_tree)\n");
	printf("---------------------------------------------------------------------\n");
	print_tree(big_tree);
	printf("\n");

	//father->son print
	printf("\nPrint (father l/r-> son) pairs : print_rec_edges(big_tree)");
	printf("\n----------------------------------------------------------\n");
	print_rec_edges(big_tree);
	printf("\n");

	free_tree(&big_tree);
	fclose(fp);
}


