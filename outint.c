#include "main.h"

/**
 * print_digits - a function that counts string
 * @n: a variable holding the count
 * @count: a variable holding the value
 * Return: void
 */

void print_digits(int n, int *count)
{
	if (n < 10)
	{
		_putcharP(n + '0');
		(*count)++;
		return;
	}

	print_digits(n / 10, count);
	_putcharP(n % 10 + '0');
	(*count)++;
}

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
