/*
 -------------------------------------
 File:    mysort.h
 Project: sekh4500_a04
 file description
 -------------------------------------
 Author:  Gurman Sekhon
 ID:      181004500
 Email:   sekh4500@mylauirier.ca
 Version  2021-02-09
 -------------------------------------
 */

#ifndef MYSORT_H
#define MYSORT_H

// define enum type BOOLEAN
typedef enum BOOLEAN {
	false, true
} BOOLEAN;

BOOLEAN is_sorted(int *a, int left, int right);
void select_sort(int *a, int left, int right);
void quick_sort(int *a, int left, int right);
void swap(int *x, int *y);

#endif
