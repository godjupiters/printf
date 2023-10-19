#include "main.h"

void prnt_buffer(char bffr[], int *buff_ind);

/**
 * _printf - a function that calls func by type
 * @format: a variable holding format
 * Return: chars
 */

int _printf(const char *format, ...)
{
	int i, printprnt = 0, prtd_c = 0;
	int flagger, wdth, prec, size, buff_ind = 0;
	va_list lst;
	char bffr[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lst, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bffr[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				prnt_buffer(bffr, &buff_ind);

			prtd_c++;
		}
		else
		{
			prnt_buffer(bffr, &buff_ind);
			flagger = get_flags_func(format, &i);
			wdth = get_width_func(format, &i, lst);
			prec = get_prec_func(format, &i, lst);
			size = get_size_func(format, &i);
			++i;
			printprnt = handle_print(format, &i, lst, bffr,
				flagger, wdth, prec, size);
			if (printprnt == -1)
				return (-1);
			prtd_c += printprnt;
		}
	}

	prnt_buffer(bffr, &buff_ind);

	va_end(lst);

	return (prtd_c);
}

/**
 * prnt_buffer - sa function that prints present value in bffr
 * @bffr: a variable holding array of chars
 * @buff_ind: a variable holding index
 */

void prnt_buffer(char bffr[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &bffr[0], *buff_ind);

	*buff_ind = 0;
}
