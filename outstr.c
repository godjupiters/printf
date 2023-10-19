#include "main.h"

/**
 * outstr - a function that outputs strings
 * @s: a variable holding the value
 * Return: len
 */

int outstr(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		_putcharP(s[len]);
		len++;
	}
	return (len);
}
