#define TX_COMPILED
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

    Test all_tests[NUM_OF_TESTS][NUM_OF_QUESTIONS] = {{{"",  NAN}, {"", NAN}, {"", NAN}, {"", NAN}},
                            {{"", NAN}, {"", NAN}, {"", NAN}, {"", NAN}},
                            {{"", NAN}, {"", NAN}, {"", NAN}, {"", NAN}},
                            {{"", NAN}, {"", NAN}, {"", NAN}, {"", NAN}},
                            {{"", NAN}, {"", NAN}, {"", NAN}, {"", NAN}}};

    for (int j = 0; j < NUM_OF_QUESTIONS; j++) {        //для первых четырёх вопросов(собираем пароль)
        get_file(all_tests[j], files[j]);
    }

    Test boss = {"", 0};                //а вот это отдельный блок для финального босса
    get_question(&boss, files[LAST_QUESTION]);
    fscanf(files[LAST_QUESTION], "%lg", &boss.answer);
    fgetc(files[LAST_QUESTION]);

    begin_game();

    char user_name[MAX_NAME_LEN] = {0}; //NOTE Что происходит при такой инициализации

    introducing_of_user(user_name);

    for (int k = 0; k < NUM_OF_QUESTIONS; k++) {
        trainer_asks(rand() % NUM_OF_TESTS, all_tests[k], &num_of_correct_answers);
    }
    trainer_asks(0, &boss, &num_of_correct_answers);

    end_game(num_of_correct_answers);
}

// TODO: asserts
void trainer_asks(int question_number, Test tests[], int* num_of_correct_answers)
{
    assert(num_of_correct_answers);
    double user_answer = 0;
    printf("%s\n%s", tests[question_number].question, "Введите правильный ответ, если вы получили два значения, выведите наибольшее\n");
    scanf("%lf", &user_answer);
    if (is_equal(user_answer, tests[question_number].answer)) {
        (*num_of_correct_answers)++;
    }
}

void end_game(int num_of_correct_answers)
{
    if (num_of_correct_answers == NUM_OF_QUESTIONS) {
        printf("Вы ограбили банк, сегодня в тюрьму вас не посадят, но лучше завязывать\n");
    }
    else {
        printf("Вы ошиблись и Костю с Иваном засекла система безопасности, *звуки мигалки*\n");
    }
}

// TODO maybe unify reading
void get_file(Test first_tests[], FILE *first_test)
{
    for (int i = 0; i < NUM_OF_TESTS; i++) {
        get_question(&first_tests[i], first_test);
        fscanf(first_test, "%lg", &first_tests[i].answer);
        fgetc(first_test);
    }
}


void get_question(Test* tests, FILE *test)
{
    int ch = 0;
    int i = 0;
    while (i < MAX_NUM_OF_CHARS && (ch = fgetc(test)) != EOF && ch != ';') {
        (tests->question)[i] = (char) ch;
        i++;
    }
}

void open_all_files(FILE *files[]) //TODO return ERROR и потом обработать
{
    FILE *first_test = fopen("trainer_fail_base/first_test.csv", "r");
    if (first_test == NULL) {
        perror("ERROR"); //NOTE Как потом выйти из программы ли так выходить из программы
                                         //exit() вызывает warning
    }
    files[0] = first_test;

    FILE *second_test = fopen("trainer_fail_base/second_test.csv", "r");
    if (second_test == NULL) {
        perror("ERROR");
    }
    files[1] = second_test;

    FILE *third_test = fopen("trainer_fail_base/third_test.csv", "r");
    if (third_test == NULL) {
        perror("ERROR");
    }
    files[2] = third_test;

    FILE *fourth_test = fopen("trainer_fail_base/fourth_test.csv", "r");
    if (fourth_test == NULL) {
        perror("ERROR");
    }
    files[3] = fourth_test;

    FILE *fifth_test = fopen("trainer_fail_base/fifth_test.csv", "r");
    if (fifth_test == NULL) {
        perror("ERROR");
    }
    files[4] = fifth_test;
}

void begin_game()
{
    // TODO: magic numbers
    slow_print("Вы входите в квартиру, адрес которой указан в помятой записке и слышите чьи-то голоса\n\n");
    txSleep(SHORT_SLEEP);

    slow_print("-Иван, это безумие, нельзя грабануть банк в центре Москвы и не попасться полиции\n");
    txSleep(SHORT_SLEEP);
    slow_print("-Кость, нас ловили хоть раз?\n");
    txSleep(SHORT_SLEEP);
    slow_print("-Нет, но...\n");
    txSleep(SHORT_SLEEP);
    slow_print("-Тем более мы наняли этого, как его..\n\n");
    slow_print("Вы входите в комнату откуда были слышны голоса\n\n");
}

//work in progress
void introducing_of_user(char* user_name)
{
    assert(user_name);

    slow_print("-Вот, его мы наняли, напомни, как тебя зовут?\n");
    txSleep(SHORT_SLEEP);

    printf("Введите своё имя: ");
    txSleep(SHORT_SLEEP);

    getline(user_name, MAX_NAME_LEN);
    char temp1[MAX_NUM_OF_CHARS] = {};
    snprintf(temp1, sizeof(temp1), "-Да, %s расшифрует нам пароль от сейфа с бабкамии и если что сможет взломать систему безопасности.\n", user_name);
    slow_print(temp1);
    txSleep(SHORT_SLEEP);

    char temp2[MAX_NUM_OF_CHARS] = {};
    snprintf(temp2, sizeof(temp2), "-%s, мы с Костей устроились пару месяцев назад в банк и сегодня проникнем в хранилище, а твоя задача расшифровать элементы пароля\n", user_name);
    slow_print(temp2);
    txSleep(SHORT_SLEEP);

    slow_print("и отправить нам. Также от тебя требуется всё время оставаться на связи, и, если потребуется  взломать систему безопасности и отключить его\n");
    txSleep(LONG_SLEEP);

    slow_print("Вы получили зашифрованные элементы пароля и компьютер от Ивана и Кости, вы должны отправлять расшифрованные элементы сразу после расшифровки\n");
    txSleep(LONG_SLEEP);

    char temp3[MAX_NUM_OF_CHARS] = {};
    snprintf(temp3, sizeof(temp3), "-А, и кстати, если ты ошибёшься хоть раз, в хранилище сработает сигнализация и за нами приедет полиция, это я тебе гарантирую, %s, мы обязательно тебя сдадим\n", user_name);

    slow_print(temp3);
    txSleep(SHORT_SLEEP);

    slow_print("Всё, на компе все файлы которые нам удалось достать, удачи\n");
}





