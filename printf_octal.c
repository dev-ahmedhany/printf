#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_octal - Prints the octadecimal format of a signed int argument
 * @args_list: The arguments list
 * @fmt_info: The format info
 *
 * Return: The number of characters written
 */
void printf_octal(va_list *args_list, fmt_info_t *fmt_info)
{
	int i = 0, zeros_count = 0, num_len = 0, len = 0, max_w, max_p;
	unsigned long num;
	char *str;

	if (fmt_info->is_long)
		num = va_arg(*args_list, unsigned long);
	else if (fmt_info->is_short)
		num = (va_arg(*args_list, unsigned long) << 2 * 8) >> 2 * 8;
	else
		num = va_arg(*args_list, unsigned int);
	str = long_to_octal(num);
	if (str)
	{
		if (fmt_info->is_precision_set && !fmt_info->precision && !num)
		{
			print_n_times(' ', fmt_info->width);
		}
		else
		{
			num_len = CMP(_strlen(str), 1);
			max_w = MAX(fmt_info->width, num_len);
			max_p = MAX(fmt_info->precision, num_len);
			zeros_count = (max_p - num_len) * !fmt_info->left_align;
			len = max_w - (NEG(zeros_count) + num_len);
			for (i = 0; !fmt_info->left_align && i < len; i++)
				_putchar(fmt_info->padding);
			if (fmt_info->hash && zeros_count == 0 && num)
				_putchar('0');
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
