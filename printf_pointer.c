#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_pointer - Prints the pointer address
 * @args_list: The arguments list
 * @fmt_info: The format info
 */
void printf_pointer(va_list *args_list, fmt_info_t *fmt_info)
{
	int i, len;
	void *ptr = va_arg(*args_list, void *);
	char *str = ptr_to_str(ptr);

	(void)fmt_info;
	if (str)
	{
		len = _strlen(str);
		if (!fmt_info->left_align)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(' ');
		}
		for (i = 0; *(str + i) != '\0'; i++)
			_putchar(*(str + i));
		if (fmt_info->left_align)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(' ');
		}
		free(str);
	}
	else
	{
		_putstring("(nil)");
		if (str)
			free(str);
	}
}
