#include "main.h"

void meenah_print_buffer(char meenah_buffer[], int *meenah_mb_ind);

/**
 * meenah_printf - Printf function
 * @meenah_format: format.
 * Return: Printed chars.
 */
int meenah_printf(const char *meenah_format, ...)
{
	int meenah_i, meenah_printed = 0, meenah_printed_chars = 0;
	int meenah_flags, meenah_width, meenah_precision, meenah_size,
	    meenah_mb_ind = 0;
	va_list meenah_list;
	char meenah_buffer[BUFF_SIZE];

	if (meenah_format == NULL)
		return (-1);

	va_start(meenah_list, meenah_format);

	for (meenah_i = 0; meenah_format && meenah_format[meenah_i]
			!= '\0'; meenah_i++)
	{
	if (meenah_format[meenah_i] != '%')
	{
	meenah_buffer[meenah_mb_ind++] = meenah_format[meenah_i];
	if (meenah_mb_ind == BUFF_SIZE)
	meenah_print_buffer(meenah_buffer, &meenah_mb_ind);
	meenah_printed_chars++;
	}
	else
	{
	meenah_print_buffer(meenah_buffer, &meenah_mb_ind);
	meenah_flags = get_flags(meenah_format, &meenah_i);
	meenah_width = get_width(meenah_format, &meenah_i, meenah_list);
	meenah_precision = get_precision(meenah_format, &meenah_i, meenah_list);
	meenah_size = get_size(meenah_format, &meenah_i);
	++meenah_i;
	meenah_printed = handle_print(meenah_format, &meenah_i, meenah_list,
			meenah_buffer, meenah_flags, meenah_width, meenah_precision, meenah_size);
	if (meenah_printed == -1)
	return (-1);
	meenah_printed_chars += meenah_printe;
	}
	}

meenah_print_buffer(meenah_buffer, &meenah_mb_ind);
va_end(meenah_list);
return (meenah_printed_chars);
}

/**
 * meenah_print_buffer - Prints the contents of the buffer if it exists
 * @meenah_buffer: Array of chars
 * @meenah_mb_ind: Index at which to add next char, represents the length.
 */
void meenah_print_buffer(char meenah_buffer[], int *meenah_mb_ind)
if (*meenah_mb_ind > 0)
	write(1, &meenah_buffer[0], *meenah_mb_ind);
	*meenah_mb_ind = 0;
}
