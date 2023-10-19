#ifndef MAIN_H
#define MAIN_H



#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - variable holding the struct
 * @format: The format.
 * @fn: The function associated.
 */

struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format form_t - Struct op
 * @format: variable holding the format.
 * @vfmt: function passed
 */

typedef struct format form_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *i,
va_list lst, char bffr[], int flagger, int wdth, int prec, int size);


int print_c(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);
int print_s(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);
int print_per(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);

int print_i(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);
int print_b(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);
int print_un(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);
int print_octalll(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);
int print_hexdec(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);
int print_hexaupcase(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);

int print_hexachar(va_list typfier, char syn_to[],
char bffr[], int flagger, char flag_ch, int wdth, int prec, int size);

int print_nonprint(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);

int print_pointr(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);

int get_flags_func(const char *format, int *i);
int get_width_func(const char *format, int *i, va_list lst);
int get_prec_func(const char *format, int *i, va_list lst);
int get_size_func(const char *format, int *i);

int print_rev_func(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);

int print_r13s(va_list typfier, char bffr[],
	int flagger, int wdth, int prec, int size);

int handle_w_c_func(char c, char bffr[],
	int flagger, int wdth, int prec, int size);
int write_num_func(int is_positive, int seprt, char bffr[],
	int flagger, int wdth, int prec, int size);
int write_no_func(int seprt, char bff[], int flagger, int wdth, int prec,
	int length_, char pdd, char extra_charr);
int write_ptr_func(char bffr[], int seprt, int length_,
	int wdth, int flagger, char pdd, char extra_charr, int padd_start);

int write_un_sgnd_func(int _is_negat, int seprt,
char bffr[],
	int flagger, int wdth, int prec, int size);

int is_prt_func(char);
int app_h_cod_func(char, char[], int);
int is_d_func(char);

long int conv_size_num_func(long int numb, int size);
long int convt_size_unsgnd_func(unsigned long int numb, int size);

#endif
