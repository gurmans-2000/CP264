/*
 -------------------------------------
 File:    avl.h
 Project: sekh4500_a08
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-03-14
 -------------------------------------
 */

typedef struct rec {
	char name[40];
	float score;
} RECORD;

typedef struct node {
	RECORD data;
	int height;
	struct node *left;
	struct node *right;

} TNODE;

/* This checks if the tree is AVL tree, returns 1 if true, otherwise 0 */
int is_avl(TNODE *root);

/* this does left rotation  */
TNODE* rotate_left(TNODE *root);

/* this does right rotation  */
TNODE* rotate_right(TNODE *root);

/* insert a record (name, score) into the AVL tree using name as key */
void insert(TNODE **rootp, char *name, float score);

/* delete node of with key equals to name from the AVL */
void delete(TNODE **rootp, char *name);  //

// following functions are adapted from a7
TNODE* extract_smallest_node(TNODE **rootp);
void display_inorder(TNODE *root);
void display_inorder_lines(TNODE *root);
void display_tree(TNODE *root, int prelen);
TNODE* search(TNODE *root, char *name);
void clean_tree(TNODE **rootp);
