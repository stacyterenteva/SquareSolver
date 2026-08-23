#include <TXLib.h>
#include <stdio.h>
#include <unistd.h>

#include "ui.h"
#include "solvers.h"
#include "constants.h"
#include "common_funcs.h"

int main()
{
    int flag = 0;

    Parameters square_parameters = {0, 0, 0, 0, {NAN, NAN}};

    user_greeting(BEGINING);

    scanf("%d", &flag);
    clean_buf();

    switch (flag) {
        case SCIENCE: {
            user_greeting(IN_MODE);

            get_coeffs(&square_parameters.a,
                       &square_parameters.b,
                       &square_parameters.c);

            States state = solve_square_equation(&square_parameters);
            print_solutions(state, square_parameters.roots);

            break;
        }
        case HELPER: {
            user_greeting(IN_MODE);

            get_coeffs(&square_parameters.a,
                       &square_parameters.b,
                       &square_parameters.c);

            States state = solve_square_equation(&square_parameters);
            int exact_status = is_exact_solutions(square_parameters.d);

            print_exact_solutions(state, exact_status, square_parameters);

            break;
        }
        default:
            printf("Œÿ»¡ ¿\n");
            break;
    }
    return 0;
}



