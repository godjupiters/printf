#include "main.h"

/**
 * handle_w_c_func - a function to print strings
 * @c: a variable holding char typfier.
 * @bffr: a variable holding array to handle print
 * @flagger: a variable holding active flagger.
 * @wdth: a variable holding wdth.
 * @prec: a variable holding prec specifier
 * @size: a variable holding specifier
 * Return: int
 */

int handle_w_c_func(char c, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	int i = 0;
	char pdd = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flagger & F_ZERO)
		pdd = '0';

	bffr[i++] = c;
	bffr[i] = '\0';

	if (wdth > 1)
	{
		bffr[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < wdth - 1; i++)
			bffr[BUFF_SIZE - i - 2] = pdd;

		if (flagger & F_MINUS)
			return (write(1, &bffr[0], 1) +
					write(1, &bffr[BUFF_SIZE - i - 1], wdth - 1));
		else
			return (write(1, &bffr[BUFF_SIZE - i - 1], wdth - 1) +
					write(1, &bffr[0], 1));
	}


	return (write(1, &bffr[0], 1));
}

/**
 * write_num_func - a function that print string
 * @_is_negat: a variable holding of arguments
 * @seprt: a variable holding char typfier.
 * @bffr: a variable holding array to handle print
 * @flagger: a variable holding active flagger
 * @wdth: a variable holding wdth.
 * @prec: a variable holding prec specifier
 * @size: a variable holding specifier
 *
 * Return: int
 */

int write_num_func(int _is_negat, int seprt, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	int length_ = BUFF_SIZE - seprt - 1;
	char pdd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flagger & F_ZERO) && !(flagger & F_MINUS))
		pdd = '0';
	if (_is_negat)
		extra_ch = '-';
	else if (flagger & F_PLUS)
		extra_ch = '+';
	else if (flagger & F_SPACE)
		extra_ch = ' ';

	return (write_no_func(seprt, bffr, flagger, wdth, prec,
				length_, pdd, extra_ch));
}

/**
 * write_no_func - a function that print a number using a bufffer
 * @seprt: a variable holding starts on the bffr
 * @bffr: a variable holding buffer
 * @flagger: a variable holding flags
 * @wdth: a variable holding wdth
 * @prec: a variable holding specifier
 * @length_: a variable holding number length_
 * @pdd: a variable holding char padding
 * @extra_charr: extra char
 * Return: int
 */

int write_no_func(int seprt, char bffr[],
		int flagger, int wdth, int prec,
		int length_, char pdd, char extra_charr)
{
	int i, padd_start = 1;

	if (prec == 0 && seprt == BUFF_SIZE - 2 && bffr[seprt] == '0' && wdth == 0)
		return (0);
	if (prec == 0 && seprt == BUFF_SIZE - 2 && bffr[seprt] == '0')
		bffr[seprt] = pdd = ' ';
	if (prec > 0 && prec < length_)
		pdd = ' ';
	while (prec > length_)
		bffr[--seprt] = '0', length_++;
	if (extra_charr != 0)
		length_++;
	if (wdth > length_)
	{
		for (i = 1; i < wdth - length_ + 1; i++)
			bffr[i] = pdd;
		bffr[i] = '\0';
		if (flagger & F_MINUS && pdd == ' ')
		{
			if (extra_charr)
				bffr[--seprt] = extra_charr;
			return (write(1, &bffr[seprt], length_) + write(1, &bffr[1], i - 1));
		}
		else if (!(flagger & F_MINUS) && pdd == ' ')
		{
			if (extra_charr)
				bffr[--seprt] = extra_charr;
			return (write(1, &bffr[1], i - 1) + write(1, &bffr[seprt], length_));
		}
		else if (!(flagger & F_MINUS) && pdd == '0')
		{
			if (extra_charr)
				bffr[--padd_start] = extra_charr;
			return (write(1, &bffr[padd_start], i - padd_start) +
					write(1, &bffr[seprt], length_ - (1 - padd_start)));
		}
	}
	if (extra_charr)
		bffr[--seprt] = extra_charr;
	return (write(1, &bffr[seprt], length_));
}

/**
 * write_un_sgnd_func - a function that outputs unsigned number
 * @_is_negat: a variable holding output numb is negative
 * @seprt: a variable holding starts in the bffr
 * @bffr: a variable holding array of chars
 * @flagger: a variable holding specifiers
 * @wdth: a variable holding specifier of wdth
 * @prec: a variable holding specifier
 * @size: a variable holding specifier size
 * Return: char
 */

int write_un_sgnd_func(int _is_negat, int seprt,
		char bffr[],
		int flagger, int wdth, int prec, int size)
{
	int length_ = BUFF_SIZE - seprt - 1, i = 0;
	char pdd = ' ';

	UNUSED(_is_negat);

	UNUSED(size);

	if (prec == 0 && seprt == BUFF_SIZE - 2 && bffr[seprt] == '0')
		return (0);

	if (prec > 0 && prec < length_)
		pdd = ' ';

	while (prec > length_)
	{
		bffr[--seprt] = '0';
		length_++;
	}

	if ((flagger & F_ZERO) && !(flagger & F_MINUS))
		pdd = '0';

	if (wdth > length_)
	{
		for (i = 0; i < wdth - length_; i++)
			bffr[i] = pdd;

		bffr[i] = '\0';

		if (flagger & F_MINUS)
		{
			return (write(1, &bffr[seprt], length_) + write(1, &bffr[0], i));
		}
		else
		{
			return (write(1, &bffr[0], i) + write(1, &bffr[seprt], length_));
		}
	}

	return (write(1, &bffr[seprt], length_));
}

/**
 * write_ptr_func - a function that outputs memory address
 * @bffr: a variable holding arrays of chars
 * @seprt: a variable holding starts in the bffr
 * @length_: a variable holding lgth of number
 * @wdth: a variable holding specifier width
 * @flagger: a variable holding specifier flag
 * @pdd: a variable holding the padding
 * @extra_charr: a variable holding extra char
 * @padd_start: a variable holding padding start
 * Return: int
 */

int write_ptr_func(char bffr[], int seprt, int length_,
		int wdth, int flagger, char pdd, char extra_charr, int padd_start)
{
	int i;

	if (wdth > length_)
	{
		for (i = 3; i < wdth - length_ + 3; i++)
			bffr[i] = pdd;
		bffr[i] = '\0';
		if (flagger & F_MINUS && pdd == ' ')
		{
			bffr[--seprt] = 'x';
			bffr[--seprt] = '0';
			if (extra_charr)
				bffr[--seprt] = extra_charr;
			return (write(1, &bffr[seprt], length_) + write(1, &bffr[3], i - 3));
		}
		else if (!(flagger & F_MINUS) && pdd == ' ')
		{
			bffr[--seprt] = 'x';
			bffr[--seprt] = '0';
			if (extra_charr)
				bffr[--seprt] = extra_charr;
			return (write(1, &bffr[3], i - 3) + write(1, &bffr[seprt], length_));
		}
		else if (!(flagger & F_MINUS) && pdd == '0')
		{
			if (extra_charr)
				bffr[--padd_start] = extra_charr;
			bffr[1] = '0';
			bffr[2] = 'x';
			return (write(1, &bffr[padd_start], i - padd_start) +
					write(1, &bffr[seprt], length_ - (1 - padd_start) - 2));
		}
	}
	bffr[--seprt] = 'x';
	bffr[--seprt] = '0';
	if (extra_charr)
		bffr[--seprt] = extra_charr;
	return (write(1, &bffr[seprt], BUFF_SIZE - seprt - 1));
}
