#include "main.h"
/**
 * handle_format1 - a helper function that handles the c, s, % specifiers
 * @c: the format character
 * @args: the argument list
 * Return: the number of characters printed
 */

int handle_format1(char c, va_list args)
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
		default:
			_putcharP('%');
			_putcharP(c);
			return (2);
	}
}
