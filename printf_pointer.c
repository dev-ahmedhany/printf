#include "main.h"

/**
 * printf_pointer - prints an hexadecimal number.
 * @list: arguments.
 * @f: flags.
 *
 * Return: counter.
 */
int printf_pointer(va_list list, flags_t *f)
{
	char *str;
	int count = 0;
	unsigned long int p = va_arg(list, unsigned long int);

	(void)f;

	if (!p)
		return (_puts("(nil)"));

	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
