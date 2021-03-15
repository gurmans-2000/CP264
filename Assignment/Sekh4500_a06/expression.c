/*
 -------------------------------------
 File:    expression.c
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
#include <stdlib.h>
#include "expression.h"
#include "common.h"
#include "queue.h"
#include "stack.h"

/*
 * auxiliary function
 */
int get_priority(char op) {
	if (op == '/' || op == '*' || op == '%')
		return 1;
	else if (op == '+' || op == '-')
		return 0;
	else
		return -1;
}

/*
 * auxiliary function
 */
int type(char c) {
	if (c >= '0' && c <= '9')
		return 0;
	else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
		return 1;
	else if (c == '(')
		return 2;
	else if (c == ')')
		return 3;
	else
		return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
	int index = 0;
	char *p = infixstr;
	QUEUE queue = { 0 };
	STACK stack = { 0 };
	int sign = 1, num = 0;
	NODE *temp = { 0 }; // Stores popped NODES
	while (*p) {
		// Store current type
		int curr_type = type(*p);
		// Get sign of operand
		if (*p == '-' && (p == infixstr || *(p - 1) == '('))
			sign = -1;
		else if (curr_type == 0) { // Operand / Number
			// Use Horner's Algo to get operand
			num = *p - '0';
			while (type(*(p + 1)) == 0) {
				num = num * 10 + *(p + 1) - '0';
				p++;
			}
			enqueue(&queue, new_node(sign * num, 0));
			sign = 1;
		} else if (curr_type == 1) { // Operator
			// Pop operators with equal or higher precedence
			// and add to QUEUE (ignoring parens), then add
			// curr operator to stack
			while (stack.top
					&& get_priority(*p)
							< get_priority((temp = pop(&stack))->data)) {
				// Ignore parens
				if (temp->type != 2 && temp->type != 3)
					enqueue(&queue, temp);
			}
			// Push temp back onto stack if unused
			if (temp && get_priority(*p) >= get_priority(temp->data)) {
				push(&stack, temp);
			}
			// Add current operator to STACK
			push(&stack, new_node(*p, type(*p)));
		} else if (curr_type == 2) { // Left parens
			push(&stack, new_node(*p, type(*p)));
		} else if (curr_type == 3) { // Right parens
			// Pop operators from STACK, add to QUEUE
			// until matching left parens is found
			while (stack.top && (temp = pop(&stack))->type != 2) {
				enqueue(&queue, temp);
			}
		}
		// Otherwise ignore
		p++;
		index++;
	}
	// Pop each NODE and add to QUEUE
	while (stack.top)
		enqueue(&queue, pop(&stack));
	clean_stack(&stack);
	return queue;
}

int evaluate_postfix(QUEUE queue) {
	NODE *p = queue.front;
	STACK stack = { 0 };
	int type = 0;
	int temp;
	while (p) {
		type = p->type;
		if (type == 0) {
			push(&stack, new_node(p->data, 0));
		} else if (type == 1) {
			int right = pop(&stack)->data;
			int left = pop(&stack)->data;
			temp = 0;
			if (p->data == '+')
				temp = left + right;
			else if (p->data == '-')
				temp = left - right;
			else if (p->data == '*')
				temp = left * right;
			else if (p->data == '/')
				temp = left / right;
			push(&stack, new_node(temp, 0));
		}
		p = p->next;
	}
	int result = stack.top->data;
	clean_stack(&stack);
	clean_queue(&queue);
	return result;
}

int evaluate_prefix(char *infixstr) {
	QUEUE qb = infix_to_postfix(infixstr);
	int result = evaluate_postfix(qb);
	clean_queue(&qb);
	return result;
}
