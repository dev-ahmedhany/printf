#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * placeHolder - Writes data formatted against some parameters
 * @args_list: The arguments list
 * @fmt_info: The format info parameters that were read
 */
void placeHolder(va_list *args_list, fmt_info_t  *fmt_info)
{
	int i;
	spec_printer_t spec_printers[] = {
		{'%', printf_percent},
		{'p', printf_pointer},
		{'c', printf_char},
		{'s', printf_string},
		{'d', printf_integer},
		{'i', printf_integer},
		{'X', printf_hex},
		{'x', printf_hex},
		{'o', printf_octal},
		{'u', printf_unsigned},
		{'b', printf_binary},
		{'R', printf_rot13},
		{'r', printf_rev_str},
		{'S', printf_S},
		{'F', printf_float},
		{'f', printf_float},
	};

	for (i = 0; i < 23 && spec_printers[i].specifier != '\0'; i++)
	{
		if (fmt_info->specifier == spec_printers[i].specifier)
		{
			spec_printers[i].print_arg(args_list, fmt_info);
			break;
		}
	}
}
