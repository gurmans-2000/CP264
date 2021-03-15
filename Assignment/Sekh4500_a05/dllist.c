/*
 -------------------------------------
 File:    bigint.c
 Project: sekh4500_a05_q2
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-02-26
 -------------------------------------
 */

#include "dllist.h"

NODE* new_node(char data) {
	NODE *np = (NODE*) malloc(sizeof(NODE));
	np->data = data;
	np->prev = NULL;
	np->next = NULL;
	return np;
}

void display_forward(NODE *np) {
	NODE *ptr = np;
	while (ptr != NULL) {
		printf("%c ", ptr->data);
		ptr = ptr->next;
	}
}

void display_backward(NODE *np) {
	NODE *ptr = np;
	while (ptr != NULL) {
		printf("%c ", ptr->data);
		ptr = ptr->prev;
	}
}

void insert_start(NODE **startp, NODE **endp, NODE *new_np) {
	if (*startp == NULL && *endp == NULL) {
		*startp = new_np;
		*endp = new_np;
	} else {
		(*startp)->prev = new_np;
		new_np->next = *startp;
		*startp = new_np;
	}
}

void insert_end(NODE **startp, NODE **endp, NODE *new_np) {
	if (*startp == NULL && *endp == NULL) {
		*startp = new_np;
		*endp = new_np;
	} else {
		(*endp)->next = new_np;
		new_np->prev = *endp;
		*endp = new_np;
	}
}

void delete_start(NODE **startp, NODE **endp) {
	if (*startp != NULL && *endp != NULL) {
		NODE *ptr = *startp;
		free(ptr);
		*startp = (*startp)->next;
		(*startp) = NULL;
	}
}

void delete_end(NODE **startp, NODE **endp) {

	if (*startp != NULL && *endp != NULL) {
		NODE *temp = *endp;
		free(endp);
		*endp = temp->prev;
		(*endp)->next = NULL;

	}
}

void clean(NODE **startp, NODE **endp) {
	NODE *ptr = *startp;
	NODE *temp = NULL;

	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	*startp = NULL;
	*endp = NULL;
}
