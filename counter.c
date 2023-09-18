#include "main.h"
/**
 * get_counter - counter
 * @format: String
 * @i: para
 * Return: counter
 */
int get_counter(const char *format, int *i)
{
	int k, curr_j;
	int counter = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j = *i + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[curr_j] == FLAGS_CH[k])
			{
				counter |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*i = curr_j - 1;

	return (counter);
}
