#include <stdlib.h>
#include "main.h"

/**
 * init_format_info - initializes a format info struct
 * @specifier: The format info to initialize
 */
void init_format_info(fmt_info_t  *specifier)
{
	if (specifier)
	{
		specifier->precision = 1;
		specifier->width = 0;
		specifier->specifier = FALSE;
		specifier->is_long_double = FALSE;
		specifier->is_long_long = FALSE;
		specifier->is_long = FALSE;
		specifier->is_short = FALSE;
		specifier->is_char = FALSE;
		specifier->is_precision_set = FALSE;
		specifier->is_width_set = FALSE;
		specifier->hash = FALSE;
		specifier->space = FALSE;
		specifier->left_align = FALSE;
		specifier->plus_sign = FALSE;
		specifier->group = FALSE;
		specifier->padding = ' ';
	}
}

/**
 * new_format_info - Creates a new format info structure and initializes it
 *
 * Return: The pointer to the newly created format info structure or NULL
 */
fmt_info_t  *new_format_info()
{
	fmt_info_t  *specifier;

	specifier = malloc(sizeof(fmt_info_t));
	if (specifier)
		init_format_info(specifier);
	return (specifier);
}

/**
 * new_float_info - Creates a new float_info struct
 * @exponent_size: The number of bits in the exponent
 * @mantissa_size: The number of bits in the mantissa
 *
 * Return: The pointer to the newly created struct, otherwise NULL
 */
float_info_t *new_float_info(ushort_t exponent_size, ushort_t mantissa_size)
{
	float_info_t *float_info;

	float_info = malloc(sizeof(float_info_t));
	if (float_info != NULL)
	{
		float_info->exponent = malloc(sizeof(char) * (exponent_size + 1));
		if (float_info->exponent == NULL)
			free(float_info);
		float_info->mantissa = malloc(sizeof(char) * (mantissa_size + 1));
		if (float_info->mantissa == NULL)
		{
			free(float_info->exponent);
			free(float_info);
		}
	}
	return (float_info);
}

/**
 * free_float_info - Frees the memory allocated to the given pointer
 * @flt_info: The pointer to free
 */
void free_float_info(float_info_t *flt_info)
{
	if (flt_info != NULL)
	{
		if (flt_info->exponent != NULL)
			free(flt_info->exponent);
		if (flt_info->mantissa != NULL)
			free(flt_info->mantissa);
		free(flt_info);
	}
}
