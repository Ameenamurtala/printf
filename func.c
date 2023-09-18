#include "main.h"

/**
 * print_unsigned - Prints an unsigned
 * @types: Argument
 * @buffer: Buffer array
 * @flags: Active flags
 * @width: get width
 * @size: Size specifier
 * @precision: Precision spec
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
		int size, int precision, int width, int flags)
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
	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints unsigned number
 * @types: List argument
 * @width: get width
 * @size: Size spec
 * @buffer: Buffer array
 * @flags: Active flag
 * @precision: Precision spec
 * Return: Number of chars
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _mee_convert_size_unsgnd(num, size);

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
 * print_hexadecimal - Prints an unsigned number in hexa
 * @size: Size spec
 * @types: Argument
 * @width: get width
 * @flags: ACtive flags
 * @buffer: Buffer array
 * @precision: Precision spec
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Prints an unsigned num
 * @types: List of argument
 * @buffer: Buffer
 * @flags: Cal active flags
 * @precision: Precision spec
 * @size: Size spec
 * @width: get width
 * Return: Numbers of chars
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal num
 * @types: Argument
 * @width: get width
 * @size: Size specf
 * @size: Size specifier
 * @map_to: Array of values
 * @precision: Precision spec
 * @flag_ch: Flags
 * @flags: Active flags
 * @buffer: Buffer array
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int size, int width, int precision)
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
