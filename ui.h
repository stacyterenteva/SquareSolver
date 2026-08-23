#ifndef UI_H
#define UI_H

#include "constants.h"

enum Greeting {
    BEGINING,
    IN_MODE,
    TRAIN_MODE
};

bool is_correct(int amt_coeff, double a, double b, double c);
void get_coeffs(double* a, double* b, double* c);
void process_incorrect_input(int amt_coeff, double* a, double* b, double* c);

void print_solutions(States state, double solutions[]);
void print_exact_solutions(States state,
                           Exactness exact_status,
                           Parameters square_parameters);

void ai_moment();
void user_greeting(Greeting mode);

#endif /* UI_H */
