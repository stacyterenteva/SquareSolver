#include "solvers.h"
#include "common_funcs.h"
#include <math.h>
#include <assert.h>

states solve_square_equation(double solutions[], double a, double b, double c)
{
    assert(finite(a));
    assert(finite(b));
    assert(finite(c));

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
    assert(finite(b));
    assert(finite(c));

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

double D(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

bool is_D_exact(double a, double b, double c)
{
    return is_zero(sqrt(D(a, b, c)) - ((int) sqrt(D(a, b, c))));
}
