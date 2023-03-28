#ifndef MAIN_H
#define MAIN_H

#include <unistd.h> /* write */
#include <stdlib.h> /* malloc, free */
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;


/**
 * struct format - Typedef struct
 *
 * @type: Format
 * @f: The function implemented
 **/
typedef struct format
{
	char type;
	int (*f)(va_list, flags_t *f);
} format;


int get_flag(char s, flags_t *f);
int _printf(const char *format, ...);

/* extra functions */
int _strlen(const char *);
int _putchar(char);
int _puts(char *);

char *_itoa(long int, int);


/* placeHolder.c */
int findPlaceHolder(const char *, va_list);
int substituteFormat(const char *, va_list, int *);

/* print functions */
int printf_string(va_list, flags_t *f);
int printf_char(va_list, flags_t *f);
int printf_binary(va_list, flags_t *f);
int printf_pointer(va_list, flags_t *f);
int printf_rot13(va_list, flags_t *f);
int printf_rev_string(va_list, flags_t *f);
int printf_integer(va_list, flags_t *f);
int printf_unsigned(va_list, flags_t *f);
int printf_octal(va_list, flags_t *f);
int printf_hex_lower(va_list, flags_t *f);
int printf_hex_upper(va_list, flags_t *f);
int print_bigS(va_list, flags_t *f);
char *convert(unsigned long int num, int base, int lowercase);

#endif /* MAIN_H */
