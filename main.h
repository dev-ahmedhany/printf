#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct _format - Typedef struct
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
int _strlen(char *);
int _putchar(char);

/* placeHolder.c */
int findPlaceHolder(const char *, va_list);
int substituteFormat(const char *, va_list, int *);

/* print functions */
int printf_string(va_list);
int printf_char(va_list);

#endif /* MAIN_H */