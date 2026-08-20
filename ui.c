#include <stdio.h>
#include "ui.h"
#include <math.h>
#include
const int max_amt_coeff = 3;

bool is_correct(int amt_coeff, double a, double b, double c)
{
    return !(amt_coeff < max_amt_coeff || !(finite(a) && finite(b) && finite(c)));
}

void get_coeff(double* a, double* b, double* c)
 {
    int amt_coeff = scanf("%lf %lf %lf", a, b, c);
    while (!is_correct(amt_coeff, *a, *b, *c)) {
        printf("Некорректный ввод\n");
        printf("Введите коэффициенты квадратного уравнения в следующем формате:\n");
        printf("a b c\n");
        while (getchar() != '\n') {
        }
        amt_coeff = scanf("%lf %lf %lf", a, b, c);
    }
 }


void print_solutions(states state, double solutions[])
{
    switch(state) {
            case NO_ROOTS:
                printf("У уравнения нет решений\n");
                break;
            case ONE_ROOT:
                printf("Единственное решение уравнения: %g", solutions[0]);
                break;
            case TWO_ROOTS:
                printf("Первый корень уравнения: %g\n", solutions[0]);
                printf("Второй корень уравнения: %g\n", solutions[1]);
                break;
            case ANY_ROOTS:
                printf("Любое число - решение уравнения\n");
                break;
            default:
                printf("ОШИБКА\n");
                break;
        }
}



