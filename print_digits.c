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
