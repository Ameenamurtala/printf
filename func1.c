#include "main.h"
/**
 * print_pointer - Value
 * @types: Arguments
 * @bee: Array
 * @size: size
 * @width: Width
 * @flags: Flags
 * @precision: Precision
 * Return: Num
 */

int print_pointer(va_list types, char bee[],
		int size, int width, int flags, int precision)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	bee[BUFF_SIZE]
		num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		bee[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;
	ind++;
	return (write_pointer(bee, ind, len,
				width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Ascii
 * @types: Argument
 * @bee: Bee
 * @size: Size
 * @width: Width
 * @flags: Flags
 * @precision: Precision
 * Return: Num of char
 */
int print_non_printable(va_list types, char bee[],
		int size, int width, int flags, int precision)
{
	int k = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[k] != '\0')
	{
		if (is_printable(str[k]))
			bee[k + offset] = str[k];
		else
			offset += append_hexa_code(str[k], bee, k + offset);
		k++;
	}
	bee[k + offset] = '\0';
	return (write(1, bee, k + offset));
}

/**
 * print_reverse - Print
 * @types: Arguments
 * @bee: Bee
 * @size: Size
 * @width: Width
 * @flags:  Flags
 * @precision: Precision
 * Return: Nums
 */

int print_reverse(va_list types, char bee[],
		int size, int width, int flags, int precision)
{
	char *str;
	int k, add = 0;

	UNUSED(bee);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);
	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (k = 0; str[k]; k++)
		;
	for (k = k - 1; k >= 0; k--)
	{
		char x = str[k];

		write(1, &x, 1);
		add++;
	}
	return (add);
}

/**
 * print_rot13string - Print
 * @types: Arguments
 * @bee: Bee
 * @size: Size
 * @width: Width
 * @flags: Flags
 * @precision: Precision
 * Return: Num of char
 */
int print_rot13string(va_list types, char bee[],
		int size, int width, int flags, int precision)
{
	char c;
	char *str;
	unsigned int n, m;
	int sum = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);

	UNUSED(bee);
	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);

	if (str == NULL)
		str = "(AHYY)";
	for (n = 0; str[n]; n++)
	{
		for (m = 0; in[m]; m++)
		{
			if (in[m] == str[n])
			{
				c = out[m];
				write(1, &c, 1);
				sum++;
				break;
			}
		}
		if (!in[m])
		{
			c = str[i];
			write(1, &c, 1);
			sum++;
		}
	}
	return (sum);
}
