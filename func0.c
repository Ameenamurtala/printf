#include "main.h"

/**
 * print_char - Print char
 * @types: Argument
 * @buffer: Bee
 * @sizes: Sizes
 * @prec: prec
 * @flags: flag
 * @width: Width
 * Return: Num
 */
int print_char(va_list types, char buffer[],int flag, int size,
		 int width, int prec)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags,
				size, width, prec));
}

/**
 * print_binary - unsigned
 * @types: Argument
 * @buffer: buffer
 * @sizes: Sizes
 * @prec: Prec
 * @flag: flag
 * @width: Width
 * Return: count
 */

int print_binary(va_list types, char buffer[],
		int flag, int sizes, int width, int prec)
{
	unsigned int b, c, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(sizes);
	UNUSED(prec);
	UNUSED(flag);
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
 * @buffer: buffer
 * @sizes: Sizes
 * @prec: Prec
 * @flag: flag
 * @width: width
 * Return: Num
 */

int print_int(va_list types, char buffer[],
		int flag, int sizes, int width, int prec)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
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
		is_negative = 1;
	}
	while (add > 0)
	{
		buffer[j--] = (add % 10) + '0';
		add /= 10;
	}
	j++;
	return (write_number(is_negative, j, buffer, flag, sizes, width, prec));
}

/**
 * print_percent - Percent
 * @types: Arguments
 * @buffer: buffer
 * @sizes: Sizse
 * @prec: Prec
 * @flag: flags
 * @width: Width
 * Return: Num
 */

int print_percent(va_list types, char buffer[],
		int flag, int sizes, int width,  int prec)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(sizes);
	UNUSED(width);
	UNUSED(prec);

	return (write(1, "%%", 1));
}

/**
 * print_string - A string
 * @types: Arguments
 * @buffer: Buffer
 * @sizes: Size
 * @prec: Prec
 * @flag: Flag
 * @width: width
 * Return: Num of chars
 */
int print_string(va_list types, char buffer[], int flag, int sizes, int width,
		int prec)
{
	int length = 0, j;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(sizes);
	UNUSED(width);
	UNUSED(prec);

	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (prec>= 0 && prec < len)
		length = prec;
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
