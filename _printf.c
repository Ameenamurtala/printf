#include "main.h"
void print_bee(char bee[], int *buff_ind);

/**
 * _printf - Printf
 * @format: formt
 * Return: Printed
 */
int _printf(const char *format, ...)
{
	int j, pointer = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char bee[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			bee[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_bee(bee, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_bee(bee, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			pointer = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (pointer == -1)
				return (-1);
			printed_chars += pointer;
		}
	}

	print_bee(bee, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_bee - Print
 * @bee: Array
 * @buff_ind: Index
 */
void print_bee(char bee[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &bee[0], *buff_ind);

	*buff_ind = 0;
}
