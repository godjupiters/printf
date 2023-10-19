#include "main.h"


/**
 * handle_format - a helper function that handles the format specifier
 * @c: the format character
 * @args: the argument list
 * Return: the number of characters printed
 */

int handle_format(char c, va_list args)
{
	unsigned int len;

	switch (c)
	{
		case 'c':
			_putcharP(va_arg(args, int));
			return (1);
		case 's':
			len = outstr(va_arg(args, char *));
			return (len);
		case '%':
			_putcharP('%');
			return (1);
		case 'd':
			len = outint(va_arg(args, int));
			return (len);
		case 'i':
			len = outint(va_arg(args, int));
			return (len);
		default:
			_putcharP('%');
			_putcharP(c);
			return (2);
	}
}
