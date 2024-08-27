#include <stdio.h>
#include <string.h>
#include "main.h"
#include "io.h"
#include "colors.h"
#include "solver.h"

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
    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {
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

void PrintHelp(void)
{
    printf("\
Usage:\n\
 quadsolver [options]\n\n\
Solve qudratic equation.\n\n\
Options:\n\
 -l, --line <a> <b> <c> input numbers as arguments\n\
 -t, --test             run tests\n\
 -h, --help             print this message\n\
");

}

int GetOptions(const int argc, const char **argv, struct Options *userOptions)
{
    int nArg;
    for (nArg = 1; nArg < argc; nArg++)
    {
        if (strcmp(argv[nArg], "--help") == 0)
            userOptions->help = 1;
        else if (strcmp(argv[nArg], "--test") == 0)
            userOptions->test = 1;
        else if (strcmp(argv[nArg], "--line") == 0)
        {
            userOptions->linePos = nArg;
            userOptions->line = 1;
            nArg += 3;
        }
        else if (*argv[nArg] == '-')
        {
            if (GetShortOptions(argv, &nArg, userOptions) == FAIL)
                return FAIL;
        }
        else
            return FAIL;
    }
    return SUCCESS;
}

int GetShortOptions(const char **argv, int *nArg, struct Options *userOptions)
{
    int j;
    int ch = 0;
    int exitForLoop = 0;
    for (j = 1; (ch = argv[*nArg][j]) != '\0'; j++)
    {
        switch (ch)
        {
            case 'h':
                userOptions->help = 1;
                break;
            case 't':
                userOptions->test = 1;
                break;
            case 'l':
                userOptions->linePos = *nArg;
                userOptions->line = 1;
                *nArg += 3;
                exitForLoop = 1;
                break;
            default:
                return FAIL;
        }

        if (exitForLoop)
            break;
    }
    return SUCCESS;
}
