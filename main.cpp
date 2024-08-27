#include <string.h>
#include "solver.h"
#include "main.h"
#include "io.h"
#include "tests.h"
#include "colors.h"

int main(const int argc, const char **argv)
{
    struct Options userOptions = {}; 
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    if (argc > 1 && GetOptions(argc, argv, &userOptions) == FAIL)
    {
        return FAIL;
    }
    else if (userOptions.help == 1)
    {
        PrintHelp();
        return SUCCESS;
    }
    else if (userOptions.test == 1)
    {
        RunAllTests();
        return SUCCESS;
    }
    else if (userOptions.line == 1)
    {
        SolveFromLine(argv, &userOptions);
        return SUCCESS;
    }
    /* if no options specified */
    else if (GetInput(&a, &b, &c) == FAIL)
        return FAIL;

    NumberOfRoots nRoots = SolveSquare(a, b, c, &x1, &x2);

    if (PrintSolutions(nRoots, x1, x2) == FAIL)
        return FAIL;
    return SUCCESS;

}
