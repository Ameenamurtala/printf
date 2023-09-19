#include "main.h"

/**
 * print_unsigned - Prints
 * @types: Argument
 * @buffer: buffer
 * @flag: flag
 * @width: width
 * @sizes: Sizes
 * @prec: Prec
 * Return: Num
 */
int print_unsigned(va_list types, char buffer[],
		int flag, int sizes, int width, int prec)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}
	k++;
	return (write_unsgnd(0, k, buffer, flag, sizes, width, prec));
}

/**
 * print_octal - Print
 * @types: List
 * @buffer: Buffer
 * @flag: Flag
 * @width: width
 * @sizes: Sizes
 * @prec: Prec
 * Return: Num
 */
int print_octal(va_list types, char buffer[],
		int flag, int sizes,  int width, int prec)
{
	int m = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[m--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[m--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & F_HASH && init_num != 0)
		buffer[m--] = '0';
	m++;
	return (write_unisgned(0, m, buffer, flag, sizes, width, prec));
}

/**
 * print_hexadecimal - Prints
 * @types: Argument
 * @buffer: Buffer
 * @flag: Flag
 * @width: Width
 * @sizes: Sizes
 * @prec: Prec
 * Return: Num
 */
int print_hexadecimal(va_list types, char buffer[],
		int flag, int sizes, int width, int prec)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flag, 'x', sizes, width, prec));
}
/**
 * print_hexa_upper - Prints
 * @types: List
 * @buffer: Buffer
 * @flag: flag
 * @width: Width
 * @sizes: Sizes
 * @prec: Prec
 * Return: Num
 */
int print_hexa_upper(va_list types, char buffer[],
		int flag, int sizes, int width, int prec)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flag, 'X', sizes, width, prec));
}

/**
 * print_hexa - Prints
 * @types: Argument
 * @width: width
 * @buffer: Buffer
 * @map_to: Array
 * @flag_ch: Flag
 * @flag: Flag
 * @sizes: Sizes
 * @prec: Prec
 * Return: Num
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flag, char flag_ch, int sizes, int width, int prec)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}
	j++;

	return (write_unsgnd(0, j, buffer, flag, size, width, prec));
}
