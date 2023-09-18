#include "main.h"
/**
 * get_eze- Cal
 * @format: Formatted
 * @i: List
 * @list: list
 * Return: eze
 */
int get_eze(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int eze = -1;

	if (format[curr_i] != '.')
		return (eze);

	eze = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			eze *= 10;
			eze += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			eze = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (eze);
}
