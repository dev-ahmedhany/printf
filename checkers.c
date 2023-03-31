#include "main.h"

/**
 * is_digit - Checks if the given character is a digit character
 * @c: The character to check
 *
 * Return: 1 or 0
 */
char is_digit(char c)
{
	return (c >= '0' && c <= '9' ? TRUE : FALSE);
}

/**
 * non_custom_specifier - Checks if the given character is a non-custom
 * specifier character
 * @c: The character to check
 *
 * Return: 1 or 0
 */
char non_custom_specifier(char c)
{
	switch (c)
	{
	case '%':
	case 'c':
	case 'd':
	case 'E':
	case 'e':
	case 'F':
	case 'f':
	case 'i':
	case 'n':
	case 'o':
	case 'p':
	case 's':
	case 'u':
	case 'X':
	case 'x':
		return (TRUE);
	default:
		return (FALSE);
	}
}

/**
 * is_specifier - Checks if the given character is a
 * \ specifier character
 * @c: The character to check
 *
 * Return: 1 or 0
 */
char is_specifier(char c)
{
	if (non_custom_specifier(c))
	{
		return (TRUE);
	}
	else
	{
		switch (c)
		{
		case 'b':
		case 'R':
		case 'r':
		case 'S':
			return (TRUE);
		default:
			return (FALSE);
		}
	}
}

/**
 * is_letter - Checks if the given character is a letter
 * @c: The character to check
 *
 * Return: 1 or 0
 */
char is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? TRUE : FALSE);
}

/**
 * check_validity - Checks if a given float is invalid
 * @flt_info: The float info struct to check
 *
 * Return: NULL if it is valid, otherwise inf or nan
 */
char *check_validity(float_info_t *flt_info)
{
	uchar_t exp_bits_on = 0, exp_all_on;
	short mant_bits_on = 0;
	char lsb_on = FALSE, msb_on = FALSE;
	int i;

	if (flt_info != NULL)
	{
		for (i = 0; *(flt_info->exponent + i) != '\0'; i++)
		{
			if (*(flt_info->exponent + i) == '1')
				exp_bits_on++;
		}
		exp_all_on = i == exp_bits_on;
		for (i = 0; *(flt_info->mantissa + i) != '\0'; i++)
		{
			msb_on = i == 0 && *(flt_info->mantissa + i) == '1' ? TRUE : msb_on;
			lsb_on = *(flt_info->mantissa + i + 1) == '\0'
				&& *(flt_info->mantissa + i) == '1' ? TRUE : lsb_on;
			if (*(flt_info->mantissa + i) == '1')
				mant_bits_on++;
		}
		if (exp_all_on)
		{
			if ((flt_info->sign == '0' && mant_bits_on == 0)
				|| (flt_info->sign == '1' && mant_bits_on == 0))
			{
				return (str_copy("inf"));
			}
			else if ((flt_info->sign == '0' && mant_bits_on == 1 && lsb_on)
				|| (flt_info->sign == '0' && mant_bits_on == 2 && lsb_on && msb_on)
				|| (flt_info->sign == '0' && mant_bits_on == i))
			{
				return (str_copy("nan"));
			}
		}
	}
	return (NULL);
}
