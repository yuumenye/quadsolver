/** \file solver.h
 *  \brief Solve quadratic equation.
 */
#ifndef SOLVER_H
#define SOLVER_H
typedef enum NumberOfRoots 
{ 
    INF  = -1, /**< Infinite number of solutions */
    NONE = 0,  /**< No solutions */
    ONE  = 1,  /**< One solution */
    TWO  = 2,  /**< Two solutions */
} NumberOfRoots;

/** \brief Solve quadratic equation.
 *
 *  Solve quadratic equation in form ax^2 + bx + c = 0.
 *  If a = 0, fallback to SolveLinear().
 *  \param[in] a Quadratic coefficient.
 *  \param[in] b Linear coefficient.
 *  \param[in] c Free term.
 *  \param[in] *x1 Pointer to the first solution.
 *  \param[in] *x2 Pointer to the second solution.
 *  \return Number of roots.
 */
NumberOfRoots SolveSquare(double a, double b, double c, double *x1, double *x2);
 
/** \brief Solve linear equation.
 *
 *  Solve linear equation in form hx + k = 0;
 *  \param[in] h Linear coefficient.
 *  \param[in] k Free term.
 *  \param[in] *x Pointer to the solution.
 *  \return Number of roots.
 */
NumberOfRoots SolveLinear(double h, double k, double *x);

int SolveFromLine(const char **argv, struct Options *userOptions);
#endif
