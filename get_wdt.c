#include "main.h"

/**
 * get_width_func - a function that cal wdth to print
 * @format: a variable holding formated string
 * @i: a variable holding arguments to be print
 * @lst: a variable holding lst of args
 * Return: int of width
 */

int get_width_func(const char *format, int *i, va_list lst)
{
	int cur_cnt;
	int wdth = 0;

	for (cur_cnt = *i + 1; format[cur_cnt] != '\0'; cur_cnt++)
	{
		if (is_d_func(format[cur_cnt]))
		{
			wdth *= 10;
			wdth += format[cur_cnt] - '0';
		}
		else if (format[cur_cnt] == '*')
		{
			cur_cnt++;
			wdth = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*i = cur_cnt - 1;

	return (wdth);
}
