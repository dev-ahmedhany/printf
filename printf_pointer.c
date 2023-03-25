#include "main.h"

int dec_to_hex(unsigned long int);

/**
 * printf_pointer - prints an hexadecimal number.
 * @list: arguments.
 * Return: counter.
 */
int printf_pointer(va_list list)
{
	void *p;
	char *s = "(nil)";
	long int a;
	int b;
	int i;

	p = va_arg(list, void*);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	a = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	b = dec_to_hex(a);
	return (b + 2);
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
