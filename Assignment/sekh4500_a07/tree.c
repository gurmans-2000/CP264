// your signature

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

TPROPS get_props(TNODE *root) {
	TPROPS r = { 0 };
	if (root == NULL)
		return r;
	else {
		r.count = 1 + get_props(root->left).count
				+ get_props(root->right).count;
		int LH = 1 + get_props(root->left).height;
		int RH = 1 + get_props(root->right).height;
		r.height = LH > RH ? LH : RH;

	}

	return r;
}

void display_preorder(TNODE *root) {
	if (root != NULL) {
		printf("%c ", root->data);
		display_preorder(root->left);
		display_preorder(root->right);
	}
}

void display_inorder(TNODE *root) {
	if (root != NULL) {

		display_inorder(root->left);
		printf("%c ", root->data);
		display_inorder(root->right);
	}
}

void display_postorder(TNODE *root) {
	if (root != NULL) {

		display_postorder(root->left);
		display_postorder(root->right);
		printf("%c ", root->data);

	}
}

TNODE* iterative_bf_search(TNODE *root, int val) {
	if (!root)
		return NULL;

	QUEUE q = { 0 };
	TNODE *curr;
	enqueue(&q, root);
	while (q.front) {
		curr = dequeue(&q);
		if (curr->data == val) {
			clean_queue(&q);
			return curr;
		}
		if (curr->left)
			enqueue(&q, curr->left);
		if (curr->right)
			enqueue(&q, curr->right);
	}

	clean_queue(&q);

	return NULL;
}

TNODE* iterative_df_search(TNODE *root, int val) {
	if (!root)
		return NULL;

	STACK stack = { 0 };
	TNODE *curr;

	push(&stack, root);

	while (stack.top) {
		curr = peek(&stack);
		pop(&stack);
		if (val == curr->data) {
			clean_stack(&stack);
			return curr;
		}
		if (curr->right)
			push(&stack, curr->right);
		if (curr->left)
			push(&stack, curr->left);
	}
// Value not found, clean up stack
	clean_stack(&stack);

	return NULL;
}

/* basic functions */
TNODE* new_node(int value) {
	TNODE *np = (TNODE*) malloc(sizeof(TNODE));
	if (np == NULL)
		return NULL;
	np->data = value;
	np->left = NULL;
	np->right = NULL;
	return np;
}

void display_tree(TNODE *root, int prelen) {
	if (root) {
		int i;
		for (i = 0; i < prelen; i++)
			printf("%c", ' ');
		printf("%s", "|___");
		printf("%c\n", root->data);
		display_tree(root->right, prelen + 4);
		display_tree(root->left, prelen + 4);
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

// queue functions adapted and modified from a6
void enqueue(QUEUE *qp, void *data) {
	QNODE *p = (QNODE*) malloc(sizeof(QNODE));
	if (p == NULL)
		return;
	else {
		p->data = data;
		p->next = NULL;

		if (qp->front == NULL) {
			qp->front = p;
			qp->rear = p;
		} else {
			(qp->rear)->next = p;
			qp->rear = p;
		}
	}
}
void* dequeue(QUEUE *qp) {
	void *temp = NULL;
	if (qp->front) {
		QNODE *p = qp->front;
		temp = p->data;
		if (qp->front == qp->rear) {
			qp->front = NULL;
			qp->rear = NULL;
		} else {
			qp->front = p->next;
		}
		free(p);
		return temp;
	}
	return NULL;
}
void clean_queue(QUEUE *qp) {
	QNODE *temp, *p = qp->front;
	while (p != NULL) {
		temp = p;
		p = p->next;
		free(temp);
	}
}

// stack functions adapted and modified from a6
void push(STACK *sp, void *data) {
	SNODE *p = (SNODE*) malloc(sizeof(SNODE));
	p->data = data;
	p->next = NULL;
	if (sp->top == NULL) {
		sp->top = p;
	} else {
		p->next = sp->top;
		sp->top = p;
	}
}
void pop(STACK *sp) {
	if (sp->top != NULL) {
		SNODE *p = sp->top;
		sp->top = p->next;
		free(p);
	}
}
void* peek(STACK *sp) {
	if (sp->top != NULL) {
		return sp->top->data;
	}
	return NULL;
}
void clean_stack(STACK *sp) {
	SNODE *temp, *p = sp->top;
	while (p) {
		temp = p;
		p = p->next;
		free(temp);
	}
	sp->top = NULL;
}
