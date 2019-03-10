/*Source Code From Laure Gonnord and Bernard Carré*/

#include "trees.h"

// construction of a tree
Tree cons(int val, Tree left, Tree right) {
  PtNode new = (PtNode)malloc(sizeof(Node));
  new->val=val;
  new->left=left;
  new->right=right;
  return new;
}

// create an empty tree
Tree mkEmptyTree(){
  return NULL;
}

// t is empty?
bool isEmpty (Tree t) {
  return t==NULL;
}

// t is a leaf?
bool isLeaf (Tree t) {
  return (!isEmpty(t) && isEmpty(t->left) && isEmpty(t->right));
}

// add x in a bst wtr its value.
void add(Tree *p_t, int x) {
  //TODO
}

// build a tree "add"ing values of the file fp
void load_tree(FILE *fp, Tree *p_t) {
  //TODO
}

// print values of t in ascendant order (left-value-right)
void print_lvr (Tree t) {  
  //TODO
}

//Section 1.5
void print_rec_edges(Tree t){
  //TODO
}

//PART II

// pre: !isEmpty(t) & !isLeaf(t)
// recursively prints arcs of the tree <value,left,right> into the file fp:
// "value -> left;" if exist
// "value -> right;" if exist
// to do...
void recursive_dot(Tree t, FILE *fp) {
  //TODO
}


// generate a .dot file for the tree
// limits (no arcs) :
//   isEmpty(t) => "empty" digraph
//   isLeaf(t) => only one node
// general case :
//   calls recursive_dot which prints arcs
void generate_dot (Tree t, FILE *fp) {
  fprintf (fp, "digraph G {\n");
  if (!isEmpty(t)) {
    if (isLeaf(t)) {
      fprintf(fp, "\t%d", t->val);
    } else {
      recursive_dot(t,fp);
    }
  }
  fprintf (fp, "}\n");
}
