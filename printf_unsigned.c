#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_unsigned - Prints an unsigned integer
 * @args_list: The arguments list
 * @fmt_info: The format info
 */
void printf_unsigned(va_list *args_list, fmt_info_t *fmt_info)
{
	int i, len = 0, zeros_count = 0, num_len;
	unsigned long num, max_w, max_p;
	char *str;

	if (fmt_info->is_long)
		num = va_arg(*args_list, unsigned long);
	else if (fmt_info->is_short)
		num = (va_arg(*args_list, unsigned int) << 2 * 8) >> 2 * 8;
	else
		num = va_arg(*args_list, unsigned int);
	str = unsigned_long_to_str(num);
	if (str)
	{
		if (fmt_info->is_precision_set && !fmt_info->precision && !num)
		{
			print_n_times(' ', fmt_info->width);
		}
		else
		{
			num_len = _strlen(str);
			max_w = MAX(fmt_info->width, num_len);
			max_p = MAX(fmt_info->precision, num_len);
			zeros_count = (max_p - num_len) * !fmt_info->left_align;
			len = max_w - (NEG(zeros_count) + num_len);
			for (i = 0; !fmt_info->left_align && i < len; i++)
				_putchar(fmt_info->padding);
			for (i = 0; i < zeros_count; i++)
				_putchar('0');
			for (i = 0; *(str + i) != '\0'; i++)
				_putchar(*(str + i));
			for (i = 0; fmt_info->left_align && i < len; i++)
				_putchar(' ');
		}
		free(str);
	}
}
