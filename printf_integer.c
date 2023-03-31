#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_integer - Prints a signed integer
 * @args_list: The arguments list
 * @fmt_info: The format info
 *
 * Return: The number of characters written
 */
void printf_integer(va_list *args_list, fmt_info_t *fmt_info)
{
	int i, len = 0, zeros_count = 0, num_len;
	long num;
	char *str, inv_plus;

	if (fmt_info->is_long)
		num = va_arg(*args_list, long);
	else if (fmt_info->is_short)
		num = (short)va_arg(*args_list, long);
	else
		num = va_arg(*args_list, int);
	str = long_to_str(num);
	if (str)
	{
		inv_plus = num >= 0 && (fmt_info->plus_sign || fmt_info->space) ? 1 : 0;
		if (fmt_info->is_precision_set && !fmt_info->precision && !num)
		{
			print_n_times(' ', fmt_info->width);
		}
		else
		{
			num_len = _strlen(str) + (inv_plus ? 1 : 0);
			if (fmt_info->is_precision_set)
				zeros_count = MAX(fmt_info->precision + (inv_plus || num < 0 ? 1 : 0),
					num_len) - num_len;
			else
				zeros_count = fmt_info->padding == '0' ? MAX(fmt_info->width,
					num_len) - num_len : 0;
			if (fmt_info->is_width_set)
				len = (MAX(fmt_info->width, num_len) - num_len) - zeros_count;
			for (i = 0; !fmt_info->left_align && i < len; i++)
				_putchar(' ');
			if (num < 0 || inv_plus)
				_putchar(num < 0 ? '-'
					: (fmt_info->space && !fmt_info->plus_sign ? ' ' : '+'));
			_putnum(zeros_count, num, str);
			for (i = 0; fmt_info->left_align && i < len; i++)
				_putchar(' ');
		}
		free(str);
	}
}
