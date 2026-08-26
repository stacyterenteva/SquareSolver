#include <TXLib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "common_funcs.h"

const int SLEEP_TIME_FOR_SLOW_PRINT = 40;

const double EPS = 1e-9;

bool is_equal(double a, double b)
{
    return (fabs(a - b) < EPS);
}

void clean_buf()
{
    while (getchar() != '\n') {
        ;
    }
}

bool is_perfect_square(double n)
{
    if (n < 0) {
        return false;
    }
    double sqrt_n = sqrt(n);
    return is_equal(sqrt_n, (int) sqrt_n);
}

void slow_print(const char string[])
{
    assert(string);

    for (int i = 0; string[i] != '\0'; i++) {
        putchar(string[i]);
        txSleep(SLEEP_TIME_FOR_SLOW_PRINT);
    }
}

void getline(char* string, int max_len)
{
    int i = 0;
    while (i < max_len && (c = getchar()) != '\n') {
        string[i] = c;
        i++;
    }
}




