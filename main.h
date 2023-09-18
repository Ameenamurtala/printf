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

#define S_SHORT 1
#define S_LONG 2

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#endif
