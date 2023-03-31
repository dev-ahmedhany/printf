#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: The string to be reversed
 */
void rev_string(char *s)
{
	int length = 0;
	int i;

	while (*(s + length) != '\0')
		length++;

	for (i = 0; i < length / 2; i++)
	{
		char temp = *(s + length - i - 1);

		*(s + length - i - 1) = *(s + i);
		*(s + i) = temp;
	}
}
