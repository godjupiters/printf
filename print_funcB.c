#include "main.h"

/**
 * print_un - a function that prints unsigned number
 * @typfier: a variable holding arguments
 * @bffr: a variable holding array to handle print
 * @flagger:  a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: no of char
 */

int print_un(va_list typfier, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(typfier, unsigned long int);

	numb = convt_size_unsgnd_func(numb, size);

	if (numb == 0)
		bffr[i--] = '0';

	bffr[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		bffr[i--] = (numb % 10) + '0';
		numb /= 10;
	}

	i++;


	return (write_un_sgnd_func(0, i, bffr, flagger, wdth, prec, size));
}

/**
 * print_octalll - a function that prints unsigned
 * number in octal notation
 * @typfier: a variable holding arguments
 * @bffr: a variable holding array to handle print
 * @flagger:  a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: char
 */

int print_octalll(va_list typfier, char bffr[],
		int flagger, int wdth, int prec, int size)
{


	int i = BUFF_SIZE - 2;

	unsigned long int numb = va_arg(typfier, unsigned long int);

	unsigned long int init_num = numb;

	UNUSED(wdth);

	numb = convt_size_unsgnd_func(numb, size);

	if (numb == 0)
		bffr[i--] = '0';

	bffr[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		bffr[i--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flagger & F_HASH && init_num != 0)
		bffr[i--] = '0';
	i++;

	return (write_un_sgnd_func(0, i, bffr, flagger, wdth, prec, size));
}

/**
 * print_hexdec - a function that prints unsigned number in hexadecimal
 * @typfier: a variable holding arguments
 * @bffr: a variable holding buffer
 * @flagger:  a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: int
 */

int print_hexdec(va_list typfier, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	return (print_hexachar(typfier, "0123456789abcdef", bffr,
				flagger, 'x', wdth, prec, size));
}

/**
 * print_hexaupcase - a function that print unsigned
 * number in upper hexadecimal
 * @typfier: a variable holding arguments
 * @bffr: a variable holding array to handle print
 * @flagger:  a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * Return: int
 */

int print_hexaupcase(va_list typfier, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	return (print_hexachar(typfier, "0123456789ABCDEF", bffr,
				flagger, 'X', wdth, prec, size));
}

/**
 * print_hexachar - a function that prints hexadecimal number in lower/upper
 * @typfier: a variable holding arguments
 * @syn_to: a variable holding value to map
 * @bffr: a variable holding array print
 * @flagger:  a variable holding active flagger
 * @flag_ch: a variable holding active flagger
 * @wdth: a variable holding wdth
 * @prec: a variable holding specification
 * @size: a variable holding specifier
 * @size: a variable holding specification
 * Return: int
 */

int print_hexachar(va_list typfier, char syn_to[], char bffr[],
		int flagger, char flag_ch, int wdth, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(typfier, unsigned long int);
	unsigned long int init_num = numb;

	UNUSED(wdth);

	numb = convt_size_unsgnd_func(numb, size);

	if (numb == 0)
		bffr[i--] = '0';

	bffr[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		bffr[i--] = syn_to[numb % 16];
		numb /= 16;
	}

	if (flagger & F_HASH && init_num != 0)
	{
		bffr[i--] = flag_ch;
		bffr[i--] = '0';
	}

	i++;

	return (write_un_sgnd_func(0, i, bffr, flagger, wdth, prec, size));
}
