#include "main.h"

/**
 * get_size_func - a function to cal the size argument
 * @format: a variable holding fomated string
 * @i: a variable holding list of args to print
 * Return: Prec
 */

int get_size_func(const char *format, int *i)
{
	int cur_cnt = *i + 1;
	int size = 0;

	if (format[cur_cnt] == 'l')
		size = S_LONG;
	else if (format[cur_cnt] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cur_cnt - 1;
	else
		*i = cur_cnt;

	return (size);
}
