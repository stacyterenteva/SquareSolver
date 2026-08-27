#ifndef TRAINER_H
#define TRAINER_H

#include <stdio.h>

const int NUM_OF_QUESTIONS = 4;
const int NUM_OF_TESTS = 5;
const int MAX_NUM_OF_CHARS = 1000;
const int NUM_OF_FILES = 5;
const int MAX_NAME_LEN = 1000;
const int LAST_QUESTION = 4;
const int SHORT_SLEEP = 300;
const int LONG_SLEEP = 600;

struct Test {char question[MAX_NUM_OF_CHARS]; double answer;};

void trainer_work();
void trainer_asks(int question_number, Test tests[], int* num_of_correct_answers);

void end_game(int num_of_correct_answers);
void begin_game();
void introducing_of_user(char* user_name);
void preboss_tekst(char* user_name);

void get_file(Test first_tests[], FILE *first_test);
void get_question(Test* tests, FILE* test);
void open_all_files(FILE *files[]);

void goto_next_phrase();

#endif /* TRAINER_H */
