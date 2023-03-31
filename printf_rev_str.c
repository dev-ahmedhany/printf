#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_rev_str - Prints the reversed string
 * @args_list: The arguments list
 * @fmt_info: The format info
 *
 * Return: The number of characters written
 */
void printf_rev_str(va_list *args_list, fmt_info_t *fmt_info)
{
	int i, len;
	char *str = va_arg(*args_list, char *);

	if (str)
	{
		len = _strlen(str);
		if (!fmt_info->left_align)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(fmt_info->padding);
		}
		for (i = len - 1; i >= 0; i--)
		{
			_putchar(*(str + i));
		}
		if (fmt_info->left_align)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(fmt_info->padding);
		}
	}
}
