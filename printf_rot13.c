#include "main.h"
/**
 * printf_rot13 - printf str to ROT13 place into buffer
 * @list: type struct va_arg where is allocated printf arguments
 * Return: counter
 *
 */
int printf_rot13(va_list list)
{
	int i, j, counter = 0;
	int k = 0;
	char *s = va_arg(list, char*);
	char normal[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char rot13[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		k = 0;
		for (j = 0; normal[j] && !k; j++)
		{
			if (s[i] == normal[j])
			{
				_putchar(rot13[j]);
				counter++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(s[i]);
			counter++;
		}
	}
	return (counter);
}
