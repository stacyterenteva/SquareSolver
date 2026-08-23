#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#include "ui.h"
#include "common_funcs.h"
#include "constants.h"


const int MAX_AMT_COEFF = 3;
const int SLEEP_TIME = 0;

bool is_correct(int amt_coeff, double a, double b, double c)
{
    int last_char = getchar();
    while (isspace(last_char) && last_char != '\n') {
        last_char = getchar();
    }
    return !(last_char != '\n' || amt_coeff < MAX_AMT_COEFF || !(finite(a) && finite(b) && finite(c)));
}


void process_incorrect_input(int amt_coeff, double* a, double* b, double* c)
{
    while (!is_correct(amt_coeff, *a, *b, *c)) {
        printf("Некорректный ввод\n");
        sleep(SLEEP_TIME);
        printf("Введите коэффициенты квадратного уравнения в следующем формате:\n");
        sleep(SLEEP_TIME);
        printf("a b c\n");
        clean_buf();
        amt_coeff = scanf("%lf %lf %lf", a, b, c);
    }
}

void get_coeffs(double* a, double* b, double* c)
{
    assert(a);
    assert(b);
    assert(c);
    assert(a != b);
    assert(b != c);
    assert(a != c);

    int amt_coeff = scanf("%lf %lf %lf", a, b, c);
    process_incorrect_input(amt_coeff, a, b, c);

}


void print_solutions(States state, double solutions[])
{
    switch(state) {
        case NO_ROOTS:
            printf("У уравнения нет решений\n");
            sleep(SLEEP_TIME);
            break;
        case ONE_ROOT:
            printf("Единственное решение уравнения: %g", solutions[0]);
            sleep(SLEEP_TIME);
            break;
        case TWO_ROOTS:
            printf("Первый корень уравнения: %g\n", solutions[0]);
            sleep(SLEEP_TIME);
            printf("Второй корень уравнения: %g\n", solutions[1]);
            sleep(SLEEP_TIME);
            break;
        case ANY_ROOTS:
            printf("Любое число - решение уравнения\n");
            sleep(SLEEP_TIME);
            break;
        default:
            printf("ОШИБКА\n");
            sleep(SLEEP_TIME);
            break;
    }
}

void ai_moment() {
    int phrase_number = rand() % 8;

    switch(phrase_number) {
        case 0:
            printf("Это очень красивые коэффициенты)\n");
            sleep(SLEEP_TIME);
            break;
        case 1:
            printf("RTRTRTRTRTRTRT\n");
            sleep(SLEEP_TIME);
            break;
        case 2:
            printf("Это очень красивые коэффициенты)\n");
            sleep(SLEEP_TIME);
            break;
        case 3:
            printf("У вас определенно есть вкус в числах!\n");
            sleep(SLEEP_TIME);
            break;
        case 4:
            printf("Сейчас решим это интереснейшее уравнение\n");
            sleep(SLEEP_TIME);
            break;
        case 5:
            printf("У вас определенно есть вкус в числах!\n");
            sleep(SLEEP_TIME);
            break;
        case 6:
            printf("Сейчас решим это интереснейшее уравнение\n");
            sleep(SLEEP_TIME);
            break;
        case 7:
            printf("Это очень красивые коэффициенты)\n");
            sleep(SLEEP_TIME);
            break;
        default:
            printf("ERROR\n");
    }
}

void print_exact_solutions(States state, Exactness exact_status, Parameters square_parameters)
{
    if (state != TWO_ROOTS) {
                print_solutions(state, square_parameters.roots);
    }
    else {
        switch(exact_status) {
            case NOT_EXACT:
                printf("(%g + sqrt(%g)) / %g\n", -square_parameters.b, square_parameters.d, 2 * square_parameters.a);
                sleep(SLEEP_TIME);
                printf("(%g - sqrt(%g)) / %g\n", -square_parameters.b, square_parameters.d, 2 * square_parameters.a);
                sleep(SLEEP_TIME);
                break;
            case EXACT:
                printf("%g\n", square_parameters.roots[0]);
                sleep(SLEEP_TIME);
                printf("%g\n", square_parameters.roots[1]);
                sleep(SLEEP_TIME);
                break;
            default:
                printf("Ошибка\n");
                break;
            }
    }
}

void user_greeting(Greeting mode)
{
    switch(mode) {
        case BEGINING:
            printf("Наша программа работает в 3 режимах:\n");
            sleep(SLEEP_TIME);
            printf("Научном(1), учебном(2) и тренировочном(3), чтобы выбрать режим нажмите соответствующую клавишу\n");
            break;
        case IN_MODE:
            printf("Введите коэффициенты в следующем формате:\n");
            sleep(SLEEP_TIME);
            printf("a b c\n");
            break;
        case TRAIN_MODE:
            printf("Отлично, вы выбрали тренировочный режим\n");
            printf("Сейчас я сгенерирую тест состоящий из 5 вопросов\n");
            printf("Каждый вопрос будет улучшать ваш навык квадратных уравнений\n");
            printf("x1 x2\n");
            break;
        default:
            printf("ОШИБКА");
            break;
    }
}


