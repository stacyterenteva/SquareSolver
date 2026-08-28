//#define TX_COMPILED
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#include <C:\TX\Examples\txWave\TXWave.h>
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
    int num_of_correct_answers = 0;

    FILE *files[NUM_OF_FILES] = {};

    open_all_files(files);

    Test all_tests[NUM_OF_TESTS][NUM_OF_QUESTIONS] = {{{"",  NAN}, {"", NAN}, {"", NAN}, {"", NAN}},
                            {{"", NAN}, {"", NAN}, {"", NAN}, {"", NAN}},
                            {{"", NAN}, {"", NAN}, {"", NAN}, {"", NAN}},
                            {{"", NAN}, {"", NAN}, {"", NAN}, {"", NAN}},
                            {{"", NAN}}};

    for (int j = 0; j < NUM_OF_QUESTIONS; j++) {        //для первых четырёх вопросов(собираем пароль)
        get_file(all_tests[j], files[j]);
    }

    Test boss = {"", 0};                //а вот это отдельный блок для финального босса
    get_question(&boss, files[LAST_QUESTION]);
    fscanf(files[LAST_QUESTION], "%lg", &boss.answer);
    fgetc(files[LAST_QUESTION]);

    //txWaveData_t kvadratka_music = txWaveLoadWav("trainer_fail_base/kvadratka_music.wav");

    //txWaveData_t migalka = txWaveLoadWav("trainer_fail_base/kvadratka_music.wav");

    //txWaveOut(txWaveLoadWav("trainer_fail_base/kvadratka_music.wav"), 1);

    begin_game();

    char user_name[MAX_NAME_LEN] = {0}; //NOTE Что происходит при такой инициализации

    introducing_of_user(user_name);
    /*
    txWaveData_t kvadratka_music = txWaveLoadWav("trainer_fail_base/kvadratka_music.wav");

    txWaveData_t migalka = txWaveLoadWav("trainer_fail_base/kvadratka_music.wav");

    txWaveOut(1000, kvadratka_music);
    */

    for (int k = 0; k < NUM_OF_QUESTIONS; k++) {
        trainer_asks(rand() % NUM_OF_TESTS, all_tests[k], &num_of_correct_answers);
    }

    preboss_tekst(user_name);
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
        printf("Вы ошиблись и Костю с Иваном засекла система безопасности\n");
        //txWaveOut(txWaveLoadWav("trainer_fail_base/mialka.wav"), 1);
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
    goto_next_phrase();

    slow_print(YELLOW "-Иван, это безумие, нельзя грабануть банк в центре Москвы и не попасться полиции\n");
    txSleep(SHORT_SLEEP);

    slow_print("-Кость, нас ловили хоть раз?\n");
    txSleep(SHORT_SLEEP);
    goto_next_phrase();

    slow_print("-Нет, но...\n");
    txSleep(SHORT_SLEEP);

    slow_print("-Тем более мы наняли этого, как его..\n\n");
    slow_print(RESET "Вы входите в комнату откуда были слышны голоса\n\n");
    goto_next_phrase();
}

//work in progress
void introducing_of_user(char* user_name)
{
    assert(user_name);

    slow_print(YELLOW "-Вот, его мы наняли, напомни, как тебя зовут?\n\n");
    txSleep(SHORT_SLEEP);

    printf(RESET "Введите своё имя: ");
    txSleep(SHORT_SLEEP);

    getline(user_name, MAX_NAME_LEN);

    putchar('\n');

    char temp[MAX_NUM_OF_CHARS] = {};
    snprintf(temp, sizeof(temp), YELLOW "-Да, %s расшифрует нам пароль от сейфа с бабкамии и если что сможет взломать систему безопасности.\n", user_name);
    slow_print(temp);
    txSleep(SHORT_SLEEP);
    goto_next_phrase();

    temp[MAX_NUM_OF_CHARS] = {};
    snprintf(temp, sizeof(temp), "-%s, мы с Костей устроились пару месяцев назад в банк и сегодня проникнем в хранилище, а твоя задача расшифровать элементы пароля\n", user_name);
    slow_print(temp);
    txSleep(SHORT_SLEEP);

    slow_print(YELLOW "и отправить нам. Также от тебя требуется всё время оставаться на связи, и, если потребуется, взломать систему безопасности и отключить её\n\n");
    txSleep(LONG_SLEEP);
    goto_next_phrase();

    slow_print(RESET "Вы получили зашифрованные элементы пароля и компьютер от Ивана и Кости, вы должны отправлять расшифрованные элементы сразу после расшифровки\n\n");
    txSleep(LONG_SLEEP);

    temp[MAX_NUM_OF_CHARS] = {};
    snprintf(temp, sizeof(temp), YELLOW "-А, и кстати, если ты ошибёшься хоть раз, в хранилище сработает сигнализация и за нами приедет полиция, это я тебе гарантирую, %s, мы обязательно тебя сдадим\n", user_name);

    slow_print(temp);
    txSleep(SHORT_SLEEP);
    goto_next_phrase();

    slow_print(YELLOW "Всё, на компе все файлы которые нам удалось достать, удачи\n\n");
    printf(RESET);
    goto_next_phrase();
}

void preboss_tekst(char* user_name)
{
    slow_print(RESET "Вы обработали все файлы\n");
    txSleep(LONG_SLEEP);

    slow_print("...\n");
    slow_print("Телефон оставленный Иваном начинал еле слышно вибрировать\n");
    txSleep(SHORT_SLEEP);
    goto_next_phrase();

    slow_print("Вы берёте трубку и слышите приглушённые голоса\n\n");
    txSleep(SHORT_SLEEP);
    // getchar();

    slow_print(YELLOW "-Чертовы лазеры, почему их не было в плане здания?!");
    txSleep(SHORT_SLEEP);
    goto_next_phrase();

    char temp[MAX_NUM_OF_CHARS] = {};
    snprintf(temp, sizeof(temp), "%s нам нужно быстро вырубить систему безопасности, я скину все вводные\n", user_name);
    slow_print(temp);

    slow_print(YELLOW "А твоя задача, сделать все необходимые рассчеты, быстрее прошу тебя\n\n" RESET);
    txSleep(LONG_SLEEP);
}

void goto_next_phrase() {
    getchar();
    printf("\x1b[A");
}





