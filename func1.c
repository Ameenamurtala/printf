#include "main.h"
/**
 * print_pointer - Print
 * @types: List
 * @buffer: Buffer
 * @flags:  Cal
 * @width: width
 * @precision: Prec
 * @size: Size
 * Return: Num
 */
int print_painter(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Print
 * @types: List
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Prec
 * @size: Size
 * Return: Num
 */
int print_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

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
 * print_reverse - Pr
 * @types: Li
 * @buffer: Buf
 * @flags:  C
 * @width: w
 * @precision: Pre
 * @size: S
 * Return: N
 */

int print_adverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int k, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

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
		char c = str[k];

		write(1, &c, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Print
 * @types: List
 * @buffer: Buffer
 * @flags:  Cal
 * @width: get
 * @precision: Prec
 * @size: Si
 * Return: Num
 */
int print_stringgg(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char d;
	char *str;
	unsigned int l, m;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (l = 0; str[l]; l++)
	{
		for (m = 0; in[m]; m++)
		{
			if (in[m] == str[l])
			{
				d = out[m];
				write(1, &d, 1);
				count++;
				break;
			}
		}
		if (!in[m])
		{
			d = str[l];
			write(1, &d, 1);
			count++;
		}
	}
	return (count);
}
