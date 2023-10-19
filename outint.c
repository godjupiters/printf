#include "main.h"

/**
 * outint - a function that outputs integers
 * @n: a variable holding the value
 * Return: count
 */

int outint(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putcharP('-');
		n = -n;
	}

	if (n == 0)
	{
		_putcharP('0');
		return (1);
	}

	print_digits(n, &count);

	return (count);
}
