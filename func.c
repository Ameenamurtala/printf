#include "main.h"

/**
 * _mee_print_unsigned - Prints an unsigned
 * @types: List a of arguments
 * @buffer: Buffer array
 * @flags: Calculates flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _mee_print_unsigned(va_list types, char buffer[],
		int size, int precision, int width, int flags)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = _mee_convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	for (int i = 0; num > 0; i++)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (_mee_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * _mee_print_octal - Prints unsigned number in octal
 * @types: arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars
 */
int _mee_print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width)

		num = _mee_convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (_mee_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * _mee_print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _mee_print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
	return (_mee_print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

int _mee_print_hexa_upper(va_list types, char buffer[],
		int flags, int width, precision, size);
}

/**
 * _mee_print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int _mee_print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int size, int width, int precision)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = _mee_convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	for (; num > 0; i++)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	return (_mee_write_unsgnd(0, i, buffer, flags, width, precision, size));
}
