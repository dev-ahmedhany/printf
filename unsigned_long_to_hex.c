#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * unsigned_long_to_hex - Converts an unsigned long
 * to its string representation
 * @num: The unsigned long number
 * @upper: Specifies whether the hexadecimals should be in uppercase
 *
 * Return: The string representation of the number in hexadecimal notation
 */
char *unsigned_long_to_hex(unsigned long num, char upper)
{
	int i;
	char *str;
	char size = 20;
	unsigned long tmp = num;

	str = malloc(sizeof(char) * (size));
	if (str)
	{
		mem_set(str, size, 0);
		for (i = 0; i <= size && tmp > 0; i++)
		{
			*(str + i) = (tmp % 16) < 10 ? (tmp % 16) + '0'
				: (tmp % 16) - 10 + 'a' + (upper ? -6 - 26 : 0);
			tmp /= 16;
		}
		rev_string(str);
		str = trim_start(str, '0', TRUE);
		str = num == 0 ? str_cat("0", "", FALSE) : str;
	}
	return (str);
}
