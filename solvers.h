#ifndef SOLVERS_H
#define SOLVERS_H

#include "constants.h"

States solve_square_equation(Parameters* square_parameters); /*solve_square_equation: получает на вход пустой массив на 2 элемента
и коэффициенты уравнения, вычисляет корни уравнения, добавляет их в s, возвращает число решений */

States solve_linear_equation(Parameters* square_parameters); /*solve_linear_equation: получает на вход 2 коэффициента и пустой массив,
решает уравнение в случае вырождения в линейное, возвращает 0 - если решение любое число, 1 - если нет решений,
2 - если решение одно, а также массив в котором находится решение, если оно есть и 0 если ничего нет*/

double calculate_d(Parameters* square_parameters);

bool is_exact_solutions(double d);

#endif /* SOLVERS_H */
