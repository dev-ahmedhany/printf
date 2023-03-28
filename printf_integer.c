#include "main.h"

/**
 * printf_integer - Print a number in base 10
 * @list: Number to print in base 10
 *
 * Return: Length of th numbers in decimal
 **/
int printf_integer(va_list list, flags_t *f)
{
	int n = va_arg(list, int);
	char *p_buff = _itoa(n, 10);
	int len = _strlen(p_buff), i;
	int res = len;

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		res += _putchar('+');

	for (i = 0 ; i < len ; i++)
		_putchar(p_buff[i]);

	return (res);
}
