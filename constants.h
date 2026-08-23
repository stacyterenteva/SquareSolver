#ifndef CONSTANTS_H
#define CONSTANTS_H

enum States {
    NO_ROOTS,
    ANY_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

enum Modes {
    SCIENCE = 1,
    HELPER
};

enum Exactness {
    NOT_EXACT,
    EXACT
};

enum Greeting {
    BEGINING,
    IN_MODE
};
struct Parameters {
    double a; double b; double c;
    double d;
    double roots[2];
};


 #endif /* CONSTANTS_H */


