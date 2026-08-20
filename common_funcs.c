#include "common_funcs.h"
#include <math.h>
const double eps = 1e-9;

bool is_zero(double n)
{
    return (fabs(n) < eps);
}

