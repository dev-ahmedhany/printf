#include "main.h"
/**
 * printf_string - print a string.
 * @list: argument.
 * @f: flags.
 * Return: the length of the string.
 */

int printf_string(va_list list, flags_t *f)
{
	char *s;
	int i, len;

	(void)f;

	s = va_arg(list, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
	}
	else
		len = _strlen(s);

	for (i = 0; i < len; i++)
		_putchar(s[i]);

	return (len);
}
