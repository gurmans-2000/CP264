/*--------------------------------------------------
 Project: CP264-a6
 File:    common.j
 Description: node structure and functions for linked list queue and stack
 Author:  HBF
 Version: 2021-02-24
 --------------------------------------------------
 */
#ifndef COMMON_H
#define COMMON_H

typedef struct node {
	int data;
	int type;
	struct node *next;
} NODE;
NODE* new_node(int data, int type);
void display(NODE *start);
void clean(NODE **startp);
#endif
