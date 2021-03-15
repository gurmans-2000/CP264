/*
 -------------------------------------
 File:    myrecord.h
 Project: sekh4500_a04
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-02-09
 -------------------------------------
 */

#ifndef MYRECORD_H
#define MYRECORD_H

typedef struct {
	char name[20];
	float score;
} RECORD;

typedef struct {
	int count;
	float mean;
	float stddev;
} REPORT;

char letter_grade(float score);
int import_data(RECORD dataset[], char *filename);
REPORT report_data(RECORD dataset[], int n, char *filename);

#endif
