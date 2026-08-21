#include <TXLib.h>
#include "test_system.h"
#include <math.h>
#include "states.h"
#include "common_funcs.h"
#include "solvers.h"
#include <stdio.h>

bool is_completed(double* program_roots, double a, double b, double c, int i, double* d);
const int amt_roots = 2;
const int amt_tests = 7;
struct test {
    int coeffs[3];
    states state;
    double roots[amt_roots];
};

test tests[] = {
    {{0, 0, 0}, ANY_ROOTS, {NAN, NAN}},
    {{0, 0, 0}, NO_ROOTS,  {NAN, NAN}},
    {{0, 1, 2}, ONE_ROOT,  {2, NAN}},
    {{1, 5, 6}, TWO_ROOTS, {-2, -3}},
    {{1, 3, -7}, TWO_ROOTS, {(-3 + sqrt(37)) / (2), (-3 - sqrt(37)) / (2)}},
    {{1, 1, 1}, NO_ROOTS,  {NAN, NAN}},
    {{1, 2, 1}, ONE_ROOT,  {-1, NAN}}
};


void std_test()
{

    for (int i = 0; i < amt_tests; i++) {
        bool test_flag = 1;
        int a = 0, b = 0, c = 0;
        double d = 0;
        double program_roots[amt_roots];
        a = tests[i].coeffs[0];
        b = tests[i].coeffs[1];
        c = tests[i].coeffs[2];
        if (!is_completed(program_roots, a, b, c, i, &d)) {
            test_flag = 0;
            printf("#%d не пройден\n", i);
            printf("Должны были получить: %.10g, %.10g\n", tests[i].roots[0],
                                                           tests[i].roots[1]);
            printf("Получили: %.10g, %.10g\n", program_roots[0], program_roots[0]);
        }
        printf("%d %d\n", i, test_flag);
    }


}

bool is_completed(double* program_roots, double a, double b, double c, int i, double* d)
{
        states test_state = solve_square_equation(program_roots, a, b, c, d);
        switch(test_state) {
            case ANY_ROOTS:
            case NO_ROOTS:
                return (test_state == tests[i].state) ? 1 : 0;
                break;
            case ONE_ROOT:
                return (test_state == tests[i].state && is_equal(tests[i].roots[0], program_roots[0]));
                break;
            case TWO_ROOTS:
                return (test_state == tests[i].state && is_equal(tests[i].roots[0], program_roots[0]) && is_equal(tests[i].roots[1], program_roots[1]));
                break;
            default:
                return 0;
                break;
        }
        return 0;
}
