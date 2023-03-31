#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_string - Prints a string
 * @args_list: The arguments list
 * @fmt_info: The format info
 */
void printf_string(va_list *args_list, fmt_info_t *fmt_info)
{
	int i, len;
	char *str = va_arg(*args_list, char *);
	char null_str[] = "(null)";

	str = str ? str : null_str;
	len = fmt_info->is_precision_set && fmt_info->precision >= 0
		? fmt_info->precision : _strlen(str);
	if (!fmt_info->left_align)
	{
		for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
			_putchar(' ');
	}
	for (i = 0; i < len && *(str + i) != '\0'; i++)
		_putchar(*(str + i));
	if (fmt_info->left_align)
	{
		for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
			_putchar(' ');
	}
}
