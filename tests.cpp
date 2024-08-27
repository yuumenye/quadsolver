#include <stdio.h>
#include <string.h>
#include "main.h"
#include "solver.h"
#include "colors.h"
#include "tests.h"
#include "io.h"
#include "compare.h"

int RunTest(const struct TestData *data)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(data->a, data->b, data->c, &x1, &x2);
    if (CompareFloat(nRoots, data->nRootsExpected) != 0 || CompareFloat(x1, data->x1Expected) != 0 || CompareFloat(x2, data->x2Expected))
    {
        caprint(RED, "Error: Test %d: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nRoots = %d\n"
                "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n",
                data->nTest, data->a, data->b, data->c, x1, x2, nRoots, data->x1Expected, data->x2Expected, data->nRootsExpected);
        return FAIL;
    }
    caprint(GREEN, "Test %d: Successful.\n", data->nTest);
    return SUCCESS;
}

void RunAllTests(void)
{
    const int maxLenght = 5;
    char nRootsStr[maxLenght] = ""; 
    struct TestData set = {};
    FILE *dataFile = fopen("tests.txt","r");
    for (int line;;line++)
    {
        int status = fscanf(dataFile, "nt:%d a:%lg b:%lg c:%lg x1e:%lg x2e:%lg nre:%s ", &set.nTest, &set.a, &set.b, &set.c, &set.x1Expected, &set.x2Expected, nRootsStr);
        if (status != 7)
        {
            if (status == EOF)
                break;
            caprint(RED,"Line %d: Invalid input", line);
            break;
        }
        else if (strcmp(nRootsStr, "INF") == 0)
        {
            set.nRootsExpected = INF;
            RunTest(&set);
        }
        else if (strcmp(nRootsStr, "NONE") == 0)
        {
            set.nRootsExpected = NONE;
            RunTest(&set);
        }
        else if (strcmp(nRootsStr, "ONE") == 0)
        {
            set.nRootsExpected = ONE;
            RunTest(&set);
        }
        else if (strcmp(nRootsStr, "TWO") == 0)
        {
            set.nRootsExpected = TWO;
            RunTest(&set);
        }
        else
        {
            caprint(RED, "Line %d: Invalid test.", line);
            break;
        }
    } 
    fclose(dataFile);
}
