#include "main.h"

/**
 * is_prt_func - a function that checks char is printable
 * @c: a variable holding char to eva
 * Return: 1 or 0
 */

int is_prt_func(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * app_h_cod_func - a function that pends ascci in hexadecimal for buff
 * @bffr: a variable holding chars.
 * @i: a variable holding start appending.
 * @ascii_codes_: a variable holding ASSCI CODE.
 * Return: 3
 */

int app_h_cod_func(char ascii_codes_, char bffr[], int i)
{
	char syn_to[] = "0123456789ABCDEF";

	if (ascii_codes_ < 0)
		ascii_codes_ *= -1;

	bffr[i++] = '\\';
	bffr[i++] = 'x';

	bffr[i++] = syn_to[ascii_codes_ / 16];
	bffr[i] = syn_to[ascii_codes_ % 16];

	return (3);
}

/**
 * is_d_func - a function that check a char is a digit
 * @c: a variable holding evaluated char
 * Return: 1 or 0
 */

int is_d_func(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * conv_size_num_func - a function that outputs number specific size
 * @numb: a variable holding no to be casted.
 * @size: a variable holding no casted.
 * Return: int
 */

long int conv_size_num_func(long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * convt_size_unsgnd_func - a func to cast no to specific size
 * @numb: a variable holding no to cast
 * @size: a variable holding the type to be casted
 * Return: num
 */

long int convt_size_unsgnd_func(unsigned long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}
