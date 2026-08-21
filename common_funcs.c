#include "common_funcs.h"
#include <math.h>
#include <stdio.h>


const double eps = 1e-9;

bool is_zero(double n)
{
    return (fabs(n) < eps);
}

void clean_buf()
{
while (getchar() != '\n') {
        }
}

bool is_perfect_square(double n) {
    return is_zero(sqrt(n) - (int) sqrt(n));
}


