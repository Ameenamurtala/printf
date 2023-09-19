#include "main.h"
/**
 * print_unsigned - Print
 * @types: List
 * @buffer: Buffer
 * @flags:  Calc
 * @width: width
 * @precision: Prec
 * @size: Size
 * Return: Number
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;
	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints
 * @types: List
 * @buffer: Buffer
 * @flags:  Cal
 * @width: get
 * @precision: Prec
 * @size: Size spec
 * Return: Number
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
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
	if (flags & F_HASH && init_num != 0)
		buffer[m--] = '0';
	m++;
	return (write_unsgnd(0, m, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Print
 * @types: List
 * @buffer: Buffer
 * @flags:  Cal
 * @width: idth
 * @precision: Pre
 * @size: Size
 * Return: Number
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Prints
 * @types: Lista
 * @buffer: Buffer
 * @flags:  Ca
 * @width: width
 * @precision: Prec
 * @size: Size
 * Return: Num
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - Print
 * @types: List
 * @map_to: Array
 * @buffer: Buff
 * @flags:  Cal
 * @flag_ch: Cal
 * @width: get w
 * @precision: Pre
 * @size: Size spec
 * @size: Si
 * Return: Num
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
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
	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}
	j++;
	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
