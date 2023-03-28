#include "main.h"

/**
 * printf_char - print char.
 * @list: va_list.
 *
 * Return: 1
 */
int printf_char(va_list list, flags_t *f)
{
	int aux;

	(void)f;

	aux = va_arg(list, int);

	_putchar(aux);

	return (1);
}
