#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int _printf(const char *format, ...);
int print_arg(char format, va_list args);
int _putcharP(char c);
int outstr(char *c);
int outint(int n);

#endif
