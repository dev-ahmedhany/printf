#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * div_by_pow_10 - Divides a number by a power of 10
 * @num: The number to divide
 * @n: The power of 10
 * @can_free: Specifies whether the given number can be freed
 *
 * Return: The quotient of the number and the power of 10, otherwise NULL
 */
char *div_by_pow_10(char *num, unsigned short n, char can_free)
{
	char *result;
	int i, j, dec_pos, new_pos, size, len;

	if (n == 0)
		return (num);
	len = _strlen(num);
	dec_pos = index_of(num, '.');
	if (dec_pos < 0)
		size = len - n > 0 ? len + 1 : (len - n == 0 ? len + 2 : n - len + len + 2);
	else if (dec_pos > 0)
		size = dec_pos - n > 0 ? len
			: (dec_pos - n == 0 ? len + 1 : len + (n - dec_pos + 1));
	else
		size = len + n + 1;
	new_pos = dec_pos < 0 ? size - n - 1
		: (dec_pos > 0 ? size - (len - dec_pos + n) : 1);
	result = malloc(sizeof(char) * (size + 1));
	if (result)
	{
		mem_set(result, size, '0');
		j = len - 1;
		for (i = size - 1; i >= 0; i--)
		{
			if (i == new_pos)
				*(result + i) = '.';
			i -= (i == new_pos ? 1 : 0);
			if (*(num + j) == '.')
				j--;
			if (*(num + j) != '.' && j >= 0)
				*(result + i) = *(num + j);
			j--;
		}
		*(result + size) = '\0';
		if (can_free)
			free(num);
	}
	return (result);
}

/**
 * set_float_parts - Sets the float_info fields to the appropriate
 * \ parts of a given float
 * @num: The given float
 * @exponent_size: The number of bits in the exponent part
 * @mantissa_size: The number of bits in the mantissa part
 * @float_info: The float_info struct
 */
void set_float_parts(double num,	uchar_t exponent_size,
	uchar_t mantissa_size, float_info_t *float_info)
{
	int i;
	char *str;
	uchar_t size = exponent_size + mantissa_size + 1;
	size_t tmp = *((size_t *)&num);

	if (float_info == NULL)
		return;
	str = malloc(sizeof(char) * (size + 1));
	if (str != NULL)
	{
		for (i = 0; i < size; i++)
			*(str + i) = ((tmp >> i) & 1)  + '0';
		*(str + size) = '\0';
		rev_string(str);
		float_info->sign = *str;
		for (i = 0; i < exponent_size; i++)
			*(float_info->exponent + i) = *(str + i + 1);
		*(float_info->exponent + i) = '\0';
		for (i = 0; i < mantissa_size; i++)
			*(float_info->mantissa + i) = *(str + i + exponent_size + 1);
		*(float_info->mantissa + i) = '\0';
		free(str);
	}
}

/**
 * _to_dec_fraction - Converts the mantissa of a float to a fraction
 * @mantissa: The mantissa to convert
 * @frac_len: The maximum length of the decimal fraction
 *
 * Return: The converted fraction
 */
char *_to_dec_fraction(char *mantissa, unsigned short frac_len)
{
	char *str, i, *pow2;
	int len = _strlen(mantissa);

	str = malloc(sizeof(char) * (frac_len + 3));
	if (str != NULL)
	{
		mem_set(str, frac_len + 2, '0');
		*(str + 1) = '.';
		*(str + frac_len + 2) = '\0';
		for (i = 0 - 1; i >= 0 - len; i--)
		{
			if (*(mantissa + ABS(i) - 1) == '1')
			{
				pow2 = two_pow_x(i);
				str = add_float(pow2, str, TRUE);
			}
		}
	}
	return (str);
}
