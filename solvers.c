#include "solvers.h"
#include "common_funcs.h"
#include <math.h>

states solve_square_equation(double solutions[], double a, double b, double c)
{

    if (is_zero(a))
        return solve_linear_equation(solutions, b, c);
    double D = b * b - 4 * a * c;
    if (D < 0)
        return NO_ROOTS;
    else if (is_zero(D)) {
        solutions[0] = -b / (2 * a);
        return ONE_ROOT;
    }
    else {
       solutions[0] = (-b + sqrt(D)) / (2 * a);
       solutions[1] = (-b - sqrt(D)) / (2 * a);
       return TWO_ROOTS;
    }
}

states solve_linear_equation(double solutions[], double b, double c)
{
    if (is_zero(b)) {
        if (is_zero(c)) {
            return ANY_ROOTS; //любое решение
        }
        else {
            return NO_ROOTS; //нет решений
        }
    }

    else {
        solutions[0] = c / b;
        return ONE_ROOT;
    }
}
