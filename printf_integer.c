#include "main.h"

/**
 * printf_integer - Print a number in base 10
 * @list: Number to print in base 10
 *
 * Return: Length of th numbers in decimal
 **/
int printf_integer(va_list list)
{
	char *p_buff;
	int len, i;

	p_buff = _itoa(va_arg(list, int), 10);

	len = _strlen(p_buff);

	for (i = 0 ; i < len ; i++)
		_putchar(p_buff[i]);

	return (len);
}
