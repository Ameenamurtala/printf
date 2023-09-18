#include "main.h"

/**
 * print_char - Print char
 * @types: Argument
 * @bee: Bee
 * @size: Size
 * @precision: Precision
 * @flags: flags
 * @width: Widths
 * Return: Number of chars
 */
int print_char(va_list types, char bee[], int size,
		int precision, int flags, int width)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, flags, size, width, bee, precision));
}

/**
 * print_binary - unsgnd
 * @types: Argument
 * @bee: Bee
 * @size: Size
 * @precision: Precision
 * @flags: flags
 * @width: Width
 * Return: count
 */

int print_beenary(va_list types, char bee[],
		int size, int precision, int flags, int width)
{
	unsigned int b, c, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(bee);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(width);

	a[0] = b / c;
	b = va_arg(types, unsigned int);
	c = 2147483648;

	for (i = 1; i < 32; i++)
	{
		c /= 2;
		a[i] = (b / c) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];

		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * print_int - Print int
 * @types: Argumt
 * @bee: Bee
 * @size: Size
 * @precision: Precision
 * @flags: flags
 * @width: width
 * Return: Num
 */

int print_int(va_list types, char bee[],
		int size, int precision, flags, int width)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int a = va_arg(types, long int);
	unsigned long int add;

	a = convert_size_number(a, size);

	if (a == 0)
		bee[j--] = '0';
	bee[BUFF_SIZE - 1] = '\0';
	add = (unsigned long int)a;

	if (a < 0)
	{
		add = (unsigned long int)((-1) * a);
		is_negative = 1;
	}
	while (add > 0)
	{
		bee[j--] = (add % 10) + '0';
		add /= 10;
	}
	j++;
	return (write_number(iss_neg, i, bee, precision, size, flags, width));
}

/**
 * print_percent - Percent
 * @types: Arguments
 * @bee: Bee
 * @size: Size
 * @precision: Precision spec
 * @flags: flags
 * @width: Width
 * Return: Num
 */

int print_percent(va_list types, char bee[],
		int size, int precision, int flags, int width)
{
	UNUSED(types);
	UNUSED(bee);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(width);

	return (write(1, "%%", 1));
}

/**
 * print_string - A string
 * @types: Arguments
 * @bee: Bee
 * @size: Size
 * @precision: Precision
 * @flags: Flags
 * @width: width
 * Return: Num of chars
 */
int print_string(va_list types, char bee[], int size, int size,
		int precision, int flags, int width)
{
	int len = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(bee);
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
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
