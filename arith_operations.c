#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * multiply - Computes the product of a number and a multiple of 10
 * @num: The first number
 * @multiple: The second number (a multiple of 10)
 *
 * Return: A pointer containing the result, otherwise program fails
 */
char *multiply(char *num, char *multiple)
{
	int size, mult_len, num_len, i, j;
	char *result, rem, carry = 0;

	mult_len = _strlen(multiple);
	num_len = _strlen(num);
	size = mult_len + num_len;
	result = malloc(sizeof(char) * (size + 1));
	if (result != NULL)
	{
		mem_set(result, size, '0');
		*(result + size) = '\0';
		mult_len--;
		j = size - mult_len - 1;
		for (i = 1; i <= mult_len; i++)
			*(result + size - i) = '0';
		for (i = num_len - 1; i >= 0; i--)
		{
			if (!(*(num + i) >= '0' && *(num + i) <= '9'))
				break;
			if (!(*multiple >= '0' && *multiple <= '9'))
				break;
			rem = ((*(num + i) - '0') * (*multiple - '0') + carry) % 10;
			carry = ((*(num + i) - '0') * (*multiple - '0') + carry) / 10;
			*(result + j) = rem + '0';
			j--;
		}
		if (carry > 0)
			*(result + j) = carry + '0';
		return (result);
	}
	return (NULL);
}

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

/**
 * mul_int - Computes the product of two positive integers
 * @left_align: The first number
 * @right: The second number
 * @can_free: Specifies whether the given numbers can be freed
 *
 * Return: The product of the two numbers, otherwise NULL
 */
char *mul_int(char *left_align, char *right, char can_free)
{
	char *result, *product;
	int size, i, len2;

	size = _strlen(left_align);
	len2 = _strlen(right);
	size += len2;
	result = malloc(sizeof(char) * (size + 1));
	if (result != NULL)
	{
		mem_set(result, size, '0');
		*(result + size) = '\0';
		for (i = 0; i < len2; i++)
		{
			product = multiply(left_align, right + i);
			result = add_int(product, result, TRUE);
		}
		while (*result == '0' && *(result + 1) != '\0')
			left_shift(result, size);
		if (can_free)
		{
			free(left_align);
			free(right);
		}
	}
	return (result);
}

/**
 * mul_float - Computes the product of two positive floats
 * @left_align: The first number
 * @right: The second number
 * @can_free: Specifies whether the given numbers can be freed
 *
 * Return: The product of the two floats, otherwise NULL
 */
char *mul_float(char *left_align, char *right, char can_free)
{
	char *left_c = str_copy(left_align);
	char *right_c = str_copy(right);
	int len1, len2, dec_pos1, dec_pos2, frac_len1, frac_len2, size, old_size;
	char *product;

	len1 = _strlen(left_c);
	len2 = _strlen(right_c);
	dec_pos1 = index_of(left_c, '.');
	dec_pos2 = index_of(right_c, '.');
	frac_len1 = len1 - (dec_pos1 + 1);
	frac_len2 = len2 - (dec_pos2 + 1);
	if (frac_len1 < frac_len2)
		left_c = append_char(left_c, '0', frac_len2 - frac_len1, TRUE);
	if (frac_len2 < frac_len1)
		right_c = append_char(right_c, '0', frac_len1 - frac_len2, TRUE);
	size = MAX(len1, len2);
	product = malloc(sizeof(char) * (size + 1));
	if (product)
	{
		mem_set(product, size, '0');
		left_c = delete_char(left_c, '.', TRUE);
		right_c = delete_char(right_c, '.', TRUE);
		old_size = size - 1;
		product = mul_int(left_c, right_c, TRUE);
		size = _strlen(product) - old_size;
		product = insert_char(product,
			size - MAX(frac_len1, frac_len2) + 1, '.', TRUE);
		product = trim_end(product, '0', TRUE);
		if (can_free)
		{
			free(left_align);
			free(right);
		}
	}
	return (product);
}

/**
 * round_float_to_int - Rounds a floating point number to an integer
 * @num: The floating point number to round
 * @len: The length of the floating-point number
 * @dec_pos: The position of the decimal point in the floating point number
 * @frac_len: The length of the fractional part in the floating point number
 *
 * Return: The integer, otherwise NULL
 */
char *round_float_to_int(char *num, int len, int dec_pos, int frac_len)
{
	int i;
	char *one, *result = NULL;

	result = malloc(sizeof(char) * (len - frac_len));
	if (result != NULL)
	{
		for (i = 0; i < (len - frac_len); i++)
			*(result + i) = *(num + i);
		*(result + i) = '\0';
		one = str_copy("1");
		if (one != NULL)
		{
			if (*(num + dec_pos + 1) != '\0' && *(num + dec_pos + 1) > '4')
				result = add_int(one, result, TRUE);
			else
				free(one);
		}
	}
	return (result);
}

/**
 * round_float - Rounds a floating point number
 * @num: The floating point number to round
 * @precision: The number of precision of the fractional part
 * @can_free: Specifies whether the given numbers can be freed
 *
 * Return: The rounded float, otherwise NULL
 */
char *round_float(char *num, unsigned int precision, char can_free)
{
	unsigned int dec_pos = index_of(num, '.'), len = (unsigned int)_strlen(num);
	unsigned int size, frac_len = len - (dec_pos + 1), i;
	char *one, *result = NULL;

	if (precision == 0)
	{
		result = round_float_to_int(num, len, dec_pos, frac_len);
	}
	else if (frac_len != precision)
	{
		if (frac_len > precision)
		{
			size = len - (frac_len - precision);
			result = malloc(sizeof(char) * (size + 1));
			for (i = 0; i < len - (frac_len - precision); i++)
				*(result + i) = *(num + i);
			*(result + i) = '\0';
			if (*(num + (len - (frac_len - precision))) > '4')
			{
				one = str_copy(result);
				mem_set(one, size, '0');
				*(one + dec_pos) = '.';
				*(one + size - 1) = '1';
				result = add_float(result, one, TRUE);
			}
		}
		else
		{
			result = str_copy(num);
			result = append_char(result, '0', precision - frac_len, TRUE);
		}
	}
	if (can_free)
		free(num);
	return (result);
}
