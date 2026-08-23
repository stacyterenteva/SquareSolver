#ifndef UI_H
#define UI_H

#include "constants.h"

bool is_correct(int amt_coeff, double a, double b, double c);
void get_coeffs(double* a, double* b, double* c);
void print_solutions(States state, double solutions[]);
void ai_moment();
void print_exact_solutions(States state, int exact_status, Parameters square_parameters);
void user_greeting(Greeting mode);

#endif /* UI_H */
