#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * two_pow_x - Computes 2 raised to the given power
 * @n: The power
 *
 * Return: The value of 2 index n, otherwise NULL
 */
char *two_pow_x(short n)
{
	char *result, *pow_b5;
	short i;

	result = malloc(sizeof(char) * (2));
	if (result)
	{
		*(result + 0) = '1';
		*(result + 1) = '\0';
		if (n > 0)
		{
			for (i = 0; i < n; i++)
			{
				pow_b5 = malloc(sizeof(char) * (2));
				if (pow_b5)
				{
					*(pow_b5 + 0) = '2';
					*(pow_b5 + 1) = '\0';
					result = mul_int(pow_b5, result, TRUE);
				}
			}
		}
		else if (n < 0)
		{
			pow_b5 = five_pow_n(n * -1);
			result = div_by_pow_10(pow_b5, n * -1, TRUE);
		}
	}
	return (result);
}

/**
 * five_pow_n - Computes 5 raised to the given positive power
 * @n: The power
 *
 * Return: The value of 5 index n, otherwise NULL
 */
char *five_pow_n(unsigned short n)
{
	char *result, *base;
	unsigned short i;

	result = malloc(sizeof(char) * (2));
	if (result)
	{
		result[0] = '1';
		result[1] = '\0';
		for (i = 0; i < n; i++)
		{
			base = malloc(sizeof(char) * (2));
			if (base)
			{
				base[0] = '5';
				base[1] = '\0';
				result = mul_int(base, result, TRUE);
			}
		}
	}
	return (result);
}

/**
 * two_pow_n - Computes 2 raised to the given positive power
 * @n: The positive index
 *
 * Return: The value of 2 exponent n
 */
unsigned int two_pow_n(unsigned int n)
{
	unsigned int result = 1;
	unsigned int i;

	for (i = 0; i < n; i++)
		result *= 2;
	return (result);
}
