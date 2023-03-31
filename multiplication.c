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
