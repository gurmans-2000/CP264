/*
 -------------------------------------
 File:    bst.c
 Project: sekh4500_a07
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-03-12
 -------------------------------------
 */

// your signature
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bst.h"

TNODE* search(TNODE *root, char *name) {
	if (!root)
		return NULL;
	if (strcmp(root->data.name, name) == 0)
		return root;
	if (strcmp(root->data.name, name) > 0)
		return search(root->left, name);
	if (strcmp(root->data.name, name) < 0)
		return search(root->right, name);
}

void insert(TNODE **rootp, char *name, float score) {
	if (!*rootp) {
		RECORD data = { 0 };
		TNODE *nnode = (TNODE*) malloc(sizeof(TNODE));
		strncpy(data.name, name, 39);

		data.score = score;
		nnode->data = data;
		nnode->right = NULL;
		nnode->left = NULL;

		*rootp = nnode;
		return;
	}
	if (strcmp(name, (*rootp)->data.name) > 0)
		insert(&(*rootp)->right, name, score);
	else if (strcmp(name, (*rootp)->data.name) < 0)
		insert(&(*rootp)->left, name, score);
	else
		return;
}

void delete(TNODE **rootp, char *name) {
	if (!*rootp)
		return;

	TNODE *tmp = NULL;

	if (strcmp(name, (*rootp)->data.name) == 0) {
		if (!(*rootp)->left && !(*rootp)->right) {
			free(rootp);
			*rootp = NULL;
		} else if ((*rootp)->left && !(*rootp)->right) {
			tmp = (*rootp)->left;
			free(rootp);
			*rootp = tmp;
		} else if (!(*rootp)->left && (*rootp)->right) {
			tmp = (*rootp)->right;
			free(rootp);
			*rootp = tmp;
		} else if ((*rootp)->left && (*rootp)->right) {
			tmp = extract_smallest_node(&(*rootp)->right);
			tmp->left = (*rootp)->left;
			tmp->right = (*rootp)->right;
			free(rootp);
			*rootp = tmp;
		}
	} else if (strcmp(name, (*rootp)->data.name) < 0)
		delete(&(*rootp)->left, name);
	else
		delete(&(*rootp)->right, name);
}

TNODE* extract_smallest_node(TNODE **rootp) {
	if (!*rootp)
		return NULL;
	if (!(*rootp)->left)
		return *rootp;
	else
		return extract_smallest_node(&(*rootp)->left);
}

void display_inorder(TNODE *root) {
	if (root) {
		if (root->left)
			display_inorder(root->left);
		printf("%-15s%3.1f\n", root->data.name, root->data.score);
		if (root->right)
			display_inorder(root->right);
	}
}

void clean_tree(TNODE **rootp) {
	TNODE *root = *rootp;
	if (root) {
		if (root->left)
			clean_tree(&root->left);
		if (root->right)
			clean_tree(&root->right);
		free(root);
	}
	*rootp = NULL;
}
