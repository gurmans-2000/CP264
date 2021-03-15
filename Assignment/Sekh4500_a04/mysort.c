/*
 -------------------------------------
 File:    mysort.c
 Project: sekh4500_a04
 file description
 -------------------------------------
 Author:  Gurman Sekhon
 ID:      181004500
 Email:   sekh4500@mylaurier.ca
 Version  2021-02-09
 -------------------------------------
 */

#include "mysort.h"

BOOLEAN is_sorted(int *a, int left, int right) {
	int *p = a;
	BOOLEAN newsort = true;

	int cmp = *(p + left);
	int value;
	for (int i = left + 1; i <= (right - left); i++) {
		value = *(p + left + i);
		if (value < cmp) {
			newsort = false;
			break;
		} else
			cmp = value;
	}
	return newsort;
}

void select_sort(int *a, int left, int right) {
	int i, j, k;

	for (i = left; i < right; i++) {
		k = i;
		for (j = i + 1; j <= right; j++) {
			if (*(a + j) < *(a + k))
				k = j;
		}
		if (k != i)
			swap(a + k, a + i);
	}
}

void quick_sort(int *a, int left, int right) {
	int key, k, i;
	if (left < right) {
		k = (left + right) / 2;
		key = *(a + k);
		swap(&a[left], &a[k]);
		int j = left;
		int pivot = a[left];
		for (i = left + 1; i <= right; i++) {
			if (a[i] < pivot) {
				swap(&a[i], &a[++j]);
			}
		}
		// swap the left and pivot elements
		swap(&a[left], &a[j]);

		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);
	}
}

void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}
