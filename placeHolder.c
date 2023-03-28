#include "main.h"

/**
 * findPlaceHolder - Format controller
 * @str: String format
 * @list: List of arguments
 *
 * Return: Total size of arguments with the total size of the base string
 **/
int findPlaceHolder(const char *str, va_list list)
{
	int size, i, aux;

	size = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == '%')
		{
			aux = substituteFormat(str, list, &i);
			if (aux == -1)
			{
				return (-1);
			}

			size += aux;
		}
		else
		{
			size += _putchar(str[i]);
		}
	}
	_putchar(-1);

	return (size);
}

/**
 * substituteFormat - Controller for percent format
 * @str: String format
 * @list: List of arguments
 * @i: Iterator
 *
 * Return: Size of the numbers of elements printed
 **/
int substituteFormat(const char *str, va_list list, int *i)
{
	int j, number_formats;
	flags_t flags = {0, 0, 0};

	format formats[] = {
		{'s', printf_string}, {'c', printf_char},
		{'S', print_bigS}, {'b', printf_binary},
		{'p', printf_pointer}, {'R', printf_rot13},
		{'r', printf_rev_string}, {'d', printf_integer},
		{'i', printf_integer}, {'o', printf_octal},
		{'x', printf_hex_lower}, {'X', printf_hex_upper},
		{'u', printf_unsigned}
	};

	(*i)++;


	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
		return _putchar('%');

	while (get_flag(str[*i], &flags))
		(*i)++;

	number_formats = sizeof(formats) / sizeof(formats[0]);
	for (j = 0; j < number_formats; j++)
	{
		if (str[*i] == formats[j].type)
		{
			return formats[j].f(list, &flags);
		}
	}

	_putchar('%'), _putchar(str[*i]);

	return (2);
}
