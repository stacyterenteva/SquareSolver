#ifndef CONSTANTS_H
#define CONSTANTS_H

// максимальное число корней
const int AMT_ROOTS = 2;

// TODO: rename ENUM_NAME_ENUM_MEMBER
enum States {
    NO_ROOTS,
    ANY_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

enum Modes {
    SCIENCE = 1,
    HELPER,
    TRAINER
};

enum Exactness {
    NOT_EXACT,
    EXACT
};

struct Parameters {
    double a; double b; double c;
    double d;
    double roots[AMT_ROOTS];
};

 #endif /* CONSTANTS_H */


