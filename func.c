#include "main.h"

/**
 * print_unsigned - Prints
 * @types: Argument
 * @bee: Bee
 * @flags: flags
 * @width: width
 * @size: Size specifier
 * @precision: Precision spec
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char bee[],
		int flags, int width, int size, int precision)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		bee[k--] = '0';
	bee[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bee[k--] = (num % 10) + '0';
		num /= 10;
	}
	k++;
	return (write_unsgnd(0, k, bee, flags, width, size, precision));
}

/**
 * print_octal - Prints unsgned
 * @types: List
 * @bee: Bee
 * @flags: Flags
 * @width: width
 * @size: Size
 * @precision: Precision
 * Return: Num
 */
int print_octal(va_list types, char bee[],
		int flags, int width, int size, int precision)
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
		bee[m--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		bee[m--] = '0';
	m++;
	return (write_unsgnd(0, m, bee, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints
 * @types: Argument
 * @bee: Bee
 * @flags: Flags
 * @width: Width
 * @size: Size
 * @precision: Precision
 * Return: Num
 */
int print_hexadecimal(va_list types, char bee[],
		int flags, int width, int size, int precision)
{
	return (print_hexa(types, "0123456789abcdef", bee,
				flags, 'x', width, size, precision));
}
/**
 * print_hexa_upper - Prints
 * @types: List of argument
 * @bee: Bee
 * @flags: flags
 * @width: Width
 * @size: Size
 * @precision: Precision
 * Return: Numbers of chars
 */
int print_hexa_upper(va_list types, char bee[],
		int flags, int width, int size, int precision)
{
	return (print_hexa(types, "0123456789ABCDEF", bee,
				flags, 'X', width, size, precision));
}

/**
 * print_hexa - Prints
 * @types: Argument
 * @width: get width
 * @bee: Bee
 * @map_to: Array of values
 * @flag_ch: Flags
 * @flags: Flags
 * @size: Size
 * @precision: Prec
 * Return: Num
 */
int print_hexa(va_list types, char map_to[], char bee[],
		int flags, char flag_ch, int size, int width, int precision)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		bee[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bee[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		bee[j--] = flag_ch;
		bee[j--] = '0';
	}
	j++;

	return (write_unsgnd(0, j, bee, flags, width, size, precision));
}
