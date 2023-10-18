#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - a function that outputs any input
 * @format: a variable holding the specifier
 * @...: allowance for called value
 * Return: count
 */

int _printf(const char *format, ...)
{
	unsigned int i, len, total = 0;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putcharP(format[i]);
		}
		else
		{
			i++;
			len = print_arg(format[i], args);
			total += (len - 1);
		}
		total++;
	}
	va_end(args);
	return (total);
}
