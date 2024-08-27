/** \file main.h
 *
 */
#ifndef MAIN_H
#define MAIN_H
enum Status
{
    SUCCESS = 0,
    FAIL = 1,
};
struct Options
{
    int help;
    int test;

    int line;
    int linePos;

    int file;
};
#endif
