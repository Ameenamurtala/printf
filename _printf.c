#include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf
 * @get_precision: prec
 * @format: fmt
 * Return: char
 */
int _printf(const char *format, ...)
{
	int j, pointer = 0, printed_chars = 0;
	int flag, width, size, buff_ind, precision = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_sizes(format, &j);
			++j;
			pointer = handle_print(format, &j, list, buffer,
				flag, size, width, precision);
			if (pointer == -1)
				return (-1);
			printed_chars += pointer;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
/**
 * print_buffer - Print
 * @buffer: Array
 * @buff_ind: Index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
