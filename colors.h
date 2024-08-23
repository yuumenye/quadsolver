/** \file colors.h
 *  \brief Make our program colorful.
 */
#ifndef COLORS_H
#define COLORS_H
#define BLACK       "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define BROWN       "\033[0;33m"
#define BLUE        "\033[0;34m"
#define PURPLE      "\033[0;35m"
#define CYAN        "\033[0;36m"
#define LIGHTGRAY   "\033[0;37m"
#define DARKGRAY    "\033[1;30m"
#define LIGHTRED    "\033[1;31m"
#define LIGHTGREEN  "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define LIGHTBLUE   "\033[1;34m"
#define LIGHTPURPLE "\033[1;35m"
#define LIGHTCYAN   "\033[1;36m"
#define WHITE       "\033[1;37m"
#define OFFCOLOR    "\033[0m"

#define cprint(color, text) printf(color text OFFCOLOR)
#define caprint(color, text, ...) printf(color text OFFCOLOR, __VA_ARGS__)
#endif
