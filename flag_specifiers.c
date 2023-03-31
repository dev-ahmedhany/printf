#include "main.h"

/**
 * flag_characters - Checks if the given character is a flag character
 * @c: The character to check
 *
 * Return: 1 or 0
 */
char flag_characters(char c)
{
	switch (c)
	{
	case '-':
	case '+':
	case '\'':
	case ' ':
	case '#':
	case '0':
		return (TRUE);
	default:
		return (FALSE);
	}
}
