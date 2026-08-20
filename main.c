#include <TXLib.h>
#include <stdlib.h>
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
    states state = solve_square_equation(solutions, a, b, c);

    print_solutions(state, solutions);
    return 0;
}








