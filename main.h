#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int putchr(char c);

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define S_SHORT 1
#define S_LONG 2

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - Struct op
 * @fn: Function
 * @fmt: Format
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int meenah_print(const char *fomat, int *j,
		va_list list, char buffer[],
		int precision, int size,
		int width, int flags);

int print_char(va_list types, char buffer[],
		int precision, int size,
		int width, int flags);
int print_string(va_list types, char buffer[],
		int precision, int size,
		int width, int flags);
int print_percentage(va_list types, char buffer[],
		int precision, int size,
		int width, int flags);
int print_int(va_list types, char buffer[],
		int flags, int width,
		int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width,
		int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width,
		int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width,
		int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width,
		int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width,
		int precision, int size);
int print_hexa(va_list types, char map_to[],
		char buffer[], int flags,
		char flag_ch, int width,
		int precision, int size);
#endif
