#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;
    
       
	_printf("%b\n", 98);
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("%S\n", "Best\nSchool");
	printf("%s\n", "Best\\x0ASchool");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf(" %+d \n", 0);
	printf(" %+d \n", 0);
	_printf(" %+d \n", -1);
	printf(" %+d \n", -1);
	_printf(" %+d \n", 9);
	printf(" %+d \n", 9);
	_printf(" %+d \n", 10);
	printf(" %+d \n", 10);
	_printf(" %+d \n", 11);
	printf(" %+d \n", 11);
	_printf(" %+d \n", 15);
	printf(" %+d \n", 15);
	_printf(" %+d \n", 16);
	printf(" %+d \n", 16);
	_printf(" %+d \n", 17);
	printf(" %+d \n", 17);
	_printf(" %+d \n", 99);
	printf(" %+d \n", 99);
	_printf(" %+d \n", 100);
	printf(" %+d \n", 100);
	_printf(" %+d \n", 101);
	printf(" %+d \n", 101);
	_printf(" %+d \n", -9);
	printf(" %+d \n", -9);
	return (0);
}
