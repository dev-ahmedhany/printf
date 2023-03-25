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

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 * @minus: flag for '-' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int minus;
} flags_t;

int _printf(const char *format, ...);

/* extra functions */
int _strlen(const char *);
int _putchar(char);
char* _itoa (int value, char* buffer, int base);
void swap(char *x, char *y);
char* reverse(char *buffer, int i, int j);

/* placeHolder.c */
int findPlaceHolder(const char *, va_list);
int substituteFormat(const char *, va_list, int *);

/* print functions */
int printf_string(va_list);
int printf_char(va_list);
int printf_binary(va_list);
int printf_pointer(va_list);
int printf_rot13(va_list);

#endif /* MAIN_H */
