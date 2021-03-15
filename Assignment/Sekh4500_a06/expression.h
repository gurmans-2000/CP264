/*
 -------------------------------------
 File:    expression.h
 Project: sekh4500_a06
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2021-03-04
 -------------------------------------
 */

#ifndef SRC_EXPRESSION_H_
#define SRC_EXPRESSION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"
#include "stack.h"
#include "queue.h"
/*
 * convert infix expression in string to postfix expression represented by QUEUE and return the postfix expression queue.
 */
QUEUE infix_to_postfix(char *infixstr);

/*
 * evaluate and returns the value postfix expression passed by queue.
 */
int evaluate_postfix(QUEUE queue);

/*
 * evaluate and return the value of prefix expression passed by string infixstr, using infix_to_postfix() and evaluate_postfix() functions.
 */
int evaluate_prefix(char *infixstr);

#endif /* SRC_EXPRESSION_H_ */
