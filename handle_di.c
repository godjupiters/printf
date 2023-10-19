#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * handle_d - a function that outputs any input
 * @format: a variable holding the specifier
 * @args: allowance for called value
 * Return: count
 */

int handle_d(char format, va_list args)
{
	int len = 0;

	switch (format)
	{
		case 'd':
			len = outint(va_arg(args, int));
			break;
		case 'i':
			len = outint(va_arg(args, int));
			break;
		default:
			_putcharP('%');
			_putcharP(format);
			break;
	}
	return (len);
}
