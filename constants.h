#ifndef CONSTANTS_H
#define CONSTANTS_H

const int AMT_ROOTS = 2;

enum States {
    NO_ROOTS,
    ANY_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
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


