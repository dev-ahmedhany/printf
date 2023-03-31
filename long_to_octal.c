#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * long_to_octal - Converts a long integer to its octal representation
 * @num: The number to convert
 *
 * Return: The octal representation of the number, otherwise NULL
 */
char *long_to_octal(unsigned long num)
{
	int i = 0, size = num == 0 ? 2 : 21;
	unsigned long num_c = num;
	char *str;

	str = malloc(sizeof(char) * (size));
	if (str)
	{
		mem_set(str, size, 0);
		if (num == 0)
		{
			*(str + i) = '0';
			return (str);
		}
		for (i = 0; i <= size; i++)
		{
			*(str + i) = (num_c % 8) + '0';
			num_c /= 8;
		}
		rev_string(str);
		str = trim_start(str, '0', TRUE);
		str = num == 0 ? str_cat("0", "", FALSE) : str;
	}
	return (str);
}
