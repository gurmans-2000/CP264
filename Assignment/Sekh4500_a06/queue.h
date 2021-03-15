/*
 -------------------------------------
 File:    queue.h
 Project: sekh4500_a06
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-03-02
 -------------------------------------
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

typedef struct queue {
	NODE *front;
	NODE *rear;
} QUEUE;

void enqueue(QUEUE *qp, NODE *np);
NODE* dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

#endif
