/*
 -------------------------------------
 File:    myrecord_llist.h
 Project: sekh4500_a05
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-02-25
 -------------------------------------
 */

#ifndef LLIST
#define LLIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
 * RECORD structure
 * name  - char array for person's name
 * score - float score of record
 */
typedef struct {
	char name[40];
	float score;
} RECORD;

/**
 * Define NODE structure
 * data  - RECORD data
 * next  - pointer pointing to the next node of linked list
 */

typedef struct node {                           // List node structure.
	RECORD data;
	struct NODE *next;                         // Pointer to an sNODE node.
} NODE;

/**
 * Display linked list.
 * @param start Pointer to the first node of linked list.
 */
void display(NODE *start);

/**
 * Search linked list for name key.
 * @param start Pointer to the first node of linked list.
 * @param name Key to search
 * @return Pointer to found node if found; otherwise NULL
 */
NODE* search(NODE *start, char *name);

/**
 * Insert new record to linked list at the sorted position.
 * @param startp Pointer pointing to the start pointer of linked list, used to update the start node address in case of change.
 * @param name The name data of new record.
 * @param score The score data of new record
 */
void insert(NODE **startp, char *name, float score);

/**
 * Delete a record by name from linked list, the first one matched.
 * @param startp Pointer pointing to the start pointer of linked list, used to update the start node address in case of change.
 * @param name  The key used to find the node for deletion.
 */
int delete(NODE **startp, char *name);

/**
 * Clean linked list.
 * @param startp Pointer pointing to the start pointer of linked list, used to update the start node address in case of change.
 */
void clean(NODE **startp);

// The following are adapted/modified from previous assignments
typedef struct {
	int count;
	float mean;
	float stddev;
} REPORT;
char letter_grade(float score);
int import_data(NODE **startp, char *filename);
REPORT report_data(NODE *start, char *filename);

#endif
