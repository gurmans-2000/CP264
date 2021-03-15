/*
 -------------------------------------
 File:    stack.c
 Project: sekh4500_a06
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-03-02
 -------------------------------------
 */

#include <stdio.h>
#include "stack.h"
/**
 * Pushes a NODE onto the top of the STACK
 */
void push(STACK *sp, NODE *np) {
	// Beginning of stack
	if (sp->top == NULL) {
		sp->top = np;
	} else    // Stack has elements, add to top
	{
		np->next = sp->top;
		sp->top = np;
	}
}

/**
 * Removes and returns the NODE at the top of
 * the STACK
 */
NODE* pop(STACK *sp) {
	if (sp->top == NULL)
		return NULL;
	NODE *np = sp->top;
	sp->top = sp->top->next;
	np->next = NULL;
	return np;
}

/**
 * Frees all NODES in the STACK
 */
void clean_stack(STACK *sp) {
	NODE *curr = sp->top;
	NODE *prev = NULL;

	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	sp = NULL;
}
