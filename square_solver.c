#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

enum states {
    NO_ROOTS,
    ANY_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};
const double eps = 1e-9;
const int max_amt_coeff = 3;
states solve_square_equation(double solutions[], double a, double b, double c); /*solve_square_equation: получает на вход пустой массив на 2 элемента
 и коэффициенты уравнения, вычисляет корни уравнения, добавляет их в s, возвращает число решений */

states solve_linear_equation(double solutions[], double b, double c); /*solve_linear_equation: получает на вход 2 коэффициента и пустой массив,
решает уравнение в случае вырождения в линейное, возвращает 0 - если решение любое число, 1 - если нет решений,
2 - если решение одно, а также массив в котором находится решение, если оно есть и 0 если ничего нет*/

void print_solutions(states state, double solutions[]);
bool is_zero(double n);
bool is_correct(int amt_coeff, double a, double b, double c);
void get_coeff(double* a, double* b, double* c);

int main()
{

    printf("Введите коэффициенты квадратного уравнения в следующем формате:\n");
    printf("a b c\n");
    double a = 0, b = 0, c = 0;
    double solutions[2] = {};
    get_coeff(NULL, &b, &c);
    states state = solve_square_equation(solutions, a, b, c);

    print_solutions(state, solutions);
    return 0;
}

states solve_square_equation(double solutions[], double a, double b, double c)
{

    if (is_zero(a))
        return solve_linear_equation(solutions, b, c);
    double D = b * b - 4 * a * c;
    if (D < 0)
        return NO_ROOTS;
    else if (is_zero(D)) {
        solutions[0] = -b / (2 * a);
        return ONE_ROOT;
    }
    else {
       solutions[0] = (-b + sqrt(D)) / (2 * a);
       solutions[1] = (-b - sqrt(D)) / (2 * a);
       return TWO_ROOTS;
    }
}

states solve_linear_equation(double solutions[], double b, double c)
{
    if (is_zero(b)) {
        if (is_zero(c)) {
            return ANY_ROOTS; //любое решение
        }
        else {
            return NO_ROOTS; //нет решений
        }
    }

    else {
        solutions[0] = c / b;
        return ONE_ROOT;
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

bool is_zero(double n)
{
    return (fabs(n) < eps);
}

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




