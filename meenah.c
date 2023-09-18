#include "main.h"
/**
 * get_meenah - Cal
 * @format: Formatted
 * @i: List
 * @list: list
 * Return: meenah
 */
int get_meenah(const char *format, int *i, va_list list)
{
	int curr_i;
	int meenah = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			meenah *= 10;
			meenah += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			meenah = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (meenah);
}
