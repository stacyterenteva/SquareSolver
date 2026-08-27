#ifndef UI_H
#define UI_H

#include "constants.h"

enum Greeting {
    GREETING_BEGINING,
    GREETING_IN_MODE
};

bool is_correct(int amt_coeff, Parameters square_parameters);
void get_coeffs(Parameters* square_parameters);
void process_incorrect_input(int amt_coeff, Parameters* square_parameters);

void print_solutions(States state, double solutions[]);
void print_exact_solutions(States state,
                           bool exact_status,
                           Parameters square_parameters);

void ai_moment();
void user_greeting(Greeting mode);

#endif /* UI_H */
