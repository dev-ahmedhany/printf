#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * mem_set - Fills a section of a string with a given character
 * \ (starts from position 0)
 * @str: The string containing the section to be filled
 * @n: The length of the section to fill
 * @c: The character to fill the section with
 */
void mem_set(char *str, int n, char c)
{
	int i;

	for (i = 0; str != NULL && i < n; i++)
		*(str + i) = c;
}

/**
 * left_shift - Moves a string n bytes to the left_align
 * @str: The string to shift
 * @n: The number of bytes to shift
 */
void left_shift(char *str, int n)
{
	int i;

	for (i = 1; i <= n; i++)
		str[i - 1] = str[i] != '\0' && str[i - 1] != '\0' ? str[i] : '\0';
}

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
 * append_char - Adds multiple copies of a given character to the
 * \ end of a string
 * @str: The string whose ending is to be trimmed
 * @c: The character to add at the end of the string
 * @n: The number of times the character should be added
 * @can_free: Specifies if the given string can be freed
 *
 * Return: The new copy of the string, otherwise NULL
 */
char *append_char(char *str, char c, int n, char can_free)
{
	int i, size;
	char *new_str;

	size = str ? _strlen(str) : 0;
	new_str = malloc(sizeof(char) * (size + n + 1));
	if (new_str)
	{
		for (i = 0; i < (size + n); i++)
			new_str[i] = i < size ? str[i] : c;
		new_str[i] = '\0';
	}
	if (can_free)
		free(str);
	return (new_str);
}

/**
 * delete_char - Removes copies of a given character from a string
 * @str: The string containing the character
 * @c: The character to remove from the string
 * @can_free: Specifies if the given string can be freed
 *
 * Return: The new copy of the string, otherwise NULL
 */
char *delete_char(char *str, char c, char can_free)
{
	char *new_str;
	int len = _strlen(str), i;

	new_str = malloc(sizeof(char) * (len - count_char(str, c) + 1));
	if (new_str)
	{
		for (i = 0, len = 0; *(str + i) != '\0'; i++)
		{
			if (*(str + i) != c)
				*(new_str + len++) = *(str + i);
		}
		*(new_str + len) = '\0';
	}
	if (can_free)
		free(str);
	return (new_str);
}

/**
 * insert_char - Inserts a character into a string
 * @str: The source string
 * @pos: The insertion position of the character
 * @c: The character to insert into the string
 * @can_free: Specifies if the given string can be freed
 *
 * Return: The trimmed copy, otherwise NULL
 */
char *insert_char(char *str, int pos, char c, char can_free)
{
	char *new_str;
	int i, j, len;

	len = _strlen(str);
	new_str = malloc(sizeof(char) * (len + 2));
	if (new_str != NULL)
	{
		for (i = 0, j = 0; i < len; i++)
		{
			if (i == pos)
				*(new_str + j++) = c;
			*(new_str + j) = *(str + i);
			j++;
		}
		*(new_str + len + 1) = '\0';
		if (can_free)
			free(str);
	}
	return (new_str);
}

/**
 * count_char - Counts the number of copies of a character in a string
 * @str: The source string
 * @c: The character to look for
 *
 * Return: The number of times the character was found
 */
int count_char(char *str, char c)
{
	int count = 0, i;

	for (i = 0; str != NULL && *(str + i) != '\0'; i++)
		count += *(str + i) == c ? 1 : 0;
	return (count);
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
 * trim_start - Makes a trimmed copy of a string
 * @str: The string whose beginning is to be trimmed
 * @c: The character to strip from the beginning of the string
 * @can_free: Specifies if the given string can be freed
 *
 * Return: The trimmed copy, otherwise NULL
 */
char *trim_start(char *str, char c, char can_free)
{
	int i, j, len;
	char *new_str;

	for (i = 0; *(str + i) != '\0' && *(str + i) == c; i++)
		;
	len = _strlen(str) - i;
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str)
	{
		for (j = 0; *(str + i) != '\0'; i++)
		{
			*(new_str + j) = *(str + i);
			j++;
		}
		*(new_str + j) = '\0';
		if (can_free)
			free(str);
	}
	return (new_str);
}

/**
 * trim_end - Makes a trimmed copy of a string
 * @str: The string whose ending is to be trimmed
 * @c: The character to strip from the end of the string
 * @can_free: Specifies if the given string can be freed
 *
 * Return: The trimmed copy, otherwise NULL
 */
char *trim_end(char *str, char c, char can_free)
{
	char *new_str;
	int len = _strlen(str);
	int i, j;

	for (i = len - 1; i >= 0 && *(str + i) == c; i--)
		;
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str)
	{
		for (j = 0; j <= i; j++)
			*(new_str + j) = *(str + j);
		*(new_str + j) = '\0';
		if (can_free)
			free(str);
	}
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
