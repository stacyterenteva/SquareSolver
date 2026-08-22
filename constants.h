#ifndef CONSTANTS_H
#define CONSTANTS_H

enum states {
    NO_ROOTS,
    ANY_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

enum modes {
    SCIENCE,
    HELPER
};

struct parameters {
    double a; double b; double c;
    double d;
    double roots[2];
};


 #endif /* CONSTANTS_H */


