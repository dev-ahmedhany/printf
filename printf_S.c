#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_S - Prints a string and the hex code for
 * \ non-printable characters
 * @args_list: The arguments list
 * @fmt_info: The format info
 *
 * Return: The number of characters written
 */
void printf_S(va_list *args_list, fmt_info_t *fmt_info)
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
		for (i = 0; *(str + i) != '\0'; i++)
		{
			if (*(str + i) < 32 || *(str + i) >= 127)
			{
				_putchar('\\');
				_putchar('x');
				_putchar(TOUPPER(hex_digit(*(str + i) / 16)));
				_putchar(TOUPPER(hex_digit(*(str + i) % 16)));
			}
			else
			{
				_putchar(*(str + i));
			}
		}
		if (fmt_info->left_align)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(fmt_info->padding);
		}
	}
	else
	{
		_putstring("(null)");
	}
}

/**
 * hex_digit - converts a decimal less than 16 to its hexadecimal form
 * @c: The decimal
 *
 * Return: The hexadecimal digit, otherwise '\0'
 */
char hex_digit(char c)
{
	char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'
	};

	return (c >= 0 && c <= 15 ? *(digits + c) : '\0');
}
