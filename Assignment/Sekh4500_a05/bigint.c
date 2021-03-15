/*
 -------------------------------------
 File:    bigint.c
 Project: sekh4500_a05_q2
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-02-26
 -------------------------------------
 */

#include "bigint.h"

BIGINT bigint(char *p) {
	BIGINT bn = { 0 };
	if (p == NULL)
		return bn;
	else if (!(*p >= '0' && *p <= '9')) { // not begin with digits
		return bn;
	} else if (*p == '0' && *(p + 1) == '\0') { // just "0"
		insert_end(&bn.start, &bn.end, new_node(*p - '0'));
		return bn;
	} else {
		while (*p) {
			if (*p >= '0' && *p <= '9') {
				insert_end(&bn.start, &bn.end, new_node(*p - '0'));
			} else {
				clean_bigint(&bn);
				break;
			}
			p++;
		}
		return bn;
	}
}

void display_bigint(BIGINT bignumber) {
	NODE *ptr = bignumber.start;
	while (ptr != NULL) {
		printf("%d", ptr->data);
		ptr = ptr->next;
	}
}

void clean_bigint(BIGINT *bignumberp) {
	clean(&bignumberp->start, &bignumberp->end);
}

BIGINT add(BIGINT op1, BIGINT op2) {
	BIGINT sum = bigint(NULL);

	if (op1.start == NULL || op2.start == NULL)
		return sum;

	NODE *curr1 = op1.end;
	NODE *curr2 = op2.end;

	int temp_sum = 0;
	int carry = 0;

	// OR not AND since one may be longer than the other
	while (curr1 != NULL || curr2 != NULL) {
		// Curr sum is sum of both numbers, plus the carry
		temp_sum = carry + (curr1 != NULL ? curr1->data : 0)
				+ (curr2 != NULL ? curr2->data : 0);
		carry = temp_sum;
		carry = (carry >= 10) ? 1 : 0;  // Carry will only be 1 or 0
		temp_sum = (carry == 1) ? temp_sum - 10 : temp_sum; // Sub 10 if theres a carry
		// Insert at front of sum list, as we are working backwards
		// through the additions
		insert_start(&sum.start, &sum.end, new_node(temp_sum));
		// Move backwards in lists if they have remaining elements
		curr1 = (curr1 != NULL) ? curr1->prev : curr1;
		curr2 = (curr2 != NULL) ? curr2->prev : curr2;
	}
	// Add carry if there is a carry leftover
	if (carry > 0)
		insert_start(&sum.start, &sum.end, new_node(1));

	return sum;

	return sum;
}

BIGINT Fibonacci(int n) {
	if (n <= 2) {
		return bigint("1");
	} else {
		BIGINT temp = bigint(NULL);  // Prev prev num
		BIGINT f1 = bigint("1");  // Prev num
		BIGINT f2 = bigint("1");  // Total/Curr num

		/*
		 printf("--> f1: ");
		 display_bigint(f1);
		 printf("\n--> f2: ");
		 display_bigint(f2);
		 printf("\n");
		 */

		BIGINT *temp_prev = &temp;
		BIGINT *f1_prev = &f1;
		// your implementation of iterative algorithm for Fibonacci number
		for (int i = 3; i <= n; i++) {
			temp = f2;

			/*
			 printf("--> Adding ");
			 display_bigint(f1);
			 printf(" and ");
			 display_bigint(f2);
			 printf("\n");
			 */

			f2 = add(f1, f2);
			//clean_bigint(f1_prev);
			f1 = temp;
			//clean_bigint(temp_prev);

			/*
			 printf("--> [%d] ", i);
			 display_bigint(f2);
			 printf("\n");
			 */
		}

		return f2;
	}
}
