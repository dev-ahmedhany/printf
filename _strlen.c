#include "main.h"

/**
 * _strlen - Computes the length of a string
 * @str: The source string
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while (*(str + len) != '\0')
		len++;
	return (len);
}
