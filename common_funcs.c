#include <math.h>
#include <stdio.h>

#include "common_funcs.h"

const double eps = 1e-9;

bool is_equal(double a, double b)
{
    return fabs(a - b) < eps;
}

void clean_buf()
{
    while (getchar() != '\n') {
    }
}

bool is_perfect_square(double n) {
    return is_equal(sqrt(n), (int) sqrt(n));
}



