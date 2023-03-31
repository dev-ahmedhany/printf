#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * str_to_int - Converts a string to an int
 * @num: The string to convert
 *
 * Return: The converted number
 */
int str_to_int(char *num)
{
	int i = 1, len, exp = 1;
	int res = 0;

	len = _strlen(num);
	for (i = len - 1; i >= 0; i--)
	{
		if (*(num + i) == '-')
			res *= -1;
		else if (is_digit(*(num + i)))
		{
			res += (*(num + i) - '0') * exp;
			exp *= 10;
		}
	}
	return (res);
}

/**
 * bin_to_int - Converts an array of bits to an int
 * @bin_str: The array of bits
 *
 * Return: The decimal equivalent of the array of bits
 */
int bin_to_int(char *bin_str)
{
	int len = _strlen(bin_str);
	int i;
	int exp = 1;
	int result = 0;

	for (i = len - 1; i >= 0 && *(bin_str + i) != '\0'; i--)
	{
		if (*(bin_str + i) == '0' || *(bin_str + i) == '1')
		{
			result += (*(bin_str + i) - '0') * exp;
			exp *= 2;
		}
	}
	return (result);
}
