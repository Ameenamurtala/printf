#include "main.h"

/**
 * handle_write_char - String
 * @c: char
 * @bee: Bee
 * @width: Width
 * @precision: Precision
 * @flags: Flags
 * @size: size
 * Return: Number
 */

int handle_write_char(char c, char bee[],
		int width, int precision, int flags, int size)
{
	int k = 0;
	char padd = ' ';

	UNUSED(size);
	UNUSED(precision);

	if (F_ZERO & flags)
		padd = '0';
	bee[k++] = c;
	bee[k] = '\0';
	if (width > 1)
	{
		bee[BUFF_SIZE - 1] = '\0';
		for (k = 0; k < width - 1; k++)
			bee[BUFF_SIZE - k - 2] = padd;
		if (F_MINUS & flags)
			return (write(1, &bee[0], 1) +
					write(1, &bee[BUFF_SIZE - k - 1], width - 1));
		else
			return (write(1, &bee[BUFF_SIZE - k - 1], width - 1) +
					write(1, &bee[0], 1));
	}
	return (write(1, &bee[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: Arguments
 * @ind: char typ
 * @width: Width
 * @size: Size
 * @bee: Bee
 * @flags: flags
 * @precision: precision
 * Return: Number of chars
 */
int write_number(int is_negative, int ind, int width,
		int size, char bee[], int flags, int precision)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((F_ZERO & flags) && !(F_MINUS & flags))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (F_PLUS & flags)
		extra_ch = '+';
	else if (F_SPACE & flags)
		extra_ch = ' ';
	return (write_num(ind, bee, flags, width, precision,
				length, padd, extra_ch));
}

/**
 * write_num - Write a num
 * @ind: Index
 * @bee: Bee
 * @prec: Prec spec
 * @flags: Flags
 * @width: Width
 * @len: Len
 * @padd: Pading
 * @extra_c: Extra
 * Return: Num
 */
int write_num(int ind, char bee[],
		int prec, int flags, int width,
		int len, char padd, char extra_c)
{
	int j, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && bee[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && bee[ind] == '0')
		bee[ind] = padd = ' ';
	if (prec > len && prec < 0)
		padd = ' ';
	while (prec > len)
		bee[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (j = 1; j < width - len + 1; j++)
			bee[j] = padd;
		bee[j] = '\0';
		if (F_MINUS & flags && padd == ' ')
		{
			if (extra_c)
				bee[--ind] = extra_c;
			return (write(1, &bee[ind], len) + write(1, &bee[j], j - 1));
		}
		else if (!(F_MINUS & flags) && padd == ' ')
		{
			if (extra_c)
				bee[--ind] = extra_c;
			return (write(1, &bee[1], j - 1) + write(1, &bee[ind], len));
		}
		else if (!(F_MINUS & flags) && padd == '0')
		{
			if (extra_c)
				bee[--padd_start] = extra_c;
			return (write(1, &bee[padd_start], j - padd_start) +
					write(1, &bee[ind], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		bee[--ind] = extra_c;
	return (write(1, &bee[ind], len));
}

/**
 * write_unsigned - Unsgned
 * @is_negative: Nums
 * @ind: Index
 * @bee: Array
 * @width: Width
 * @size: Size
 * @precision: Precision
 * @flags: Flags
 * Return: Nums
 */

int write_unsgnd(int is_negative, int ind,
		char bee[],
		int width, int size, int precision, int flags)
{
	int len = BUFF_SIZE - ind - 1, j = 0;
	char padd = ' ';

	UNUSED(size);
	UNUSED(is_negative);

	if (precision == 0 && ind == BUFF_SIZE - 2 && bee[ind] == '0')
		return (0);
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
	{
		bee[--ind] = '0';
		len++;
	}
	if ((F_ZERO & flags) && !(F_MINUS & flags))
		padd = '0';
	if (width > len)
	{
		for (j = 0; j < width - len; j++)
			bee[j] = padd;
		bee[j] = '\0';
		if (F_MINUS & flags)
		{
			return (write(1, &bee[ind], len) + write(1, &bee[0], j));
		}
		else
		{
			return (write(1, &bee[0], j) + write(1, &bee[ind], len));
		}
	}
	return (write(1, &bee[ind], len));
}

/**
 * write_pointer - address
 * @bee: Arrays
 * @ind: Index
 * @flags: Flags
 * @width: Width
 * @len: Len
 * @padd: Char
 * @extra_c: Char
 * @padd_start: Index
 * Return: Num of written chars
 */
int write_pointer(char bee[], int ind, int flags,
		int width, int len, char padd, char extra_c, int padd_start)
{
	int j;

	if (width > len)
	{
		for (j = 3; j < width - len + 3; j++)
			bee[j] = padd;
		bee[j] = '\0';
		if (F_MINUS & flags && padd == ' ')
		{
			bee[--ind] = 'x';
			bee[--ind] = '0';

			if (extra_c)
				bee[--ind] = extra_c;
			return (write(1, &bee[ind], len) + write(1, &bee[3], j - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			bee[--ind] = 'x';
			bee[--ind] = '0';

			if (extra_c)
				bee[--ind] = extra_c;
			return (write(1, &bee[3], j - 3) + write(1, &bee[ind], len));
		}
		else if (!(F_MINUS & flags) && padd == '0')
		{
			if (extra_c)
				bee[--padd_start] = extra_c;
			bee[1] = '0';
			bee[2] = 'x';

			return (write(1, &bee[padd_start], j - padd_start) +
					write(1, &bee[ind], len - (1 - padd_start) - 2));
		}
	}
	bee[--ind] = 'x';
	bee[--ind] = '0';
	if (extra_c)
		bee[--ind] = extra_c;
	return (write(1, &bee[ind], BUFF_SIZE - ind - 1));
}
