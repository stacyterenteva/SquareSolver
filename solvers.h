#ifndef SOLVERS_H
#define SOLVERS_H

#include "constants.h"

States solve_square_equation(Parameters* square_parameters); /*solve_square_equation: получает на вход указатель на структуру с коэффициентами, дискриминантом, пустым массивом с корнями,
вычисляет корни уравнения, изменяет их значения в структуре, возвращает число решений */

States solve_linear_equation(Parameters* square_parameters); /*solve_linear_equation: получает на вход указатель на структуру, с коэффициентами, дискриминантом, пустым массивом с корнями
решает уравнение в случае вырождения в линейное, возвращает число решений*/

double calculate_d(Parameters* square_parameters);

bool is_exact_solutions(double d);

#endif /* SOLVERS_H */
