#include <TXLib.h>
#include <stdio.h>
#include <unistd.h>

#include "ui.h"
#include "solvers.h"
#include "constants.h"
#include "common_funcs.h"
#include "trainer.h"

int main()
{
    Modes mode_flag = SCIENCE;

    Parameters square_parameters = {.a = 0, .b = 0, .c = 0, .d = 0, .roots = {NAN, NAN}};

    user_greeting(BEGINING);

    scanf("%d", (int*) &mode_flag);
    clean_buf();

    switch (mode_flag) {
        case SCIENCE: {
            user_greeting(IN_MODE);
            get_coeffs(&square_parameters.a,
                       &square_parameters.b,
                       &square_parameters.c);

            ai_moment();

            States state = solve_square_equation(&square_parameters);
            print_solutions(state, square_parameters.roots);
            break;
        }
        case HELPER: {
            user_greeting(IN_MODE);

            get_coeffs(&square_parameters.a,
                       &square_parameters.b,
                       &square_parameters.c);

            ai_moment();

            States state = solve_square_equation(&square_parameters);
            Exactness exact_status = (Exactness) is_exact_solutions(square_parameters.d);

            print_exact_solutions(state, exact_status, square_parameters);
            break;
        }
        case TRAINER:
            trainer_work();
            break;
        default:
            printf("������\n");
            break;
    }
    return 0;
}





