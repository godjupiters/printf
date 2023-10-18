#include "main.h"

/**
 * _putcharP - a function that prints char
 * @c: variable holding the char
 * Return: returns c
 */

int _putcharP(char c)
{
	return (write(1, &c, 1));
}
