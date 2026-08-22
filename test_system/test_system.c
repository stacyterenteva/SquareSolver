#include <TXLib.h>
#include <math.h>
#include <stdio.h>

#include "test_system.h"
#include "../constants.h"
#include "../common_funcs.h"
#include "../solvers.h"

const int amt_roots = 2;

struct test {
    int coeffs[3];
    states state;
    double roots[amt_roots];
};

test tests[] = {
    {{0, 0, 0}, ANY_ROOTS, {NAN, NAN}},
    {{0, 0, 1}, NO_ROOTS,  {NAN, NAN}},
    {{0, 1, 2}, ONE_ROOT,  {2, NAN}},
    {{1, 5, 6}, TWO_ROOTS, {-2, -3}},
    {{1, 3, -7}, TWO_ROOTS, {(-3 + sqrt(37)) / (2), (-3 - sqrt(37)) / (2)}},
    {{1, 1, 1}, NO_ROOTS,  {NAN, NAN}},
    {{1, 2, 1}, ONE_ROOT,  {-1, NAN}}
};

const int amt_tests = 7;

int main()
{

    for (int i = 0; i < amt_tests; i++) {
        bool test_flag = 1;
        double a = 0, b = 0, c = 0;
        double d = 0;

        a = tests[i].coeffs[0];
        b = tests[i].coeffs[1];
        c = tests[i].coeffs[2];
        parameters test_parameters = {a, b, c, d, {NAN, NAN}};
        if (!is_completed(test_parameters, i)) {
            test_flag = 0;
            printf("#%d не пройден\n", i + 1);
            printf("Должны были получить: %.10g, %.10g, %d\n", tests[i].roots[0],
                                                           tests[i].roots[1],
                                                           tests[i].state);
            printf("Получили: %.10g, %.10g, %d\n", test_parameters.roots[0],
                                               test_parameters.roots[1],
                                               solve_square_equation(&test_parameters));
        }
        printf("#%d пройден\n", i + 1);
    }


}

bool is_completed(parameters test_parameters, int i)
{
        states test_state = solve_square_equation(&test_parameters);
        switch(test_state) {
            case ANY_ROOTS:
            case NO_ROOTS:
                return (test_state == tests[i].state) ? 1 : 0;
                break;
            case ONE_ROOT:
                return (test_state == tests[i].state && is_equal(tests[i].roots[0], test_parameters.roots[0]));
                break;
            case TWO_ROOTS:
                return (test_state == tests[i].state && is_equal(tests[i].roots[0], test_parameters.roots[0]) && is_equal(tests[i].roots[1], test_parameters.roots[1]));
                break;
            default:
                return 0;
                break;
        }
        return 0;
}

