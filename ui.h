#ifndef UI_H
#define UI_H

#include "constants.h"

bool is_correct(int amt_coeff, double a, double b, double c);
void get_coeffs(double* a, double* b, double* c);
void print_solutions(States state, double solutions[]);
void ai_moment();
void print_exact_solutions(int exact_status, Parameters square_parameters);

#endif /* UI_H */
