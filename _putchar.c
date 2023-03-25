#include "main.h"

/**
 * _putchar uses a local buffer of 1024 to call write
 * as little as possible
 * @c: The character to print
 *
 * Return: On success 1.
 * On error -1.
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}
