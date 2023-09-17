#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int putchr(char c);

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fmt -Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: format
 * @fm_t: function
 */
typedef struct fmt fmt_t;

int meenah_printf(const char *meenah_format, ...);
int meenah_handle_print(const char *meenah_fmt, int *meenah_i,
		va_list meenah_list, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);

/****************** FUNCTIONS ****************/

/* Functions to print strings and char */
int meenah_print_char(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_print_string(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_print_percent(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);

/* Functions to print numbers */
int meenah_print_int(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_print_binary(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_print_unsigned(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_print_octal(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_print_hexadecimal(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_print_hexa_upper(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_print_hexa(va_list meenah_types, char meenah_map_to[],
		char meenah_buffer[], int meenah_flags,
		char meenah_flag_ch, int meenah_width,
		int meenah_precision, int meenah_size);

/* Function to print non-printable characters */
int meenah_print_non_printable(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);

/* Function to print memory address */
int meenah_print_pointer(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);

/* Functions to handle other specifiers */
int meenah_get_flags(const char *meenah_format, int *meenah_i);
int meenah_get_width(const char *meenah_format, int *meenah_i,
		va_list meenah_list);
int meenah_get_precision(const char *meenah_format, int *meenah_i,
		va_list meenah_list);
int meenah_get_size(const char *meenah_format, int *meenah_i);

/* Function to print string in reverse */
int meenah_print_reverse(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);

/* Function to print a string in ROT13 */
int meenah_print_rot13string(va_list meenah_types, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);

/* Width handler */
int meenah_handle_write_char(char c, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_write_number(int is_positive, int ind, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size);
int meenah_write_num(int ind, char meenah_bff[], int meenah_flags,
		int meenah_width, int meenah_precision,
		int meenah_length, char meenah_padd, char meenah_extra_c);
int meenah_write_pointer(char meenah_buffer[], int ind, int length,
		int meenah_width, int meenah_flags,
		char meenah_padd, char meenah_extra_c, int meenah_padd_start);

int meenah_write_unsgnd(int is_negative, int ind,
		char meenah_buffer[], int meenah_flags,
		int meenah_width, int meenah_precision, int meenah_size);

/****************** UTILS ****************/
int meenah_is_printable(char);
int meenah_append_hexa_code(char, char[], int);
int meenah_is_digit(char);

long int meenah_convert_size_number(long int num, int size);
long int meenah_convert_size_unsgnd(unsigned long int num, int size);

#endif
