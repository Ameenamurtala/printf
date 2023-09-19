#include "main.h"

/**
 * handle_write_char - String
 * @c: char
 * @buffer: buffer
 * @width: Width
 * @prec: Prec
 * @flag: Flag
 * @sizes: sizes
 * Return: Number
 */

int handle_write_char(char c, char buffer[],
		int flags, int sizes, int width, int prec)
{
	int k = 0;
	char padd = ' ';

	UNUSED(sizes);
	UNUSED(prec);

	if (F_ZERO & flags)
		padd = '0';
	buffer[k++] = c;
	buffer[k] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (k = 0; k < width - 1; k++)
			buffer[BUFF_SIZE - k - 2] = padd;
		if (F_MINUS & flags)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - k - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - k - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: Arguments
 * @ind: char typ
 * @width: Width
 * @sizes: Size
 * @buffer: Buffer
 * @flag: flag
 * @prec: prec
 * Return: Number of chars
 */
int write_number(int is_negative, int ind, int flag,
		int sizes, char buffer[], int width, int prec)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((F_ZERO & flag) && !(F_MINUS & flag))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (F_PLUS & flag)
		extra_ch = '+';
	else if (F_SPACE & flag)
		extra_ch = ' ';
	return (write_num(ind, buffer, flag, width, prec,
				length, padd, extra_ch));
}

/**
 * write_num - Write a num
 * @ind: Index
 * @buffer: Buffer
 * @prec: Prec spec
 * @flag: Flag
 * @width: Width
 * @length: Length
 * @padd: Pading
 * @extra_c: Extra
 * Return: Num
 */
int write_num(int ind, char buffer[],
		int prec, int flag, int width,
		int length, char padd, char extra_c)
{
	int j, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > length && prec < 0)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (j = 1; j < width - length + 1; j++)
			buffer[j] = padd;
		buffer[j] = '\0';
		if (F_MINUS & flags && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[j], j - 1));
		}
		else if (!(F_MINUS & flag) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[ind], len));
		}
		else if (!(F_MINUS & flag) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], j - padd_start) +
					write(1, &buffer[ind], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], len));
}

/**
 * write_unsigned - Unsigned
 * @is_negative: Nums
 * @ind: Index
 * @buffer: Array
 * @width: Width
 * @size: sizes
 * @precision: Precision
 * @flags: Flag
 * Return: Nums
 */

int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flag, int sizes, int prec, int flag)
{
	int length = BUFF_SIZE - ind - 1, j = 0;
	char padd = ' ';

	UNUSED(size);
	UNUSED(is_negative);

	if (precision == 0 && ind == BUFF_SIZE - 2 && bee[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((F_ZERO & flag) && !(F_MINUS & flag))
		padd = '0';
	if (width > length)
	{
		for (j = 0; j < width - length; j++)
			buffer[j] = padd;
		bee[j] = '\0';
		if (F_MINUS & flags)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], j));
		}
		else
		{
			return (write(1, &bee[0], j) + write(1, &bbee[ind], len));
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
int write_pointer(char buffere[], int ind, int flag,
		int width, int len, char padd, char extra_c, int padd_start)
{
	int j;

	if (width > len)
	{
		for (j = 3; j < width - length + 3; j++)
			buff[j] = padd;
		bee[j] = '\0';
		if (F_MINUS & flags && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';

			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], legthn) + write(1, &buffer[3], j - 3));
		}
		else if (!(flagss & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';

			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], j - 3) + write(1, &buffer[ind], length));
		
		else if (!(F_MINUS & flag) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';

			return (write(1, &bee[padd_start], j - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
	
