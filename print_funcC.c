#include "main.h"

/**
 * print_pointr - a functions thar prints value of pointer
 * @typfier: a variable holding of arguments
 * @bffr: a variable holding array to handle print
 * @flagger: a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: int
 */

int print_pointr(va_list typfier, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	char extra_charr = 0, pdd = ' ';
	int seprt = BUFF_SIZE - 2, length_ = 2, padd_start = 1;
	unsigned long num_addrs;
	char syn_to[] = "0123456789abcdef";
	void *addrs = va_arg(typfier, void *);

	UNUSED(wdth);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	bffr[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		bffr[seprt--] = syn_to[num_addrs % 16];
		num_addrs /= 16;
		length_++;
	}
	if ((flagger & F_ZERO) && !(flagger & F_MINUS))
		pdd = '0';
	if (flagger & F_PLUS)
		extra_charr = '+', length_++;
	else if (flagger & F_SPACE)
		extra_charr = ' ', length_++;

	seprt++;

	return (write_ptr_func(bffr, seprt, length_,
				wdth, flagger, pdd, extra_charr, padd_start));
}

/**
 * print_nonprint - a function that prints ascii codes in
 * hexa for non print chars
 * @typfier: a variable holding of arguments
 * @bffr: a variable holding array to handle print
 * @flagger:  a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: int
 */

int print_nonprint(va_list typfier, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(typfier, char *);

	UNUSED(flagger);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_prt_func(str[i]))
			bffr[i + offset] = str[i];
		else
			offset += app_h_cod_func(str[i], bffr, i + offset);

		i++;
	}

	bffr[i + offset] = '\0';

	return (write(1, bffr, i + offset));
}

/**
 * print_rev_func - a function that prints reverse string
 * @typfier: a variable holding of arguments
 * @bffr: a variable holding array to handle print
 * @flagger:  a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: int
 */

int print_rev_func(va_list typfier, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(bffr);
	UNUSED(flagger);
	UNUSED(wdth);
	UNUSED(size);

	str = va_arg(typfier, char *);

	if (str == NULL)
	{
		UNUSED(prec);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}

	return (count);
}

/**
 * print_r13s - a function that prints a string in rot13.
 * @typfier: a variable holding of arguments
 * @bffr: a variable holding array to handle print
 * @flagger: a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: int
 */

int print_r13s(va_list typfier, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	char x;
	char *str;
	unsigned int i, bn;
	int count = 0;
	char feed[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char fdout[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typfier, char *);
	UNUSED(bffr);
	UNUSED(flagger);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (bn = 0; feed[bn]; bn++)
		{
			if (feed[bn] == str[i])
			{
				x = fdout[bn];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!feed[bn])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}

	return (count);
}
