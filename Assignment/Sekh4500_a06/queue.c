/*
 -------------------------------------
 File:    queue.c
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
#include "common.h"
#include "queue.h"

/**
 * Adds a new NODE to the end of the QUEUE
 */
void enqueue(QUEUE *qp, NODE *np) {
	// Beginning of queue
	if (qp->front == NULL || qp->rear == NULL) {
		qp->front = np;
		qp->rear = np;
	} else    // Queue has elements, add to rear
	{
		qp->rear->next = np;
		qp->rear = np;
	}

}

/**
 * Removes and returns the NODE at the beginning
 * of the QUEUE
 */
NODE* dequeue(QUEUE *qp) {
	if (qp->front == NULL || qp->rear == NULL)
		return NULL;
	NODE *np = qp->front;
	qp->front = qp->front->next;
	np->next = NULL;
	return np;
}

/**
 * Cleans the QUEUE by freeing each NODE
 */
void clean_queue(QUEUE *qp) {
	NODE *curr = qp->front;
	NODE *prev = NULL;

	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	qp = NULL;
}
