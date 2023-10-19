#include "main.h"

/**
 * get_prec_func - a function that cal the prec to print
 * @format: a variable holding formated string
 * @i: a variable holding args to be print
 * @lst: a variable holding lst of arguments.
 * Return: Preci
 */

int get_prec_func(const char *format, int *i, va_list lst)
{
	int cur_cnt = *i + 1;
	int prec = -1;

	if (format[cur_cnt] != '.')
		return (prec);

	prec = 0;

	for (cur_cnt += 1; format[cur_cnt] != '\0'; cur_cnt++)
	{
		if (is_d_func(format[cur_cnt]))
		{
			prec *= 10;
			prec += format[cur_cnt] - '0';
		}
		else if (format[cur_cnt] == '*')
		{
			cur_cnt++;
			prec = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*i = cur_cnt - 1;

	return (prec);
}
