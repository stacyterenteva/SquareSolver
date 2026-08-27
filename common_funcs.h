#ifndef COMMON_FUNCS_H
#define COMMON_FUNCS_H

const int SLEEP_TIME_FOR_SLOW_PRINT = 40;

bool is_equal(double a, double b);

void clean_buf();
void slow_print(const char string[]);
void getline(char* string, unsigned int max_len);

#endif /* COMMON_FUNCS_H */
