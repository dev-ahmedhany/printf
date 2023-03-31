#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * add_int - Adds two positive integers
 * @left_align: The first number
 * @right: The second number
 * @can_free: Specifies whether the given numbers can be freed
 *
 * Return: The sum of the two integers, otherwise NULL
 */
char *add_int(char *left_align, char *right, int can_free)
{
	int i, size, len1, len2;
	char dig1, dig2, carry, rem, *result;

	len1 = _strlen(left_align);
	len2 = _strlen(right);
	size = MAX(len1, len2) + 1;
	result = malloc(sizeof(char) * (size + 1));
	if (result)
	{
		mem_set(result, size, '0');
		carry = 0;
		i = size - 1;
		len1--;
		len2--;
		for (; i >= 0; i--)
		{
			dig1 = len1 >= 0 ? *(left_align + len1) - '0' : 0;
			dig2 = len2 >= 0 ? *(right + len2) - '0' : 0;
			rem = (dig1 + dig2 + carry) % 10;
			carry = (dig1 + dig2 + carry) / 10;
			*(result + i) = rem + '0';
			len1--;
			len2--;
		}
		*(result + size) = '\0';
		result = trim_start(result, '0', TRUE);
		if (can_free)
		{
			free(left_align);
			free(right);
		}
	}
	return (result);
}

/**
 * add_float - Adds two positive floating point numbers
 * @left_align: The first number
 * @right: The second number
 * @can_free: Specifies whether the given numbers can be freed
 *
 * Return: The sum of the two floats, otherwise NULL
 */
char *add_float(char *left_align, char *right, char can_free)
{
	int len1, len2, dec_pos1, dec_pos2, frac_len1, frac_len2, size;
	int i, rem, carry, dig1, dig2, dec_pos;
	char *sum, trim;

	for (len1 = 0; *(left_align + len1) != '\0'; len1++)
		dec_pos1 = *(left_align + len1) == '.' ? len1 : dec_pos1;
	for (len2 = 0; *(right + len2) != '\0'; len2++)
		dec_pos2 = *(right + len2) == '.' ? len2 : dec_pos2;
	frac_len1 = len1 - dec_pos1 - 1, frac_len2 = len2 - dec_pos2 - 1;
	dec_pos = frac_len1 > frac_len2 ? dec_pos1 : dec_pos2;
	size = MAX(len1, len2) + 1, sum = malloc(sizeof(char) * (size + 1));
	if (sum == NULL)
		return (NULL);
	mem_set(sum, size, '0'), carry = 0, len1--, len2--;
	for (i = size - 1; i >= 0; i--)
	{
		frac_len1 = len1 - dec_pos1 - 1, frac_len2 = len2 - dec_pos2 - 1;
		dig1 = len1 > dec_pos1
			? ((len1 - dec_pos1 - 1) >= frac_len2 ? *(left_align + len1) - '0' : 0)
			: ((len1 == dec_pos1) || (len1 < 0) ? 0 : *(left_align + len1) - '0');
		len1 -= (len1 > dec_pos1
			? ((len1 - dec_pos1 - 1) >= frac_len2 ? 1 : 0)
			: (len2 <= dec_pos2 ? 1 : 0));
		dig2 = len2 > dec_pos2
			? ((len2 - dec_pos2 - 1) >= frac_len1 ? *(right + len2) - '0' : 0)
			: ((len2 == dec_pos2) || (len2 < 0) ? 0 : *(right + len2) - '0');
		len2 -= (len2 > dec_pos2
			? ((len2 - dec_pos2 - 1) >= frac_len1 ? 1 : 0)
			: (len1 <= dec_pos1 ? 1 : 0));
		rem = (dig1 + dig2 + carry) % 10, carry = (dig1 + dig2 + carry) / 10;
		*(sum + i) = (i - 1 == dec_pos) ? '.' : rem + '0';
	}
	*(sum + size) = '\0';
	if ((can_free >> 0) & TRUE)
		free(left_align);
	if ((can_free >> 1) & TRUE)
		free(right);
	trim = (size > 1) && (sum[0] == '0');
	return (trim ? sub_str(sum, 1, 01) : sum);
}
