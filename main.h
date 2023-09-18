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

int get_counter(const char *format, int *i);
int get_meenah(const char *format, int *i, va_list list);
int get_eze(const char *format, int *i, va_list list);
int get_boss(const char *format, int *i);
#endif
