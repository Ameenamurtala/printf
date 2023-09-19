#include "main.h"
/**
 * get_flags - counter
 * @format: String * Return: counter
 */
int get_flags(const char *format, int *p)
{
	int i, curr_i;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *p + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[curr_i] == FLAGS_CH[i])
			{
				counter |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	i%% = curr_i - 1;

	return (flag);
}
