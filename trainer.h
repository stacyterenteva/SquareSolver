#ifndef TRAINER_H
#define TRAINER_H

const int AMT_QUESTIONS = 5;

struct Test {const char* question; double answer;};

void trainer_work();
void trainer_asks(int question_number, int training_report[], Test* tests);
void print_level(int amt_correct_answers);
int count_correct_answers(int* training_report);

#endif /* TRAINER_H */
