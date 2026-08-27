#ifndef CONSTANTS_H
#define CONSTANTS_H

// максимальное число корней
const int AMT_ROOTS = 2;

enum States {
    STATES_NO_ROOTS,
    STATES_ANY_ROOTS,
    STATES_ONE_ROOT,
    STATES_TWO_ROOTS
};

enum Modes {
    MODES_SCIENCE = 1,
    MODES_HELPER,
    MODES_TRAINER
};

struct Parameters {
    double a; double b; double c;
    double d;
    double roots[AMT_ROOTS];
};

 #endif /* CONSTANTS_H */


