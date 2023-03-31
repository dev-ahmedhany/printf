#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * compare_numbers - Compares the left_align number to the right number
 * @left_align: The left_align number
 * @right: The right number
 *
 * Return: 1 if left_align is > right, -1 if left_align < right, otherwise 0
 */
char compare_numbers(char *left_align, char *right)
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
