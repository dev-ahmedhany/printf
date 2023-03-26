#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct format - Typedef struct
 *
 * @type: Format
 * @f: The function implemented
 **/
typedef struct format
{
	char type;
	int (*f)(va_list);
} format;


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
int printf_string(va_list);
int printf_char(va_list);
int printf_binary(va_list);
int printf_pointer(va_list);
int printf_rot13(va_list);
int printf_rev_string(va_list);
int printf_integer(va_list);
int printf_unsigned(va_list);
int printf_octal(va_list);
int printf_hex_lower(va_list);
int printf_hex_upper(va_list);
int print_bigS(va_list);
char *convert(unsigned long int num, int base, int lowercase);

#endif /* MAIN_H */
