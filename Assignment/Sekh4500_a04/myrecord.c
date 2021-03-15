/*
 -------------------------------------
 File:    myrecord.c
 Project: sekh4500_a04
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-02-09
 -------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"

#define MAX_LINE 100

char letter_grade(float s) {
	if (s >= 90 && s <= 100)
		return 'S';
	else if (s >= 80 && s < 90)
		return 'A';
	else if (s >= 70 && s < 80)
		return 'B';
	else if (s >= 60 && s < 70)
		return 'C';
	else if (s >= 50 && s < 60)
		return 'D';
	else
		return 'F';

}

int import_data(RECORD dataset[], char *filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	char delimiters[] = ",\n\r";
	char line[100];
	int n = 0;
	char *token = NULL;
	while (fgets(line, sizeof(line), fp) != NULL) {
		token = (char*) strtok(line, delimiters);
		strcpy(dataset[n].name, token);
		token = (char*) strtok(NULL, delimiters);
		dataset[n].score = atof(token);
		n++;

	}
	fclose(fp);
	return n;
}

REPORT report_data(RECORD dataset[], int n, char *filename) {
	FILE *report_file;
	report_file = fopen("reports.txt", "w");
	REPORT report = { };
	if (n < 1)
		return report;
	else {
		int i;
		float mean = 0;
		float stddv = 0;
		for (i = 0; i < n; i++) {
			fprintf(report_file, "%s,%c\n", dataset[i].name,
					letter_grade(dataset[i].score));
		}
		for (i = 0; i < n; i++) {
			mean += dataset[i].score;
			stddv += dataset[i].score * dataset[i].score;

		}
		mean = mean / n;
		stddv = sqrt(stddv / n - mean * mean);
		report.count = n;
		report.mean = mean;
		report.stddev = stddv;

	}

	return report;
}
