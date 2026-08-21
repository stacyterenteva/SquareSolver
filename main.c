#include <TXLib.h>
#include <stdio.h>
#include "ui.h"
#include "solvers.h"
#include "common_funcs.h"

int main()
{

    printf("¬ведите коэффициенты квадратного уравнени€ в следующем формате:\n");
    printf("a b c\n");

    double a = 0, b = 0, c = 0;
    double solutions[2] = {};
    get_coeff(&a, &b, &c);

    ai_moment();

    states state = solve_square_equation(solutions, a, b, c);

    print_solutions(state, solutions);

    if (!is_D_exact(a, b, c))
        print_exact_solutions(a, b, c);

    return 0;
}








