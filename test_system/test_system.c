#include <TXLib.h>
#include <math.h>
#include <stdio.h>

#include "test_system.h"
#include "../constants.h"
#include "../common_funcs.h"
#include "../solvers.h"

struct test {
    int coeffs[3];
    States state;
    double roots[AMT_ROOTS];
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

const int amt_tests = sizeof(tests) / sizeof(test);

int main()
{
    for (int test_number = 0; test_number < amt_tests; test_number++) {
        double a = 0, b = 0, c = 0;
        double d = 0;

        a = tests[test_number].coeffs[0];
        b = tests[test_number].coeffs[1];
        c = tests[test_number].coeffs[2];
        Parameters test_parameters = {a, b, c, d, {NAN, NAN}};

        if (!is_completed(test_parameters, test_number)) {
            printf("#%d не пройден\n", test_number + 1);
            printf("Должны были получить: %.10g, %.10g, %d\n", tests[test_number].roots[0],
                                                           tests[test_number].roots[1],
                                                           tests[test_number].state);
            printf("Получили: %.10g, %.10g, %d\n", test_parameters.roots[0],
                                               test_parameters.roots[1],
                                               solve_square_equation(&test_parameters));
        }
        printf("#%d пройден\n", test_number + 1);
    }


}

bool is_completed(Parameters test_parameters, int test_number)
{
        States test_state = solve_square_equation(&test_parameters);
        switch(test_state) {
            case ANY_ROOTS:
            case NO_ROOTS:
                return (test_state == tests[test_number].state) ? 1 : 0;
                break;
            case ONE_ROOT:
                return (test_state == tests[test_number].state && is_equal(tests[test_number].roots[0], test_parameters.roots[0]));
                break;
            case TWO_ROOTS:
                return (test_state == tests[test_number].state
                        && is_equal(tests[test_number].roots[0], test_parameters.roots[0])
                        && is_equal(tests[test_number].roots[1], test_parameters.roots[1]));
                break;
            default:
                return 0;
                break;
        }
        return 0;
}

