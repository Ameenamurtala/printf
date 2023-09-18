#include "main.h"
/**
 * get_eze - Cal
 * @format: Formatted
 * @i: List
 * Return: eze
 */
int get_eze(const char *format, int *i)
{
	int curr_i = *i + 1;
	int eze = 0;

	if (format[curr_i] == 'l')
		eze = S_LONG;
	else if (format[curr_i] == 'h')
		eze = S_SHORT;

	if (eze == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (eze);
}
