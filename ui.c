#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

#include "ui.h"
#include "common_funcs.h"
#include "constants.h"

enum choices {
    WANT = 1,
    NO_WANT = 2};

const int max_amt_coeff = 3;

bool is_correct(int amt_coeff, double a, double b, double c)
{
    return !(amt_coeff < max_amt_coeff || !(finite(a) && finite(b) && finite(c)));
}

void get_coeffs(double* a, double* b, double* c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(a != b);
    assert(b != c);
    assert(a != c);

    int amt_coeff = scanf("%lf %lf %lf", a, b, c);
    while (!is_correct(amt_coeff, *a, *b, *c)) {
        printf("Некорректный ввод\n");
        sleep(2);
        printf("Введите коэффициенты квадратного уравнения в следующем формате:\n");
        sleep(2);
        printf("a b c\n");
        sleep(2);
        clean_buf();
        amt_coeff = scanf("%lf %lf %lf", a, b, c);
    }
 }



void print_solutions(states state, double solutions[])
{
    switch(state) {
            case NO_ROOTS:
                printf("У уравнения нет решений\n");
                sleep(2);
                break;
            case ONE_ROOT:
                printf("Единственное решение уравнения: %g", solutions[0]);
                sleep(2);
                break;
            case TWO_ROOTS:
                printf("Первый корень уравнения: %g\n", solutions[0]);
                sleep(2);
                printf("Второй корень уравнения: %g\n", solutions[1]);
                sleep(2);
                break;
            case ANY_ROOTS:
                printf("Любое число - решение уравнения\n");
                sleep(2);
                break;
            default:
                printf("ОШИБКА\n");
                sleep(2);
                break;
        }
}

void print_exact_solutions(double a, double b, double d)
{

    printf("Полученное нами решение не совсем точное\n");
    sleep(2);
    printf("Если вы хотите получить точное решение нажмите 1\n");
    sleep(2);
    printf("Если нет нажмите 2\n");
    sleep(2);
    int user_choice = 0;
    clean_buf();
    scanf("%d", &user_choice);
    switch(user_choice) {
        case WANT:
            printf("(%g + sqrt(%g)) / %g\n", -b, d, 2 * a);
            sleep(2);
            printf("(%g - sqrt(%g)) / %g\n", -b, d, 2 * a);
            sleep(2);
            break;
        case NO_WANT:
            printf("Cпасибо за использование нашей программы, хорошего дня\n");
            sleep(2);
            break;
        default:
            printf("Некорректный ввод\n");
            sleep(2);
            break;
    }
}


void ai_moment() {
    int phrase_number = rand() % 8;
    switch(phrase_number) {
        case 0:
            printf("Это очень красивые коэффициенты)\n");
            sleep(2);
            break;
        case 1:
            printf("RTRTRTRTRTRTRT\n");
            sleep(2);
            break;
        case 2:
            printf("Это очень красивые коэффициенты)\n");
            sleep(2);
            break;
        case 3:
            printf("У вас определенно есть вкус в числах!\n");
            sleep(2);
            break;
        case 4:
            printf("Сейчас решим это интереснейшее уравнение\n");
            sleep(2);
            break;
        case 5:
            printf("У вас определенно есть вкус в числах!\n");
            sleep(2);
            break;
        case 6:
            printf("Сейчас решим это интереснейшее уравнение\n");
            sleep(2);
            break;
        case 7:
            printf("Это очень красивые коэффициенты)\n");
            sleep(2);
            break;
        default:
            printf("ERROR\n");
    }
}

void print2_exact_solutions(double a, double b, double c, double d, bool is_exact_solution) {
    if (!is_exact_solution) {
        printf("Корни данного уравнения комплексные\n");
        sleep(2);
    }
    else {
        if (!is_perfect_square(d))
            print_exact_solutions(a, b, c);
    }
}



