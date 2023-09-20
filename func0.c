#include "main.h"
/**
 * print_char - Print
 * @types: List
 * @buffer: Buff
 * @flags:  Cal
 * @width: Width
 * @precision: Prec
 * @size: Siz
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
 * @buffer: Buff
 * @flags: flags
 * @width: wdth
 * @precision: Prec
 * @size: Size
 * Return: Num
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, m;
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
			for (m = width - length; m > 0; m--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (m = width - length; m > 0; m--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent - sign
 * @types: List
 * @buffer: Buf
 * @flags: flags
 * @width: width
 * @precision: Prec
 * @size: Size spec
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
 * print_int -  int
 * @types: List
 * @buffer: Buf
 * @flags: flags
 * @width: width
 * @precision: Prec
 * @size: Size
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
	return (write_number(is_negative, m, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints
 * @types: List
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: Prec
 * @size: Size
 * Return: Num
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int b, c, d, plus;
	unsigned int a[32];
	int add;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b = va_arg(types, unsigned int);
	c = 2147483648;
	a[0] = b / c;
	for (d = 1; d < 32; d++)
	{
		c /= 2;
		a[d] = (b / c) % 2;
	}
	for (d = 0, plus = 0, add = 0; d < 32; d++)
	{
		plus += a[d];
		if (plus || d == 31)
		{
			char x = '0' + a[d];

			write(1, &x, 1);
			add++;
		}
	}
	return (add);
}
