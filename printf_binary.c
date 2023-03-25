#include "main.h"

/**
 * printf_binary - Print a number in base 2
 * @list: Number to print in base 2
 *
 * Return: Length of the numbers in binary
 **/
int printf_binary(va_list list)
{
	char *p_buff;
	int len, i;

	p_buff = _itoa(va_arg(list, unsigned int), 2);

	len = _strlen(p_buff);

	for (i = 0 ; i < len ; i++)
		_putchar(p_buff[i]);

	return (len);
}
