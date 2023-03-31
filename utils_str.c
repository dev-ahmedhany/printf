#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * index_of - Returns the first index of a character in a string
 * @str: The string that could contain the character
 * @c: The character to look for
 *
 * Return: The position of the character if found, otherwise -1
 */
int index_of(char *str, char c)
{
	int i;

	for (i = 0; *(str + i) != '\0' && *(str + i) != c; i++)
		;
	return (*(str + i) == c ? i : -1);
}

/**
 * str_cat - Concatenates two strings
 * @left_align: The left_align string
 * @right: The right string
 * @can_free: Specifies if the given strings can be freed
 *
 * Return: A pointer to the concatenated string
 */
char *str_cat(char *left_align, char *right, char can_free)
{
	int left_length = _strlen(left_align);
	int right_length = _strlen(right);
	int i;
	char *str;

	if (left_align == NULL && right == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (left_length + right_length + 1));
	if (str != NULL)
	{
		for (i = 0; *(left_align + i) != '\0'; i++)
			*(str + i) = *(left_align + i);
		for (i = 0; *(right + i) != '\0'; i++)
			*(str + left_length + i) = *(right + i);
		*(str + left_length + right_length) = '\0';
	}
	if (can_free)
	{
		free(left_align);
		free(right);
	}
	return (str);
}

/**
 * sub_str - Makes a copy of a subset of a string
 * @str: The string containing the subset
 * @i: The starting position of the subset
 * @can_free: Specifies if the given string can be freed
 *
 * Return: The string subset, otherwise NULL
 */
char *sub_str(char *str, int i, char can_free)
{
	char *new_str;
	int len = _strlen(str);
	char start = i < 0 ? len + i : i;
	int size = i < 0 ? -i : len - start;
	int j;

	new_str = malloc(sizeof(char) * (size + 1));
	if (str)
	{
		for (j = 0; *(str + start) != 0; j++)
		{
			*(new_str + j) = *(str + start);
			start++;
		}
		*(new_str + j) = '\0';
	}
	if (can_free)
		free(str);
	return (new_str);
}

/**
 * str_copy - Makes a copy of a string
 * @str: The string to copy
 *
 * Return: The copied string, otherwise NULL
 */
char *str_copy(char *str)
{
	char *new_str;
	int i;
	int len = _strlen(str);

	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str)
	{
		for (i = 0; i < len; i++)
			*(new_str + i) = *(str + i);
		*(new_str + i) = '\0';
	}
	return (new_str);
}
