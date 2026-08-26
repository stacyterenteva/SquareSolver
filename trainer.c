#include <TXLib.h>
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
    int num_of_correct_answers = 0;

    FILE *files[NUM_OF_FILES] = {};

    open_all_files(files);

    // TODO: magic numbers
    // TODO: initialization using NAN
    Test all_tests[5][4] = {{{"", 0}, {"", 0}, {"", 0}, {"", 0}},
                            {{"", 0}, {"", 0}, {"", 0}, {"", 0}},
                            {{"", 0}, {"", 0}, {"", 0}, {"", 0}},
                            {{"", 0}, {"", 0}, {"", 0}, {"", 0}},
                            {{"", 0}, {"", 0}, {"", 0}, {"", 0}}};

    for (int j = 0; j < 4; j++) {        //для первых четырёх вопросов(собираем пароль)
        get_file(all_tests[j], files[j]);
    }

    Test boss = {"", 0};                //а вот это отдельный блок для финального босса
    get_question(&boss, files[4]);
    fscanf(files[4], "%lg", &boss.answer);
    fgetc(files[4]);

    begin_game();

    char* user_name[MAX_LEN_NAME] = "";

    getline(user_name, );

    introducing_of_user(&user_name);

    for (int k = 0; k < 4; k++) {
        trainer_asks(rand() % AMT_TESTS, all_tests[k], &num_of_correct_answers);
    }
    trainer_asks(0, &boss, &num_of_correct_answers);

    end_game(num_of_correct_answers);
}

void trainer_asks(int question_number, Test tests[], int* num_of_correct_answers)
{
    double user_answer = 0;
    printf("%s\n%s", tests[question_number].question, "Введите правильный ответ, если вы получили два значения, выведите наибольшее\n");
    scanf("%lf", &user_answer);
    if (is_equal(user_answer, tests[question_number].answer)) {
        (*num_of_correct_answers)++;
    }
}

void end_game(int num_of_correct_answers)
{
    if (num_of_correct_answers == 5) {
        printf("Вы ограбили банк, сегодня в тюрьму вас не посадят, но лучше завязывать\n");
    }
    else {
        printf("Вы ошиблись и Костю с Иваном засекла система безопасности, *звуки мигалки*\n");
    }
}

// TODO maybe unify reading
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
    // TODO: read about errno
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

void begin_game()
{
    slow_print("Вы входите в квартиру, адрес которой указан в помятой записке и слышите чьи-то голоса\n");
    putchar('\n');
    txSleep(300);
    slow_print("-Иван, это безумие, нельзя грабануть банк в центре Москвы и не попасться полиции\n");
    txSleep(300);
    slow_print("-Кость, нас ловили хоть раз?\n");
    txSleep(300);
    slow_print("-Нет, но...\n");
    txSleep(300);
    slow_print("-Тем более мы наняли этого, как его..\n");
}

void introducing_of_user(const char** user_name)
{
    printf("-Вот, user_name расшифрует нам пароль от сейфа с бабкамии и, если что, сможет взломать систему безопасности.\n");
    txSleep(600);
    printf("Введите своё имя: ");
    //scanf("%s", *user_name);
    putchar('\n');
    // TODO snprintf
    slow_print("-%s, мы с Костей устроились пару месяцев назад в банк и сегодня проникнем в хранилище, а твоя задача расшифровать элементы пароля\n");
    txSleep(300);
    slow_print("и отправить нам. Также от тебя требуется всё время оставаться на связи, и, если потребуется  взломать систему безопасности и отключить его\n");
    txSleep(600);
    slow_print("Вы получили зашифрованные элементы пароля и компьютер от Ивана и Кости, вы должны отправлять расшифрованные элементы сразу после расшифровки\n");
    txSleep(600);
    slow_print("-А, и кстати, если ты ошибёшься хоть раз, в хранилище сработает сигнализация и за нами приедет полиция, и будь уверен, %s, мы обязательно тебя сдадим\n");
    txSleep(300);
    slow_print("Всё, на компе все файлы которые нам удалось достать, удачи\n");
}





