#include "main.h"

/**
 * printf_binary - Print a number in base 2
 * @list: Number to print in base 2
 *
 * Return: Length of the numbers in binary
 **/
int printf_binary(va_list list)
{
	char number[33];
	int len, i;

	_itoa(va_arg(list, unsigned int), number, 2);
	len = _strlen(number);

	for (i = 0; i < len; i++)
		_putchar(number[i]);

	return (len);
}
