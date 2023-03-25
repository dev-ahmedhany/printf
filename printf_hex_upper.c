#include "main.h"

int is_lowercase(char);
char *string_to_upper(char *);

/**
 * printf_hex_upper - Print a number in hexadecimal format
 * @list: Number to print
 *
 * Return: Length of the number
 **/
int printf_hex_upper(va_list list)
{
	char *p_buff;
	int len, i;

	p_buff = _itoa(va_arg(list, unsigned int), 16);
	p_buff = string_to_upper(p_buff);

	len = _strlen(p_buff);

	for (i = 0 ; i < len ; i++)
		_putchar(p_buff[i]);

	return (len);
}

/**
 * is_lowercase - Check if the character are in lowercase
 * @c: Character
 * Return: 1 or 0
 **/
int is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * string_to_upper - Change the string to uppercase
 * @s: String
 * Return: String uppercase
 **/
char *string_to_upper(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_lowercase(s[i]))
		{
			s[i] = s[i] - 32;
		}
	}

	return (s);
}

