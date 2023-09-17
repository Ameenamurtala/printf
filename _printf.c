#include "main.h"

void print_buffer(char buffer[], int *mb_ind);

/**
 * _printf - Printf function
 * @format: format
 * Return: Printed chars
 */
int _printf(const char *format, ...)
{
	int k, meenah = 0, printed_chars = 0;
	int flags, width, mb_ind, precision, width = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
	if (format[k] != '%')
	{
		buffer[mb_ind++] = format[k];
		if (mb_ind == BUFF_SIZE)
			print_buffer(buffer, &mb_ind);
		printed_chars++;
	}
	else
	{
		print_buffer(buffer, mb_ind);
		flags = get_flags(format, &mb_ind);
		width = get_width(format, &k, list);
		precision = get_precision(format, &k, list);
		size = get_size(format, &k);
		k++;
		meenah = handle_print(format, &k, list,
				buffer, flags, width, precision, size);

		if (meenah == -1)
			return (-1);
		prited_chars += meenah;
	}
	}

	print_buffer(buffer, &mb_ind);
	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer - content of buffer
 * @mb_ind: index to add chaar
 * @buffer: Arrays
 */
void print_buffer(char buffer[], int *mb_ind)
if (*mb_ind > 0)
	write(1, &buffer[0], *mb_ind);
	*mb_ind = 0;
}
