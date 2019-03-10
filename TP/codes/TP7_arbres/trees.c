/* Source Code From Laure Gonnord and Bernard Carré
 * Modified by Walter Rudametkin
 */

#include "trees.h"

//construction of a tree by return value
//struct node * cons(int val, struct node *left, struct node *right)
//{
//    PtNode new = malloc(sizeof(Node));
//    new->val=val;
//    new->left=left;
//    new->right=right;
//    return new;
//}

// construction of a tree by pointer
void cons_tree(struct node ** ptr_tree, int val, struct node *left, struct node *right)
{
	//TODO
}

// create an empty tree by return value
//struct node * mk_empty_tree()
//{
//	return NULL;
//}

// initialize un empty tree
void mk_empty_tree(struct node ** ptr_tree)
{
	*ptr_tree = NULL;
}

// tree is empty?
bool is_empty(struct node *tree)
{
	return tree==NULL;
}

// t is a leaf?
bool is_leaf(struct node *tree)
{
	return(!is_empty(tree) && is_empty(tree->left) && is_empty(tree->right));
}

// add x in a bst wtr its value.
void add(struct node **ptr_tree, int x)
{
	//TODO
}

// print values of tree in ascendant order (left-value-right)
void print_tree(struct node *tree)
{
	//TODO
}

// build a tree "add"ing values of the file fp
void load_tree(FILE *fp, struct node **ptr_tree)
{
	//TODO
	//Tip: use while(fscanf(..) ...)
}

// Free all memory used by the tree
void free_tree(struct node **ptr_tree)
{
	//TODO
}


// print pairs (father =L/R=> son)
void print_rec_edges(struct node *tree)
{
	//TODO
}

//PART II

// recursively prints arcs of the tree <value,left,right> into the file fp:
// "value -> left;"  if it exists
// "value -> right;" if it exists
// check for: !is_empty(t) & !is_leaf(t)
void recursive_dot(struct node *tree, FILE *fp)
{
	//TODO
}


// generate a .dot file for the tree
// limits (no arcs) :
//   is_empty(t) => "empty" digraph
//   is_leaf(t) => only one node
// general case :
//   calls recursive_dot which prints arcs
void generate_dot (struct node *t, FILE *fp)
{
	fprintf (fp, "digraph G {\n");
	if (!is_empty(t))
	{
		if (is_leaf(t))
		{
			fprintf(fp, "\t%d", t->val);
		}
		else
		{
			recursive_dot(t,fp);
		}
	}
	fprintf (fp, "}\n");
}
