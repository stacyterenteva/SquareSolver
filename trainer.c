#include <TXLib.h>
#include <stdio.h>

#include "constants.h"
#include "ui.h"
#include "solvers.h"
#include "trainer.h"
#include "common_funcs.h"
#include "trainer.h"

const char* FIRST_TASK = "Выберите правильную формулу дискриминанта:\n"
                     "1)b - 4ac\n"
                     "2)c^2 - 4ab\n"
                     "3)b^2 - 4ac\n"
                     "4)b^2 - 2ac";
const char* SECOND_TASK = "Решите уравнение x^2 - 26x + 169 = 0, не по формулам, а сворачивая в полный квадрат";
const char* THIRD_TASK = "Решите уравнение 2x^2 - 11x + 14 = 0";
const char* FOURTH_TASK = "Найдите два последовательных натуральных числа, произведение которых равно 156";
const char* FIFTH_TASK = "Вы грабите банк. У вас есть команда из двух шпионов и компьютер, чтобы дистанционно взламывать его системы безопасности. Первый шпион(Петя) \n"
                   "стоит у входа в хранилища, а второй(Вася) у сейфа. Двигаться по хранилищу нельзя, так как их засекут датчики движения. Недавно вы выкрали\n"
                   "пароль от сейфа и отдали его Пете в форме пластикового шара с запиской внутри, он, чтобы отдать его Васе, кидает шар под углом 30 градусов к \n"
                   "горизонту и со скоростью 6 м/c. Проблема в том, что на высоте 2 м расположен лазерный луч, который обязательно засечёт шар и миссия\n"
                   "провалиться. Рассчитайте время, которое у вас есть до момента срабатывания сигнализации, чтобы понять успеет ли ваша программа взломать\n"
                   "микроконтроллер системы сигнализации и принять решение о продолжении миссии. Считайте, что g = 10, а сигнализация работает мгновенно";

void trainer_work()
{
    int training_report[AMT_QUESTIONS] = {};

    Test tests[AMT_QUESTIONS] = {
        {.question = FIRST_TASK, .answer = 3},
        {.question = SECOND_TASK, .answer = 13},
        {.question = THIRD_TASK, .answer = 3.5},
        {.question = FOURTH_TASK, .answer = 12},
        {.question = FIFTH_TASK, .answer = 1}};

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
            printf("Вы дали 1 правильный ответ, ваш уровень: Начинающий\n");
            printf("Не расстраивайтесь, ведь с нашими тестами вы легко его поднимите\n");
            break;
        case 2:
            printf("Вы дали 2 правильных ответа, ваш уровень: Уже что-знаете\n");
            printf("Вы знаете базу, но вам возможно не хватает опыта, продолжайте использовать тренажёр\n");
            break;
        case 3:
            printf("Вы дали 3 правильных ответа, ваш уровень: Середнячок\n");
            printf("Возможно вы неправильно решаете задачи или ошибаетесь по невнимательности\n");
            break;
        case 4:
            printf("Вы дали 4 правильных ответа, ваш уровень: Уверенный\n");
            printf("Это почти идеал, но всегда можно стремиться к лучшему\n");
            printf("Продолжайте пользоваться тренажёром\n");
            break;
        case 5:
            printf("Вы дали 5 правильных ответов, ваш уровень: Бог квадратных уравнений\n");
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






