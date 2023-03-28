#include "main.h"

/**
 * printf_hex_lower - Print a number in hexadecimal format
 * @list: Number to print
 * @f: flags.
 *
 * Return: Length of the number
 **/
int printf_hex_lower(va_list list, flags_t *f)
{
	char *p_buff;
	int len, i, count = 0;

	p_buff = _itoa(va_arg(list, unsigned int), 16);

	len = _strlen(p_buff);

	if (f->hash == 1 && p_buff[0] != '0')
		count += _puts("0x");

	for (i = 0 ; i < len ; i++)
		count += _putchar(p_buff[i]);

	return (count);
}
