#include <math.h>
#include "compare.h"

double CompareFloat(double x, double y)
{
    double e = 10e-6;
    double diff = x - y;
    if (fabs(diff) < e)
        return 0;
    return diff;
}

