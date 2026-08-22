#include <TXLib.h>
#include <stdio.h>
#include <unistd.h>

#include "ui.h"
#include "solvers.h"
#include "constants.h"
#include "common_funcs.h"

int main()
{
    int flag = 0;
    double a = 0, b = 0, c = 0;
    Parameters square_parameters = {a, b, c, 0, {NAN, NAN}};
    printf("Наша программа работает в 2 режимах:\n");
    printf("Научном(1) и учебном(2), чтобы выбрать режим нажмите соответствующую клавишу\n");
    sleep(2);
    scanf("%d", &flag);
    clean_buf();
    switch (flag) {
        case SCIENCE: {
            printf("Введите коэффициенты в следующем формате:\n");
            sleep(2);
            printf("a b c\n");
            sleep(2);

            get_coeffs(&a, &b, &c);

            States state = solve_square_equation(&square_parameters);
            print_solutions(state, square_parameters.roots);
            break;
        }
        case HELPER: {
            printf("Введите коэффициенты в следующем формате:\n");
            sleep(2);
            printf("a b c\n");
            sleep(2);

            get_coeffs(&a, &b, &c);

            int exact_status = is_exact_solutions(square_parameters.d);
            solve_square_equation(&square_parameters);
            print_exact_solutions(exact_status, square_parameters);
            break;
        }
        default:
            printf("ОШИБКА\n");
            break;
    }
    return 0;
}
