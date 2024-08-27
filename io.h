/** \file io.h
 *  \brief Get input, print solutions.
 */
#ifndef IO_H
#define IO_H
#include <stdio.h>
#include "solver.h"
/** \brief Print solutions.
 *  \param[in] nRoots Number of roots.
 *  \param[in] x1 First solution.
 *  \param[in] x2 Second solution.
 */
int PrintSolutions(NumberOfRoots nRoots, double x1, double x2);
/** \brief Get input.
 *
 *  Get input values in a, b, c.
 *  \param[in] *a Pointer to the quadratic coefficent.
 *  \param[in] *b Pointer to the linear coefficient.
 *  \param[in] *c Pointer to the free term.
 */

int GetInput(double *a, double *b, double *c);

/** \brief Clear input.
 *
 *  Clear input. Abort the program if EOF is encountered.
 */
int ClearInput(FILE *inStream = stdin);

int GetOptions(const int argc, const char **argv, struct Options *userOptions);
int GetShortOptions(const char **argv, int *nArg, struct Options *userOptions);
void PrintHelp(void);

#endif
