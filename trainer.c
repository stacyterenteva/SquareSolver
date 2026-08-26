//#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "constants.h"
#include "ui.h"
#include "solvers.h"
#include "trainer.h"
#include "common_funcs.h"
#include "trainer.h"


void trainer_work()
{

    int training_report[AMT_QUESTIONS] = {0, 0, 0, 0, 0};

    FILE *files[MAX_FILES] = {};

    Test first_tests[AMT_TESTS] = {{"", 0}, {"", 0}, {"", 0}, {"", 0}};
    get_file(first_tests, files[0]);

    Test second_tests[AMT_TESTS] = {{"", 0}, {"", 0}, {"", 0}, {"", 0}};
    get_file(second_tests, files[1]);

    Test third_tests[AMT_TESTS] = {{"", 0}, {"", 0}, {"", 0}, {"", 0}};
    get_file(third_tests, files[2]);

    Test fourth_tests[AMT_TESTS] = {{"", 0}, {"", 0}, {"", 0}, {"", 0}};
    get_file(fourth_tests, files[3]);

    Test fifth_tests[1] = {{"", 0}};
    get_question(&fifth_tests[0], files[4]);
    fscanf(files[4], "%lg", &fifth_tests[0].answer);
    fgetc(files[4]);

    trainer_asks(rand() % AMT_TESTS, training_report, first_tests, 0);

    trainer_asks(rand() % AMT_TESTS, training_report, second_tests, 1);

    trainer_asks(rand() % AMT_TESTS, training_report, third_tests, 2);

    trainer_asks(rand() % AMT_TESTS, training_report, fourth_tests, 3);

    trainer_asks(0, training_report, fifth_tests, 4);

    int amt_correct_answer = count_correct_answers(training_report);

    for (int i = 0; i < 5; i++)
        printf("%d ", training_report[i]);
    print_level(amt_correct_answer);

}

void trainer_asks(int question_number, int training_report[], Test tests[], int i)
{
    double user_answer = 0;
    printf("%s\n%s", tests[question_number].question, "Введите правильный ответ, если вы получили два значения, выведите наибольшее\n");
    scanf("%lf", &user_answer);
    training_report[i] = is_equal(user_answer, tests[question_number].answer);
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

void get_file(Test first_tests[], FILE *first_test)
{
    for (int i = 0; i < AMT_TESTS; i++) {
        get_question(&first_tests[i], first_test);
        fscanf(first_test, "%lg", &first_tests[i].answer);
        fgetc(first_test);
    }
}


void get_question(Test* tests, FILE *test)
{
    int ch = 0;
    int i = 0;
    while (i < MAX_AMT_CHARS && (ch = fgetc(test)) != EOF && ch != ';') {
        (tests->question)[i] = (char) ch;
        i++;
    }
}

void open_all_files(FILE *files[])
{
    FILE *first_test = fopen("trainer_fail_base/first_test.csv", "r");
    assert(first_test);
    files[0] = first_test;

    FILE *second_test = fopen("trainer_fail_base/second_test.csv", "r");
    assert(second_test);
    files[1] = second_test;

    FILE *third_test = fopen("trainer_fail_base/third_test.csv", "r");
    assert(third_test);
    files[2] = third_test;

    FILE *fourth_test = fopen("trainer_fail_base/fourth_test.csv", "r");
    assert(fourth_test);
    files[3] = fourth_test;

    FILE *fifth_test = fopen("trainer_fail_base/fifth_test.csv", "r");
    assert(fifth_test);
    files[4] = fifth_test;
}






