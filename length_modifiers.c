#include "main.h"

/**
 * length_modifier - Checks if the given character is a length character
 * @c: The character to check
 *
 * Return: 1 or 0
 */
char length_modifier(char c)
{
	switch (c)
	{
	case 'h':
	case 'l':
		return (TRUE);
	default:
		return (FALSE);
	}
}
