#include "main.h"

int dec_to_hex(unsigned long int);

/**
 * printf_pointer - prints an hexadecimal number.
 * @list: arguments.
 * Return: counter.
 */
int printf_pointer(va_list list)
{
	char *str;
	int count = 0;
	unsigned long int p = va_arg(list, unsigned long int);
	if (!p)
		return (_puts("(nil)"));

	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
