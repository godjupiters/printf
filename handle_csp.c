#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * handle_csp - a function that outputs any input
 * @format: a variable holding the specifier
 * @args: allowance for called value
 * Return: count
 */

int handle_csp(char format, va_list args)
{
	int len = 0;

	switch (format)
	{
		case 'c':
			_putcharP(va_arg(args, int));
			break;
		case 's':
			len = outstr(va_arg(args, char *));
			break;
		case '%':
			_putcharP('%');
			break;
		default:
			_putcharP('%');
			_putcharP(format);
			break;
	}
	return (len);
}
