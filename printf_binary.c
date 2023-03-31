#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_binary - Prints the binary format of an unsigned int argument
 * @args_list: The arguments list
 * @fmt_info: The format info
 */
void printf_binary(va_list *args_list, fmt_info_t  *fmt_info)
{
	int i, size = 32, len = 0;
	unsigned int num = va_arg(*args_list, unsigned int), tmp;
	char *str;

	str = malloc(sizeof(char) * (size + 1));
	if (str)
	{
		mem_set(str, size, '\0');
		tmp = num;
		for (i = 0; i < size && tmp > 0; i++, len++)
		{
			*(str + i) = (tmp % 2) + '0';
			tmp /= 2;
		}
		if (!fmt_info->left_align)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(fmt_info->padding);
		}
		for (i = size - 1; i >= 0; i--)
		{
			if (*(str + i) != '\0')
				_putchar(*(str + i));
		}
		if (num == 0)
			_putchar('0');
		if (fmt_info->left_align)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(' ');
		}
	}
}
