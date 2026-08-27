#define TX_COMPILED
#include <TXLib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "common_funcs.h"


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

void slow_print(const char string[])
{
    assert(string);

    for (int i = 0; string[i] != '\0'; i++) {
        putchar(string[i]);
        txSleep(SLEEP_TIME_FOR_SLOW_PRINT);
    }
}

void getline(char* string, unsigned int max_len)
{
    assert(string);

    unsigned int i = 0;
    int c = '\0'; //NOTE Почему ворнинг и как происходит автоматическое изменение типа
    while (i < max_len && (c = getchar()) != EOF && c != '\n') {
        string[i] = (char)c;
        i++;
    }
}




