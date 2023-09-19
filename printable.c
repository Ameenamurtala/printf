#include "main.h"
/**
 * is_printable - Eval
 * @c: Char
 * Return: 1 , 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - Append
 * @buffer: Array
 * @p: Index
 * @ascii_code: ASSCI
 * Return: Al 3
 */
int append_hexa_code(char ascii_code, char buffer[], int p)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[p++] = '\\';
	buffer[p++] = 'x';
	buffer[p++] = map_to[ascii_code / 16];
	buffer[p] = map_to[ascii_code % 16];
	return (3);
}

/**
 * is_digit - digit
 * @c: Char
 * Return: 1, 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - Casts
 * @num: Num
 * @size: Num
 * Return: Cast
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * convert_size_unsigned - Casts
 * @num: Num
 * @size: Num
 * Return: num
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
