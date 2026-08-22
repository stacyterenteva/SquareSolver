#ifndef UI_H
#define UI_H

#include "constants.h"

bool is_correct(int amt_coeff, double a, double b, double c);
void get_coeffs(double* a, double* b, double* c);
void print_solutions(states state, double solutions[]);
void print_exact_solutions(double a, double b, double d);
void ai_moment();
void print2_exact_solutions(double a, double b, double c, double d, bool is_exact_solution);

#endif /* UI_H */
