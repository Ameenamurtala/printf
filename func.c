#include "main.h"
/**
 * print_char - Pr
 * @types: Lis
 * @buffer: Buff
 * @flags:  Cal
 * @width: Width
 * @precision: Prec
 * @size: Size
 * Return: Num
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - Print
 * @types: List
 * @buffer: Buf
 * @flags:  Cal
 * @width: ge
 * @precision: Prec
 * @size: Size
 * Return: Num
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, j;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent - Print
 * @types: List
 * @buffer: Buff
 * @flags:  Cal
 * @width: idth.
 * @precision: Prec
 * @size: size
 * Return: Num
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Print
 * @types: Lista
 * @buffer: Buffer
 * @flags:  Cal
 * @width: get
 * @precision: Pr
 * @size: Si
 * Return: Num
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	int is_negative = 0;
	long int a = va_arg(types, long int);
	unsigned long int num;

	a = convert_size_number(a, size);

	if (a == 0)
		buffer[m--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)a;

	if (a < 0)
	{
		num = (unsigned long int)((-1) * a);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[m--] = (num % 10) + '0';
		num /= 10;
	}

	m++;
	return (write_number(is_negative, m, flags, size, buffer, width, precision));
}

/**
 * print_binary - Print
 * @types: List
 * @buffer: Buffer
 * @flags:  Cal
 * @width: width
 * @precision: Prec
 * @size: Size
 * Return: Numb
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, z, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648;
	a[0] = x / y;
	for (z = 1; z < 32; z++)
	{
		y /= 2;
		a[z] = (x / y) % 2;
	}
	for (z = 0, sum = 0, count = 0; z < 32; z++)
	{
		sum += a[z];
		if (sum || z == 31)
		{
			char i = '0' + a[z];

			write(1, &i, 1);
			count++;
		}
	}
	return (count);
}
