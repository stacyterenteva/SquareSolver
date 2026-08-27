#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "ui.h"
#include "solvers.h"
#include "constants.h"
#include "common_funcs.h"
#include "trainer.h"


int main()
{
    Modes mode_flag = MODES_SCIENCE;

    Parameters square_parameters =
        {.a = NAN, .b = NAN, .c = NAN, .d = NAN, .roots = {NAN, NAN}};

    user_greeting(GREETING_BEGINING);

    scanf("%d", (int*) &mode_flag);
    clean_buf();

    switch (mode_flag) {
        case MODES_SCIENCE: {
            user_greeting(GREETING_IN_MODE);
            get_coeffs(&square_parameters);

            ai_moment();

            States state = solve_square_equation(&square_parameters);
            print_solutions(state, square_parameters.roots);
            break;
        }
        case MODES_HELPER: {
            user_greeting(GREETING_IN_MODE);

            get_coeffs(&square_parameters);

            ai_moment();

            States state = solve_square_equation(&square_parameters);
            bool exact_status = is_exact_solutions(square_parameters.d);

            print_exact_solutions(state, exact_status, square_parameters);
            break;
        }
        case MODES_TRAINER:
            trainer_work();
            break;
        default:

            printf("Ошибка\n");
            return EXIT_FAILURE;
            break;
    }

    return EXIT_SUCCESS;
}





