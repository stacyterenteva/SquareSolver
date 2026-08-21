#include "common_funcs.h"
#include <math.h>
#include <stdio.h>


const double eps = 1e-9;

bool is_equal(double a, double b)
{
    return fabs(a - b) < 1e-9;
}


void clean_buf()
{
while (getchar() != '\n') {
        }
}

bool is_perfect_square(double n) {
    return is_equal(sqrt(n), (int) sqrt(n));
}



