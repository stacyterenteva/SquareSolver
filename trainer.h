#ifndef TRAINER_H
#define TRAINER_H

#include <stdio.h>

const int AMT_QUESTIONS = 5;
const int AMT_TESTS = 4;
const int MAX_AMT_CHARS = 2000;
const int NUM_OF_FILES = 5;

struct Test {char question[MAX_AMT_CHARS]; double answer;};

void trainer_work();
void trainer_asks(int question_number, int training_report[], Test tests[], int i);

int count_correct_answers(int* training_report);
void print_level(int amt_correct_answers);

void get_file(Test first_tests[], FILE *first_test);
void get_question(Test* tests, FILE* test);
void open_all_files(FILE *files[]);

#endif /* TRAINER_H */
