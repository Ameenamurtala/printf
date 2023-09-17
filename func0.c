#include "main.h"

int print_char(va_list meenah, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size)
{
	char c = va_arg(meenah, int);
	return (handle_write_char(c, meenah_buffer,
			meenah_flags, meenah_width,
			meenah_precision, meenah_size));
}

int print_string(va_list meenah, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size)
{
	int meenah_length = 0, i;
	char *meenah_str = va_arg(meenah, char *);

	UNUSED(meenah_buffer);
	UNUSED(meenah_size);
	UNUSED(meenah_precision);
	UNUSED(meenah_width);
	UNUSED(meenah_flags);

	if (meenah_str == NULL)
	{
		meenah_str = "(null)
			if (meenah_precision >= 6)
				meenah_str = "      ";
	}

	for (; meenah_str[meenah_length] != '\0'; meenah_length++)
		if (meenah_precision >= 0
				&& meenah_precision < meenah_length)
			meenah_length = meenah_precision;
	if (meenah_width > meenah_length)
	{
		if (meenah_flags & F_MINUS)
		{
			write(1, &meenah_str[0], meenah_length)
				((i = meenah_width - meenah_length; i > 0; i--)
				 write(1, " ", 1);
				 return (meenah_width);
				 }
				 else
				 {
				 for (i = meenah_width - meenah_length; i > 0;
						 write(1, " ", 1);
						 write(1, &meenah_str[0], meenah_length);
						 return (meenah_width);
						 }
						 }
						 return (write(1, meenah_str, meenah_length));
}

int print_percent(va_list meenah, char meenah_buffer[],int meenah_flags,
	int meenah_width, int meenah_precision, int meenah_size)
{
UNUSED(meenah);
UNUSED(meenah_buffer);
UNUSED(meenah_flags);
UNUSED(meenah_width);
UNUSED(meenah_precision);
UNUSED(meenah_size);
return (write(1, "%%", 1));
}

int print_int(va_list meenah, char meenah_buffer[],int meenah_flags,
		int meenah_width, int meenah_precision, int meenah_size)
{
	int meenah_i = BUFF_SIZE - 2;
	int meenah_is_negative = 0;
	long int meenah_n = va_arg(meenah, long int);
	unsigned long int meenah_num;
	
	meenah_n = convert_size_number(meenah_n, meenah_size);
	
	if (meenah_n == 0)
		meenah_buffer[meenah_i--] = '0';
	meenah_buffer[BUFF_SIZE - 1] = '\0';
	meenah_num = (unsigned long int)meenah_n;
	if (meenah_n < 0)
	{
		meenah_num = (unsigned long int)((-1) * meenah_n);
		meenah_is_negative = 1;
	}
	while (meenah_num > 0)
	{
		meenah_buffer[meenah_i--] = (meenah_num % 10) + '0';
		meenah_num /= 10;
	}
	meenah_i++;
	return (write_number(meenah_is_negative, meenah_i,
				meenah_buffer, meenah_flags, meenah_width,
				meenah_precision, meenah_size));
}

int print_binary(va_list meenah, char meenah_buffer[],
		int meenah_flags, int meenah_width,
		int meenah_precision, int meenah_size)
{
	unsigned int meenah_n, meenah_m, meenah_i, meenah_sum;
	unsigned int meenah_a[32];
	int meenah_count;

	UNUSED(meenah_buffer);
	UNUSED(meenah_flags);
	UNUSED(meenah_width);
	UNUSED(meenah_precision);
	UNUSED(meenah_size);

	meenah_n = va_arg(meenah, unsigned int);
	meenah_m = 2147483648;
	meenah_a[0] = meenah_n / meenah_m;

	for (meenah_i = 1; meenah_i < 32; meenah_i++)
	{
		meenah_m /= 2;
		meenah_a[meenah_i] = (meenah_n / meenah_m) % 2;
	}
	for (meenah_i = 0, meenah_sum = 0,
			meenah_count = 0; meenah_i < 32; meenah_i++)
	{
		meenah_sum += meenah_a[meenah_i];
		if (meenah_sum || meenah_i == 31)
		{
			char meenah_z = '0' + meenah_a[meenah_i];
			write(1, &meenah_z, 1);
			meenah_count++;
		}
	}
	return (meenah_count);
