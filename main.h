#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int putchr(char c);

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1
/**
 * struct fmt - struct
 * @fmt: formt
 * @fn: fn
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char bee[], int flags, int width, int precision, int size);

int print_char(va_list types, char bee[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char bee[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char bee[],
	int flags, int width, int precision, int size);

int print_int(va_list types, char bee[],
	int flags, int width, int precision, int size);
int print_beenary(va_list types, char bee[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char bee[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char bee[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char bee[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char bee[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char bee[], int flags, char flag_ch, int width, int precision, int size);

int print_non_printable(va_list types, char bee[],
	int flags, int width, int precision, int size);

int print_pointer(va_list types, char bee[],
	int flags, int width, int precision, int size);

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char bee[], int flags, int width, int precision, int size);

void print_bee(char bee[], int *buff_ind);
int get_counter(const char *format, int *i);
int get_meenah(const char *format, int *i, va_list list);
int get_eze(const char *format, int *i, va_list list);
int get_boss(const char *format, int *i);

int print_reverse(va_list types, char bee[],
	int flags, int width, int precision, int size);

int print_rot13string(va_list types, char bee[],
	int flags, int width, int precision, int size);

int handle_write_char(char c, char bee[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char bee[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bee[], int flags, int width, int precision,
	int len, char padd, char extra_c);
int write_pointer(char bee[], int ind, int len,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned(int is_negative, int ind,
char bee[],
	int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif
