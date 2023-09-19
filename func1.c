#include "main.h"
/**
 * print_pointer - Value
 * @types: Arguments
 * @buffer: Array
 * @sizes: size
 * @width: Width
 * @flag: Flag
 * @prec: Prec
 * Return: Num
 */

int print_pointer(va_list types, char buffer[],
		int flag, int sizes, int width, int prec)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(sizes);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE]
		num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	return (write_pointer(buffer, ind, length,
				width, flag, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Ascii
 * @types: Argument
 * @buffer: Buffer
 * @sizes: Sizes
 * @width: Width
 * @flag: Flag
 * @prec: Prec
 * Return: Num of char
 */
int print_non_printable(va_list types, char buffer[],
		int flag, int sizes, int width, int prec)
{
	int k = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flag);
	UNUSED(size);
	UNUSED(width);
	UNUSED(prec);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[k] != '\0')
	{
		if (is_printable(str[k]))
			buffer[k + offset] = str[k];
		else
			offset += append_hexa_code(str[k], buffer, k + offset);
		k++;
	}
	buffer[k + offset] = '\0';
	return (write(1, buffer, k + offset));
}

/**
 * print_reverse - Print
 * @types: Arguments
 * @buffer: Buffer
 * @flag: flag
 * @sizes: Sizes
 * @width: Width
 * @prec: Prec
 * Return: Nums
 */

int print_reverse(va_list types, char buffer[],
		int sizes, int width, int flag, int prec)
{
	char *str;
	int k, add = 0;

	UNUSED(buffer);
	UNUSED(sizes);
	UNUSED(width);
	UNUSED(flag);
	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(prec);
		str = ")Null(";
	}
	for (k = 0; str[k]; k++)

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
 * @buffer: Buffer
 * @sizes: Sizes
 * @width: Width
 * @flag: Flag
 * @prec: Prec
 * Return: Num of char
 */
int print_rot13string(va_list types, char buffer[],
		int flag, int sizes, int width, int prec)
{
	char c;
	char *str;
	unsigned int n, m;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(sizes);
	UNUSED(width);
	UNUSED(flag);
	UNUSED(prec);

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
				count++;
				break;
			}
		}
		if (!in[m])
		{
			c = str[n];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
