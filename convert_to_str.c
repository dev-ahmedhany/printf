#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * unsigned_long_to_str - Converts an unsigned long
 * to its string representation
 * @num: The unsigned long integer
 *
 * Return: The string representation of the unsigned long integer
 */
char *unsigned_long_to_str(unsigned long num)
{
	char *str;
	unsigned long rem = num;
	char size = 20, j;

	str = malloc(sizeof(char) * (size + 1));
	if (str)
	{
		*(str + size) = '\0';
		mem_set(str, size, '0');
		j = size - 1;
		while (rem > 0)
		{
			*(str + j) = (rem % 10) + '0';
			rem /= 10;
			j--;
		}
		str = trim_start(str, '0', TRUE);
		str = num == 0 ? str_cat("0", "", FALSE) : str;
	}
	return (str);
}

/**
 * long_to_str - Converts a long to its string representation
 * @num: The long integer
 *
 * Return: The string representation of the long integer
 */
char *long_to_str(long num)
{
	char *str;
	long rem = num;
	char sign = rem < 0 ? -1 : 1;
	char size = 20, j;

	str = malloc(sizeof(char) * (size + 1));
	if (str)
	{
		*(str + size) = '\0';
		mem_set(str, size, '0');
		j = size - 1;
		if (rem == 0)
			*(str + j) = '0';

		while ((sign == -1 && rem < 0) || (sign == 1 && rem > 0))
		{
			*(str + j) = (rem % 10) * sign + '0';
			rem /= 10;
			j--;
		}
		if (sign < 0)
			*(str + j) = '-';
		str = trim_start(str, '0', TRUE);
		str = num == 0 ? str_cat("0", "", FALSE) : str;
	}
	return (str);
}

/**
 * ptr_to_str - Converts a pointer to its string representation
 * @ptr: The pointer
 *
 * Return: The string representation of the pointer
 */
char *ptr_to_str(void *ptr)
{
	int i, size;
	uintptr_t tmp;
	char *str, *str0;

	if (ptr)
	{
		tmp = (uintptr_t)ptr;
		size = sizeof(ptr) * 2;
		str = malloc(sizeof(char) * (size + 1));
		if (str)
		{
			str0 = malloc(sizeof(char) * (2 + 1));
			if (str0)
			{
				mem_set(str, size, '0');
				for (i = 0; i < size; i++)
				{
					*(str + i) = (tmp % 16) < 10 ? (tmp % 16) + '0'
						: (tmp % 16) - 10 + 'a';
					tmp /= 16;
				}
				*(str + i) = '\0';
				*(str0 + 0) = '0';
				*(str0 + 1) = 'x';
				*(str0 + 2) = '\0';
				rev_string(str);
				str = trim_start(str, '0', TRUE);
				str = *str == '\0' ? str_cat("0", "", FALSE) : str;
				str = str_cat(str0, str, TRUE);
			}
			if (!str0)
				free(str);
		}
	}
	else
	{
		str = str_copy("(nil)");
	}
	return (str);
}

/**
 * float_to_str - Converts an IEEE 754 float to its string representation
 * @flt_info: The information about the float
 * @can_free: Specifies whether the given numbers can be freed
 *
 * Return: The string representation of the float, otherwise NULL
 */
char *float_to_str(float_info_t *flt_info, char can_free)
{
	uchar_t exponent_size = _strlen(flt_info->exponent);
	short bias = two_pow_n(exponent_size) / 2 - 1, exponent;
	char *power, *fraction, *product, *float_num, *pow_frac;
	unsigned short frac_len = 22;/* Only doubles are supported */

	exponent = bin_to_int(flt_info->exponent) - bias;
	power = two_pow_x(exponent);
	fraction = _to_dec_fraction(flt_info->mantissa, frac_len);
	fraction[0] = '1';
	if (exponent >= 0)
	{
		pow_frac = malloc(sizeof(char) * 3);
		if (pow_frac)
		{
			*(pow_frac + 0) = '.';
			*(pow_frac + 1) = '0';
			*(pow_frac + 2) = '\0';
			power = str_cat(power, pow_frac, TRUE);
		}
	}
	product = mul_float(fraction, power, TRUE);
	float_num = str_cat(flt_info->sign == '1' ? "-" : "", product, FALSE);
	free(product);
	if (can_free)
		free_float_info(flt_info);
	return (float_num);
}
