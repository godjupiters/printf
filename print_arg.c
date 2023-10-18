#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_arg - a function that outputs any input
 * @format: a variable holding the specifier
 * @args: variable holding the argument
 * Return: count
 */

int print_arg(char format, va_list args)
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
		case 'd':
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
