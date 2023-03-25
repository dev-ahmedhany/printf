#include "main.h"

/**
 * printf_octal - Print a unsigned octal
 * @list: Number to print
 *
 * Return: Length of the number
 **/
int printf_octal(va_list list)
{
	char *p_buff;
	int len, i;

	p_buff = _itoa(va_arg(list, unsigned int), 8);

	len = _strlen(p_buff);

	for (i = 0 ; i < len ; i++)
		_putchar(p_buff[i]);

	return (len);
}
