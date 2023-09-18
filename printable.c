#include "main.h"

/**
 * is_printable - Eval
 * @c: Char
 * Return: 1, 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Ap
 * @bee: Arr
 * @i: Index
 * @ascii_code: ASSCI
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char bee[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	bee[i++] = '\\';
	bee[i++] = 'x';

	bee[i++] = map_to[ascii_code / 16];
	bee[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - V
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
 * convert_size_unsgnd - Cast
 * @num: Num
 * @size: Num
 * Return: Cast
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
