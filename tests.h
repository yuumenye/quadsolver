/** \file tests.h
 *  \brief Run predefined tests.
 */
#ifndef TESTS_H
#define TESTS
struct TestData
{
    int nTest; /**< Number of test */
    double a, b, c; /**< Coefficients */
    double x1Expected, x2Expected; /**< Predefined solutions */
    int nRootsExpected; /**< Predefined number of solutions */
};

/** \brief Run test.
 *  \param[in] *data Pointer to test data.
 */
int RunTest(const struct TestData *data);
/** \brief Run all tests.
 */
void RunAllTests(void);
#endif
