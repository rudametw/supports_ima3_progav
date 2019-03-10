/*
 *  By Walter Rudametkin
 *  Modfied from Bernard Carre
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}Node, *PtNode, *Tree;
/* These typedefs are optionnel, you may use them */

/* Constructs a new tree from a value for the root node, a given left tree and a given right tree */
//struct node * cons_tree(int, struct node *, struct node *);
void cons_tree(struct node **, int, struct node *, struct node *);

/* Make an empty tree */
//struct node * mk_empty_tree();
void mk_empty_tree(struct node **);

/* Is the tree empty ? */
bool is_empty(struct node *);

/* Is the tree a leaf ? */
bool is_leaf(struct node *);


/* Add the value (int) to the binary search tree,
 * it must be ordered.
 * Do not verify the presence of the value,
 * duplicate values are valid.
 */
void add(struct node **, int);

/* Print the values of the tree in ascendant order */
void print_tree(struct node *);

/* Build a tree adding values of the file */
void load_tree(FILE *, struct node **);

void free_tree(struct node **);

void print_rec_edges(struct node *t);


/**
 * PART 2
 */
void generate_dot(struct node *, FILE *);

void recursive_dot(struct node *, FILE *fp);
