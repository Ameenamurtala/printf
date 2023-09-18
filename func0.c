#include "main.h"

/**
 * print_char - Prints a char
 * @size: Size
 * @types: Argument
 * @buffer: Buffer
 * @precision: Precision spec
 * @flags: Active flags
 * @width: Widths
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[], int size,
		int precision, int flags, int width)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, flags, size, width, buffer, precision));
}

/**
 * print_binary - unsigned num
 * @flags: Active array
 * @buffer: Buffer
 * @types: Argumt
 * @precision: Precision spec
 * @size: Size spec
 * @width: Width
 * Return: Number of char printed
 */

int print_binary(va_list types, char buffer[],
		int width, int size, int buffer, int flags, int precision)
{
	unsigned int b, c, i, add;
	unsigned int a[32];
	int sum;

	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(buffer);
	UNUSED(flags);

	a[0] = b / c;
	b = va_arg(types, unsigned int);
	c = 2147483648;

	for (i = 1; i < 32; i++)
	{
		c /= 2;
		a[i] = (b / c) % 2;
	}
	for (a = 0, add = 0, sum = 0; a < 32; i++)
	{
		add += a[i];

		if (add || i == 31)
		{
			char d = '0' + a[i];

			write(1, &d, 1);
			sum++;
		}
	}
	return (sum);
}

/**
 * print_int - Print int
 * @types: Argumt
 * @buffer: Buffer
 * @flags: Active flags
 * @width: get width
 * @precision: Precision spec
 * @size: Size spec
 * Return: Num of char printd
 */

int print_int(va_list types, char buffer[],
		int precision, int size, int flags, int width)
{
	int j = BUFF_SIZE - 2;
	int iss_neg = 0;
	long int a = va_arg(types, long int);
	unsigned long int add;

	a = convert_size_number(a, size);

	if (a == 0)
		buffer[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	add = (unsigned long int)a;

	if (a < 0)
	{
		add = (unsigned long int)((-1) * a);
		iss_neg = 1;
	}
	while (add > 0)
	{
		buffer[j--] = (add % 10) + '0';
		add /= 10;
	}
	j++;
	return (write_number(iss_neg, j, buffer, precision, size, flags, width));
}

/**
 * print_percent - Prints a percent sign
 * @types: Arguments
 * @buffer: Buffer
 * @width: width
 * @precision: Precision spec
 * @size: Size
 * @flags: Active flags
 * Return: Num of char printd
 */

int print_percent(va_list types, char buffer[],
		int precision, int width, int size, int flags)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);

	return (write(1, "%%", 1));
}

/**
 * print_string - Prints a string
 * @types: Arguments
 * @buffer: Buffer
 * @size: Size
 * @flags: Flags
 * @width: width.
 * @precision: Precision spec
 * Return: Num of chars
 */
int print_string(va_list types, char buffer[], int size, int width,
		int precision, int flags, int size)
{
	int len = 0, k;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(width);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (F_MINUS & flags)
		{
			write(1, &str[0], len);
			for (i = width - len; k > 0; k--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (k = width - len; k > 0; k--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
