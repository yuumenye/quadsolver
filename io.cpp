#include <stdio.h>
#include "main.h"
#include "solver.h"
#include "io.h"
#include "colors.h"

int PrintSolutions(NumberOfRoots nRoots, double x1, double x2)
{
    switch (nRoots) 
    {
        case NONE:
            printf("No solutions.\n");
            return SUCCESS;
        case ONE:
            printf("%g\n", x1);
            return SUCCESS;
        case TWO:
            printf("%g %g\n", x1, x2);
            return SUCCESS;
        case INF:
            printf("Infinite number of solutions.\n");
            return SUCCESS;
        default:
            cprint(RED, "Error: Wrong number of solutions.\n");
            return FAIL;
    }
}

int GetInput(double *a, double *b, double *c)
{
    while (scanf("%lg %lg %lg", a, b, c) != 3) {
        if (ClearInput() == FAIL)
            return FAIL;
        cprint(RED, "Error: Wrong input.\n");
    }
    return SUCCESS;
}

int ClearInput(FILE *inStream)
{
    int ch = 0;
    while ((ch = getc(inStream)) != '\n')
        if (ch == EOF)
            return FAIL;
    return SUCCESS;
}
