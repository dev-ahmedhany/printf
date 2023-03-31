#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_char - Prints a character
 * @args_list: The arguments list
 * @fmt_info: The format info
 */
void printf_char(va_list *args_list, fmt_info_t  *fmt_info)
{
	int i, len = 1;
	char str = va_arg(*args_list, int);

	if (!fmt_info->left_align)
	{
		for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
			_putchar(' ');
	}
	_putchar(str);
	if (fmt_info->left_align)
	{
		for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
			_putchar(' ');
	}
}
