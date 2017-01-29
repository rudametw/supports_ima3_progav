/*
 *  trees.h
 *  
 *
 *  From a code of Bernard Carre
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int val;
	struct node *left;
	struct node *right;
} Node, *PtNode, *Tree;


/*Construct a new tree from a value for the root node, a given left tree and a given right tree*/
Tree cons(int , Tree , Tree );

// make an empty tree
Tree mkEmptyTree();

/*Is the given tree empty ?*/
bool isEmpty (Tree);

/*Is the given tree a leaf ?*/
bool isLeaf (Tree);

/*Add a given integer in a binary search tree*/
// do not verify the presence of x.
void add(Tree *, int);

/*Print the values of the tree in ascendant order*/
void print_lvr (Tree);

/* build a tree adding values of the file */
void load_tree(FILE *, Tree *);

/*PART 2*/

void generate_dot (Tree , FILE *);
