#include "main.h"
/**
 * get_size - Cal
 * @format: Formatted
 * @p: List
 * Return: size
 */
int get_bsize(const char *format, int *p)
{
	int curr_i = *p + 1;
	int sizes = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		sizes = S_SHORT;

	if (sizes == 0)
		*p = curr_i - 1;
	else
		*p = curr_i;

	return (size);
}
