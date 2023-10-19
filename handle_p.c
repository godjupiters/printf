#include "main.h"

/**
 * handle_print - a function that prints an arg
 * @format: a variable holding fmtted string
 * @lst: a variable holding the list of arg to print
 * @seprt: seprt
 * @bffr: a variable holding the buffer array
 * @flagger: a variable holding the act flagger
 * @wdth: a variable holding the wdth.
 * @prec: a variable holding the prec specification
 * @size: a variable holding the specifier
 * Return: int
 */

int handle_print(const char *format, int *seprt, va_list lst, char bffr[],
		int flagger, int wdth, int prec, int size)
{
	int i, unknwn_len = 0, prtd_c = -1;
	form_t fmt_types[] = {
		{'c', print_c}, {'s', print_s}, {'%', print_per},
		{'i', print_i}, {'d', print_i}, {'b', print_b},
		{'u', print_un}, {'o', print_octalll}, {'x', print_hexdec},
		{'X', print_hexaupcase}, {'p', print_pointr},
		{'S', print_nonprint},
		{'r', print_rev_func}, {'R', print_r13s}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].format != '\0'; i++)
		if (format[*seprt] == fmt_types[i].format)
			return (fmt_types[i].fn(lst, bffr, flagger,
						wdth, prec, size));

	if (fmt_types[i].format == '\0')
	{
		if (format[*seprt] == '\0')
			return (-1);
		unknwn_len += write(1, "%%", 1);
		if (format[*seprt - 1] == ' ')
			unknwn_len += write(1, " ", 1);
		else if (wdth)
		{
			--(*seprt);
			while (format[*seprt] != ' ' && format[*seprt] != '%')
				--(*seprt);
			if (format[*seprt] == ' ')
				--(*seprt);
			return (1);
		}
		unknwn_len += write(1, &format[*seprt], 1);
		return (unknwn_len);
	}
	return (prtd_c);
}
