#include <TXLib.h>
#include <stdio.h>

#include "constants.h"
#include "ui.h"
#include "solvers.h"
#include "trainer.h"
#include "common_funcs.h"


void trainer_work()
{
    int training_report[AMT_QUESTIONS] = {};
    Test tests[AMT_QUESTIONS] = {
        {.question = "Выберите правильную формулу дискриминанта:\n"
                     "1)b - 4ac\n"
                     "2)c^2 - 4ab\n"
                     "3)b^2 - 4ac\n"
                     "4)b^2 - 2ac", .answer = 3},
        {.question = "Решите уравнение x^2 - 26x + 169 = 0, не по формулам,"
        " а сворачивая в полный квадрат", .answer = 13},
        {.question = "Решите уравнение 2x^2 - 11x + 14 = 0", .answer = -3.5}};

    for (int question_number = 0; question_number < AMT_QUESTIONS; question_number++) {
        trainer_asks(question_number, training_report, tests);
    }

    int amt_correct_answer = count_correct_answers(training_report);

    print_level(amt_correct_answer);
}

void trainer_asks(int question_number, int training_report[], Test* tests)
{
    double user_answer = 0;
    printf("%s\n%s", tests[question_number].question, "Введите правильный ответ, если вы получили два значения, выведите наибольшее\n");
    scanf("%lg", &user_answer);
    if (is_equal(user_answer, tests[question_number].answer)) {
        training_report[question_number] = 1;
    }
}

void print_level(int amt_correct_answers)
{
    switch (amt_correct_answers) {
        case 0:
            printf("Вы дали 0 правильных ответов, ваш уровень: Полный ноль\n");
            printf("Не расстраивайтесь, ведь с нашими тестами вы легко его поднимите\n");
            break;
        case 1:
            printf("Вы дали 1 правильный ответ, ваш уровень: Уже что-знаете\n");
            printf("Не расстраивайтесь, ведь с нашими тестами вы легко его поднимите\n");
            break;
        case 2:
            printf("Вы дали 2 правильных ответов, ваш уровень: Уверенный\n");
            printf("Это почти идеал, но всегда можно стремиться к лучшему\n");
            break;
        case 3:
            printf("Вы дали 3 правильных ответа, ваш уровень: Бог квадратных уравнений\n");
            printf("Поздравляем с максимальным результатом!!\n");
            printf("Вы отлично разбираетесь в теме\n");
            break;
        default:
            printf("ОШИБКА\n");
    }
}

int count_correct_answers(int* training_report)
{
    int amt_correct_answers = 0;
    for (int i = 0; i < AMT_QUESTIONS; i++) {
        amt_correct_answers += training_report[i];
    }
    return amt_correct_answers;
}






