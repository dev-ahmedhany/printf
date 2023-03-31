#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_n_times - Prints a character n times
 * @c: The character to print
 * @n: The number of times to print the character
 */
void print_n_times(char c, int n)
{
	int i;

	for (i = 0; i < n; i++)
		_putchar(c);
}

/**
 * set_format_error - Sets the error after reading a format specifier
 * @format: The format string
 * @pos: The current position in the format string
 * @len: The length of the format specifier minus 1
 * @last_token: The last token from the format specifier
 * @error: The format error flag
 */
void set_format_error(const char *format, int *pos, int len,
	int last_token, int *error)
{
	char next_char = format[*pos + len + 1];
	int i;

	if (last_token == 1 && next_char == '\0')
	{
		*error = -1;
	}
	else if ((last_token == 2 || last_token == 3) && next_char == '\0')
	{
		*error = -1;
		(*pos) += len - 1;
	}
	else if (last_token == 4 && next_char == '\0')
	{
		*error = -1;
	}
	else
	{
		*error = 1;
	}
	if (next_char != '\0' && last_token != 5)
	{
		_putchar('%');
		for (i = 0; i <= len; i++)
		{
			if (!length_modifier(format[*pos + i]))
				_putchar(format[*pos + i]);
		}
		(*pos) += len;
	}
}
