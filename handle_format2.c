#include "main.h"
/**
 * handle_format2 - a helper function that handles the d, i specifiers
 * @c: the format character
 * @args: the argument list
 * Return: the number of characters printed
 */

int handle_format2(char c, va_list args)
{
	unsigned int len;

	switch (c)
	{
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
