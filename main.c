#include <TXLib.h>
#include <stdio.h>

#include "ui.h"
#include "solvers.h"
#include "test_system.h"

int main()
{
    printf("¬ведите коэффициенты квадратного уравнени€ в следующем формате:\n");
    printf("a b c\n");

    double a = 0, b = 0, c = 0;
    double d = 0;
    double solutions[2] = {NAN, NAN};

    get_coeffs(&a, &b, &c);

    ai_moment();

    states state = solve_square_equation(solutions, a, b, c, &d);

    print_solutions(state, solutions);

    is_exact_solutions(a, b, c, d);

    //std_test();

    return 0;
}








