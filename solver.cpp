#include <string.h>
#include <math.h>
#include <assert.h>
#include "solver.h"
#include "io.h"
#include "main.h"
#include "compare.h"

NumberOfRoots SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    if (CompareFloat(a, 0) == 0)
        return SolveLinear(b, c, x1);
    else
    {
        double d = b*b - 4*a*c;
        double sqrtd = sqrt(d);
        if (CompareFloat(d, 0) > 0) 
        {
            *x1 = (-b + sqrtd) / (2*a);
            *x2 = (-b - sqrtd) / (2*a);
            return TWO;
        }
        else if (CompareFloat(d, 0) == 0)
        {
            *x1 = -b / (2*a);
            return ONE;
        }
        else if (CompareFloat(d, 0) < 0)
            return NONE;
    }
    return NONE;
}


NumberOfRoots SolveLinear(double h, double k, double *x)
{
    assert(x != NULL);
    assert(std::isfinite(h));
    assert(std::isfinite(k));

    if (CompareFloat(h, 0) == 0)
    {
        if (CompareFloat(k, 0) == 0)
            return INF;
    }
    else
    {
        *x = -k / h;
        return ONE;
    }
    return NONE;
}

int SolveFromLine(const char **argv, struct Options *userOptions)
{
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    int lp = userOptions->linePos;

    if (sscanf(argv[++lp], "%lg", &a) != 1)
        return FAIL;
    if (sscanf(argv[++lp], "%lg", &b) != 1)
        return FAIL;
    if (sscanf(argv[++lp], "%lg", &c) != 1)
        return FAIL;
    NumberOfRoots nRoots = SolveSquare(a, b, c, &x1, &x2);

    if (PrintSolutions(nRoots, x1, x2) == FAIL)
        return FAIL;
    return SUCCESS;
}
