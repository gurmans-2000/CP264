/*
 -------------------------------------
 File:    dllist.h
 Project: sekh4500_a05
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-02-25
 -------------------------------------
 */

#ifndef DLLIST
#define DLLIST

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node *prev;
	struct node *next;
} NODE;

NODE* new_node(char data);
void display_forward(NODE *start);
void display_backward(NODE *end);
void insert_start(NODE **startp, NODE **endp, NODE *new_np);
void insert_end(NODE **startp, NODE **endp, NODE *new_np);
void delete_start(NODE **startp, NODE **endp);
void delete_end(NODE **startp, NODE **endp);
void clean(NODE **startp, NODE **endp);

#endif
