#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * printf_percent - Prints a percent sign (%)
 * @args_list: The arguments list
 * @fmt_info: The format info
 */
void printf_percent(va_list *args_list, fmt_info_t *fmt_info)
{
	(void)args_list;
	_putchar(fmt_info->specifier);
}
