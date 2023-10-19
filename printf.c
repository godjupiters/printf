#include "main.h"

/**
 * _printf - a function that outputs any input
 * @format: a variable holding the specifier
 * @...: allowance for called value
 * Return: count
 */

int _printf(const char *format, ...)
{
	unsigned int i, total = 0;
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
			if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
				total += handle_format1(format[i], args) - 1;
			else if (format[i] == 'd' || format[i] == 'i')
				total += handle_format2(format[i], args) - 1;
			else
			{
				_putcharP('%');
				_putcharP(format[i]);
			}
		}
		total++;
	}
	va_end(args);
	return (total);
}
