#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _putstring - writes the given string to the buffer
 * @str: The string to write
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstring(char *str)
{
	int i, out;

	for (i = 0; str && *(str + i) != 0; i++)
		out = _putchar(*(str + i));
	return (out);
}

/**
 * _putchar - writes the character c to the buffer
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write_to_buffer(c, 0));
}

/**
 * write_to_buffer - Writes a char to the buffer based on an action code
 * @c: The character to write
 * @action: The action to perform (
 * -1-> reset the static variables
 * 0-> write char to buffer
 * 1-> don't write character to buffer but empty buffer onto stdout
 * -2-> the number of characters written to stdout)
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_to_buffer(char c, char action)
{
	static int i;
	static int chars_count;
	static char buffer[1024];
	static char out;

	if (i < 1024 && action == 0)
	{
		out = chars_count < 1 ? 1 : out;
		buffer[i] = c;
		i++;
		chars_count++;
	}
	if (i >= 1024 || action == 1)
	{
		out = write(1, buffer, i);
		fflush(stdout);
		i = 0;
		mem_set(buffer, 1024, 0);
	}
	if (action == -1)
	{
		i = 0;
		chars_count = 0;
		mem_set(buffer, 1024, 0);
	}
	if (action == -2)
	{
		return (chars_count);
	}
	return (out);
}

/**
 * _putnum - Prints a number to the buffer
 * @zeros_count: The number of zeros to print
 * @num: The number
 * @str: The string representation of the number
 */
void _putnum(int zeros_count, long num, char *str)
{
	int i;

	for (i = 0; i < zeros_count; i++)
		_putchar('0');
	for (i = num < 0 ? 1 : 0; *(str + i) != '\0'; i++)
		_putchar(*(str + i));
}

/**
 * _putnchrs - Prints multiple characters
 * @n: The number of characters to print
 */
void _putnchrs(int n, ...)
{
	int i;
	va_list args;

	if (n <= 0)
		return;
	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		_putchar(va_arg(args, int));
	}
	va_end(args);
}
