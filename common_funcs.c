#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <assert.h>

#include "common_funcs.h"

// TODO: CONSTANT_EPS
const double eps = 1e-9;

bool is_equal(double a, double b)
{
    return (fabs(a - b) < eps);
}

void clean_buf()
{
    // NOTE: maybe UB!
    while (getchar() != '\n') {
    }
}

bool is_perfect_square(double n)
{
    if (n < 0) {
        return false;
    }
    // TODO: sqrt_n = ...
    return is_equal(sqrt(n), (int) sqrt(n));
}

void slow_print(char string[])
{
    assert(string);

    for (int i = 0; string[i] != '\0'; i++) {
        putchar(string[i]);
        // TODO: magic number
        Sleep(40);
    }
}




