#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * cmp_nums - Compares the left_align number to the right number
 * @left_align: The left_align number
 * @right: The right number
 *
 * Return: 1 if left_align is > right, -1 if left_align < right, otherwise 0
 */
char cmp_nums(char *left_align, char *right)
{
	char *num1 = left_align;
	char *num2 = right;
	int len1 = _strlen(num1) - 1, len2 = _strlen(num2) - 1, i = 0;

	for (i = 0; (*(num1 + i) == '0' && *(num1 + i + 1) != '\0') && i < len1; i++)
		;
	num1 = num1 + i;
	len1 = _strlen(num1);
	for (i = 0; (*(num2 + i) == '0' && *(num2 + i + 1) != '\0') && i < len2; i++)
		;
	num2 = num2 + i;
	len2 = _strlen(num2);
	if (len1 > len2)
	{
		return (1);
	}
	else if (len1 < len2)
	{
		return (-1);
	}
	else
	{
		for (i = 0; i < len1; i++)
		{
			if (*(num1 + i) > *(num2 + i))
				return (1);
			if (*(num1 + i) < *(num2 + i))
				return (-1);
		}
		return (0);
	}
}

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

/**
 * long_to_oct - Converts a long integer to its octal representation
 * @num: The number to convert
 *
 * Return: The octal representation of the number, otherwise NULL
 */
char *long_to_oct(unsigned long num)
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

/**
 * div_by_10_exp - Divides a number by a power of 10
 * @num: The number to divide
 * @n: The power of 10
 * @can_free: Specifies whether the given number can be freed
 *
 * Return: The quotient of the number and the power of 10, otherwise NULL
 */
char *div_by_10_exp(char *num, unsigned short n, char can_free)
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
 * two_exp - Computes 2 raised to the given power
 * @n: The power
 *
 * Return: The value of 2 index n, otherwise NULL
 */
char *two_exp(short n)
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
			pow_b5 = five_exp(n * -1);
			result = div_by_10_exp(pow_b5, n * -1, TRUE);
		}
	}
	return (result);
}

/**
 * five_exp - Computes 5 raised to the given positive power
 * @n: The power
 *
 * Return: The value of 5 index n, otherwise NULL
 */
char *five_exp(unsigned short n)
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
 * two_pexp - Computes 2 raised to the given positive power
 * @n: The positive index
 *
 * Return: The value of 2 exponent n
 */
unsigned int two_pexp(unsigned int n)
{
	unsigned int result = 1;
	unsigned int i;

	for (i = 0; i < n; i++)
		result *= 2;
	return (result);
}

/**
 * u_long_to_hex - Converts an unsigned long to its string representation
 * @num: The unsigned long number
 * @upper: Specifies whether the hexadecimals should be in uppercase
 *
 * Return: The string representation of the number in hexadecimal notation
 */
char *u_long_to_hex(unsigned long num, char upper)
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

/**
 * u_long_to_str - Converts an unsigned long to its string representation
 * @num: The unsigned long integer
 *
 * Return: The string representation of the unsigned long integer
 */
char *u_long_to_str(unsigned long num)
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
 * mantissa_to_dec_fraction - Converts the mantissa of a float to a fraction
 * @mantissa: The mantissa to convert
 * @frac_len: The maximum length of the decimal fraction
 *
 * Return: The converted fraction
 */
char *mantissa_to_dec_fraction(char *mantissa, unsigned short frac_len)
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
				pow2 = two_exp(i);
				str = add_float(pow2, str, TRUE);
			}
		}
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
	short bias = two_pexp(exponent_size) / 2 - 1, exponent;
	char *power, *fraction, *product, *float_num, *pow_frac;
	unsigned short frac_len = 22;/* Only doubles are supported */

	exponent = bin_to_int(flt_info->exponent) - bias;
	power = two_exp(exponent);
	fraction = mantissa_to_dec_fraction(flt_info->mantissa, frac_len);
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