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


/**
 * dec_to_hex - prints an hexgecimal number.
 * @num: arguments.
 * Return: counter.
 */
int dec_to_hex(unsigned long int num)
{
	long int i;
	long int *array;
	long int counter = 0;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}
