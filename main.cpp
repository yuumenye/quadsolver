#include "main.h"
#include "solver.h"
#include "io.h"
#include "tests.h"

int main()
{
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    if (GetInput(&a, &b, &c) == FAIL)
        return FAIL;
    RunAllTests();
    NumberOfRoots nRoots = SolveSquare(a, b, c, &x1, &x2);

    if (PrintSolutions(nRoots, x1, x2) == FAIL)
        return FAIL;
    return SUCCESS;
}
