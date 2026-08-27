#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#include "ui.h"
#include "common_funcs.h"
#include "constants.h"


const int MAX_NUM_OF_COEFF = 3;
const int SLEEP_TIME = 0;

bool is_correct(int num_of_coeff, Parameters square_parameters)
{
    int last_char = getchar();
    while (isspace(last_char) && last_char != '\n') {
        last_char = getchar();
    }
    return !(last_char != '\n' || num_of_coeff < MAX_NUM_OF_COEFF || !(finite(square_parameters.a) && finite(square_parameters.b) && finite(square_parameters.c)));
}


void process_incorrect_input(int num_of_coeff, Parameters* square_parameters)
{
    while (!is_correct(num_of_coeff, *square_parameters)) {
        printf("Некорректный ввод\n");
        sleep(SLEEP_TIME);
        printf("Введите коэффициенты квадратного уравнения в следующем формате:\n");
        sleep(SLEEP_TIME);
        printf("a b c\n");
        clean_buf();
        num_of_coeff = scanf("%lf %lf %lf", &(square_parameters->a), &(square_parameters->b), &(square_parameters->c));
    }
}

void get_coeffs(Parameters* square_parameters)
{
    assert(square_parameters);

    int num_of_coeff = scanf("%lf %lf %lf", &(square_parameters->a), &(square_parameters->b), &(square_parameters->c));
    process_incorrect_input(num_of_coeff, square_parameters);

}


void print_solutions(States state, double solutions[])
{
    switch(state) {
        case STATES_NO_ROOTS:
            printf("У уравнения нет решений\n");
            sleep(SLEEP_TIME);
            break;

        case STATES_ONE_ROOT:
            printf("Единственное решение уравнения: %g", solutions[0]);
            sleep(SLEEP_TIME);
            break;

        case STATES_TWO_ROOTS:
            printf("Первый корень уравнения: %g\n", solutions[0]);
            sleep(SLEEP_TIME);
            printf("Второй корень уравнения: %g\n", solutions[1]);
            sleep(SLEEP_TIME);
            break;

        case STATES_ANY_ROOTS:
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

    // TODO: think about this
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
            assert(0);
    }
}

void print_exact_solutions(States state, bool exact_status, Parameters square_parameters)
{
    if (state != STATES_TWO_ROOTS) {
                print_solutions(state, square_parameters.roots);
    }
    else {
        if (exact_status) {
            printf("(%g + sqrt(%g)) / %g\n", -square_parameters.b, square_parameters.d, 2 * square_parameters.a);
            sleep(SLEEP_TIME);
            printf("(%g - sqrt(%g)) / %g\n", -square_parameters.b, square_parameters.d, 2 * square_parameters.a);
            sleep(SLEEP_TIME);
        }
        else {
            printf("%g\n", square_parameters.roots[0]);
            sleep(SLEEP_TIME);
            printf("%g\n", square_parameters.roots[1]);
            sleep(SLEEP_TIME);
        }
    }
}


void user_greeting(Greeting mode)
{
    switch(mode) {
        case GREETING_BEGINING:
            printf("Наша программа работает в 3 режимах:\n");
            sleep(SLEEP_TIME);
            printf("Научном(1), учебном(2) и тренировочном(3), чтобы выбрать режим нажмите соответствующую клавишу\n");
            break;
        case GREETING_IN_MODE:
            printf("Введите коэффициенты в следующем формате:\n");
            sleep(SLEEP_TIME);
            printf("a b c\n");
            break;
        default:
            assert(0 && "Unreachable");
            break;
    }
}


