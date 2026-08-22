#ifndef UI_H
#define UI_H

#include "states.h"

bool is_correct(int amt_coeff, double a, double b, double c);
void get_coeffs(double* a, double* b, double* c);
void print_solutions(states state, double solutions[]);
void print_exact_solutions(double a, double b, double c);
void ai_moment();
void is_exact_solutions(double a, double b, double c, double d);

#endif /* UI_H */
