/*
 -------------------------------------
 File:    myrecord_llist.c
 Project: sekh4500_a05
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-02-25
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_llist.h"
#include <math.h>

NODE* new_node(char *name, float score) {
	NODE *ptr = (NODE*) malloc(sizeof(NODE));
	if (ptr != NULL) {
		strcpy(ptr->data.name, name);
		ptr->data.score = score;
		ptr->next = NULL;
	}
	return ptr;
}

void display(NODE *start) {
	NODE *np = start;
	while (np != NULL) {
		printf("%s,%.1f\n", np->data.name, np->data.score);
		np = np->next;
	}
}

NODE* search(NODE *startp, char *name) {
	NODE *curr = startp;

	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

void insert(NODE **startp, char *name, float score) {

	NODE *p = (NODE*) malloc(sizeof(NODE));
	strcpy(p->data.name, name);
	p->data.score = score;
	p->next = NULL;
	NODE *prev = NULL;
	NODE *ptr = *startp;
	while (ptr != NULL) {
		if (strcmp(ptr->data.name, name) >= 0)
			break;
		prev = ptr;
		ptr = ptr->next;
	}

	if (prev == NULL) {
		*startp = p;
		p->next = ptr;
	} else {
		prev->next = p;
		p->next = ptr;

	}
}

int delete(NODE **startp, char *name) {
	NODE *curr = *startp;
	NODE *prev = NULL;

	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0)
			break;
		prev = curr;
		curr = curr->next;
	}

	if (curr != NULL) {
		prev->next = curr->next;
		free(curr);
		return 1;
	} else {
		return 0;
	}

}

void clean(struct node **startp) {
	struct node *temp, *np = *startp;
	while (np != NULL) {
		temp = np;
		np = np->next;
		free(temp);
	}
	*startp = NULL;
}

// the following functions are adapted and modified from previous assignments.
char letter_grade(float s) {
	char r = 'F';
	if (s >= 90)
		r = 'S';
	else if (s >= 80)
		r = 'A';
	else if (s >= 70)
		r = 'B';
	else if (s >= 60)
		r = 'C';
	else if (s >= 50)
		r = 'D';
	else
		r = 'F';
	return r;
}

int import_data(NODE **startp, char *filename) {
	char line[40], name[20];
	char *result = NULL;
	char delimiters[] = ",";
	float score = 0;
	int count = 0;

	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fp) != NULL) {
		result = strtok(line, delimiters);
		strcpy(name, result);
		result = strtok(NULL, delimiters);
		score = atof(result);
		insert(startp, name, score);
		count++;
	}
	fclose(fp);

	return count;
}

REPORT report_data(NODE *start, char *filename) {
	REPORT report = { };
	NODE *np = start;
	int count = 0;
	float mean = 0;
	float stddev = 0;

	FILE *fp = fopen(filename, "w");
	while (np != NULL) {
		count++;
		mean += np->data.score;
		stddev += np->data.score * np->data.score;
		fprintf(fp, "%s,%3.1f,%c\n", np->data.name, np->data.score,
				letter_grade(np->data.score));
		np = np->next;
	}
	fclose(fp);

	mean /= count;
	stddev = sqrt(stddev / count - mean * mean);
	report.count = count;
	report.mean = mean;
	report.stddev = stddev;
	return report;
}
