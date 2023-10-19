#include "main.h"

/**
 * get_flags_func - a function that cal active flag
 * @format: a variable holding arguments
 * @i: a variable holding a parameter.
 * Return: flag
 */

int get_flags_func(const char *format, int *i)
{
	int bn, cur_cnt;
	int flagger = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_cnt = *i + 1; format[cur_cnt] != '\0'; cur_cnt++)
	{
		for (bn = 0; FLAGS_CH[bn] != '\0'; bn++)
			if (format[cur_cnt] == FLAGS_CH[bn])
			{
				flagger |= FLAGS_ARR[bn];
				break;
			}

		if (FLAGS_CH[bn] == 0)
			break;
	}

	*i = cur_cnt - 1;

	return (flagger);
}
