#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_rot13 - Prints the rot13'ed string
 * @args_list: The arguments list
 * @fmt_info: The format info
 *
 * Return: The number of characters written
 */
void printf_rot13(va_list *args_list, fmt_info_t *fmt_info)
{
	int i, len, is_low_1, is_low_2, is_upper, is_lower;
	char *str = va_arg(*args_list, char *);

	if (str)
	{
		len = _strlen(str);
		if (!fmt_info->left_align)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(fmt_info->padding);
		}
		for (i = 0; str && *(str + i) != '\0'; i++)
		{
			is_low_1 = *(str + i) >= 'a' && *(str + i) <= 'm';
			is_low_2 = *(str + i) >= 'A' && *(str + i) <= 'M';
			is_upper = *(str + i) >= 'A' && *(str + i) <= 'Z';
			is_lower = *(str + i) >= 'a' && *(str + i) <= 'z';

			if (is_lower || is_upper)
				_putchar(((is_low_1 + is_low_2) * (*(str + i) + 13))
					+ ((1 - is_low_1 - is_low_2) * (*(str + i) - 13)));
			else
				_putchar(*(str + i));
		}
		if (fmt_info->left_align)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(fmt_info->padding);
		}
	}
}
