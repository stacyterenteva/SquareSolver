#include "solvers.h"
#include "common_funcs.h"
#include <math.h>
#include <assert.h>

states solve_square_equation(double solutions[], double a, double b, double c, double* d)
{
    assert(d);
    assert(finite(a));
    assert(finite(b));
    assert(finite(c));

    if (is_equal(a, 0))
        return solve_linear_equation(solutions, b, c);

    *d = calculate_d(a, b, c);
    if (*d < 0)
        return NO_ROOTS;
    else if (is_equal(*d, 0)) {
        solutions[0] = -b / (2 * a);
        return ONE_ROOT;
    }
    else {
       solutions[0] = (-b + sqrt(*d)) / (2 * a);
       solutions[1] = (-b - sqrt(*d)) / (2 * a);
       return TWO_ROOTS;
    }
}

states solve_linear_equation(double solutions[], double b, double c)
{
    assert(finite(b));
    assert(finite(c));

    if (is_equal(b, 0)) {
        if (is_equal(c, 0)) {
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

double calculate_d(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

