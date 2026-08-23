#include <math.h>
#include <assert.h>

#include "solvers.h"
#include "common_funcs.h"

States solve_square_equation(Parameters* square_parameters)
{
    assert(square_parameters);

    if (is_equal(square_parameters->a, 0))
        return solve_linear_equation(square_parameters);

    square_parameters->d = calculate_d(square_parameters);

    if (square_parameters->d < 0) {
        return NO_ROOTS;
    }
    else if (is_equal(square_parameters->d, 0)) {
        square_parameters->roots[0] = -square_parameters->b / (2 * square_parameters->a);
        return ONE_ROOT;
    }
    else {
       square_parameters->roots[0] = (-square_parameters->b + sqrt(square_parameters->d)) / (2 * square_parameters->a);
       square_parameters->roots[1] = (-square_parameters->b - sqrt(square_parameters->d)) / (2 * square_parameters->a);
       return TWO_ROOTS;
    } //TODO KOREN IZ 14 TIYZHELO BVRAT DVA RAZA
}

States solve_linear_equation(Parameters* square_parameters)
{
    assert(finite(square_parameters->b));
    assert(finite(square_parameters->c));

    if (is_equal(square_parameters->b, 0)) {
        if (is_equal(square_parameters->c, 0)) {
            return ANY_ROOTS; //любое решение
        }
        else {
            return NO_ROOTS; //нет решений
        }
    }
    else {
        square_parameters->roots[0] = square_parameters->c / square_parameters->b;
        return ONE_ROOT;
    }
}

double calculate_d(Parameters* square_parameters)
{
    return square_parameters->b * square_parameters->b - 4 * square_parameters->a * square_parameters->c;
}

bool is_exact_solutions(double d)
{
    return is_perfect_square(d);
}
