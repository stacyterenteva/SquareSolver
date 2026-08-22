#include <TXLib.h>
#include <stdio.h>
#include <unistd.h>

#include "ui.h"
#include "solvers.h"
#include "constants.h"
#include "common_funcs.h"

void is_exact_solutions(double a, double b, double c, double d);

int main()
{
    printf("¬ведите коэффициенты квадратного уравнени€ в следующем формате:\n");
    sleep(2);
    printf("a b c\n");
    sleep(2);

    double a = 0, b = 0, c = 0;

    get_coeffs(&a, &b, &c);

    parameters square_parameters = {a, b, c, 0, {NAN, NAN}};

    ai_moment();

    states state = solve_square_equation(&square_parameters);

    print_solutions(state, square_parameters.roots);

    bool is_exact_solution = is_exact_solutions(square_parameters.d);
    print2_exact_solutions(square_parameters.a, square_parameters.b, square_parameters.c, square_parameters.d, is_exact_solution);

    return 0;
}
