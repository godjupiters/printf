#include "main.h"

/**
 * print_c - a function that prints a char
 * @typfier: a variable holding arg list
 * @bffr: a variable holding
 * @flagger:  a variable holding active flagger
 * @wdth: a variable holding width
 * @prec: a variable holding precision spec
 * @size: a variable holding size specifier
 * Return: int
 */
int print_c(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size)
{
	char c = va_arg(typfier, int);

	return (handle_w_c_func(c, bffr, flagger, wdth, prec, size));
}

/**
 * print_s - a function that prints a string
 * @typfier: a variable holding arguments
 * @bffr: a variable holding buffer
 * @flagger:  a variable holding flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding prec spec
 * @size: a variable holding size spec
 * Return: char number
 */
int print_s(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size)
{
	int length_ = 0, i;
	char *str = va_arg(typfier, char *);

	UNUSED(bffr);
	UNUSED(flagger);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[length_] != '\0')
		length_++;

	if (prec >= 0 && prec < length_)
		length_ = prec;

	if (wdth > length_)
	{
		if (flagger & F_MINUS)
		{
			write(1, &str[0], length_);
			for (i = wdth - length_; i > 0; i--)
				write(1, " ", 1);
			return (wdth);
		}
		else
		{
			for (i = wdth - length_; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length_);
			return (wdth);
		}
	}

	return (write(1, str, length_));
}

/**
 * print_per - a function that prints Percen sign
 * @typfier: a variable holding arguments
 * @bffr: a variable holding array to handle print
 * @flagger:  a variable holding flagger
 * @wdth: a variable holding wdth.
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: no of char
 */

int print_per(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size)
{
	UNUSED(typfier);
	UNUSED(bffr);
	UNUSED(flagger);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * print_i - a function that print int
 * @typfier: a variable holding arguments
 * @bffr: a variable holding array to handle print
 * @flagger:  a variable holding active flagger
 * @wdth: a variable holding wdth.
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: no of char
 */
int print_i(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	int _is_negat = 0;
	long int n = va_arg(typfier, long int);
	unsigned long int numb;

	n = conv_size_num_func(n, size);

	if (n == 0)
		bffr[i--] = '0';

	bffr[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)n;

	if (n < 0)
	{
		numb = (unsigned long int)((-1) * n);
		_is_negat = 1;
	}

	while (numb > 0)
	{
		bffr[i--] = (numb % 10) + '0';
		numb /= 10;
	}

	i++;

	return (write_num_func(_is_negat, i, bffr, flagger, wdth, prec, size));
}

/**
 * print_b - a function that prints unsigned number
 * @typfier: a variable holding arguments
 * @bffr: a variable holding array to handle print
 * @flagger:  a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: no of char
 */

int print_b(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(bffr);
	UNUSED(flagger);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(size);

	n = va_arg(typfier, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

