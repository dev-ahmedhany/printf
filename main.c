#include <stdio.h>
#include <limits.h>
#include "main.h"

 /**
  * test - test function
  * @len1: length of string
  * @len2: length of string
  */
 void test(int len1, int len2);

 /**
  * main - Entry point
  *
  * Return: Always 0
  */
 int main(void)
 {
		double OneSeventh = 1.0/7.0;
	printf("----original Test Cases----\n");
	test(_printf("Let's try to printf a simple sentence.\n"),printf("Let's try to printf a simple sentence.\n"));
	test(_printf("Negative:[%d]\n", -762534),printf("Negative:[%d]\n", -762534));
	test(_printf("Unsigned:[%u]\n", (unsigned int)INT_MAX + 1024),printf("Unsigned:[%u]\n", (unsigned int)INT_MAX + 1024));
	test(_printf("Unsigned octal:[%o]\n", (unsigned int)INT_MAX + 1024),printf("Unsigned octal:[%o]\n", (unsigned int)INT_MAX + 1024));
	test(_printf("Unsigned hexadecimal:[%x, %X]\n", (unsigned int)INT_MAX + 1024, (unsigned int)INT_MAX + 1024),printf("Unsigned hexadecimal:[%x, %X]\n", (unsigned int)INT_MAX + 1024, (unsigned int)INT_MAX + 1024));
	test(_printf("Character:[%c]\n", 'H'),printf("Character:[%c]\n", 'H'));
	test(_printf("String:[%s]\n", "I am a string !"),printf("String:[%s]\n", "I am a string !"));
	test(_printf("Address:[%p]\n", (void *)0x7ffe637541f0),printf("Address:[%p]\n", (void *)0x7ffe637541f0));
	test(_printf("Percent:[%%]\n"),printf("Percent:[%%]\n"));
 	printf("----positive sign (+) Flag Tests----\n");	
 	test(_printf(" %+d \n", 0),printf(" %+d \n", 0));
 	test(_printf(" %+d \n", -1),printf(" %+d \n", -1));
 	test(_printf(" %+d \n", 9),printf(" %+d \n", 9));
 	test(_printf(" %+d \n", 10),printf(" %+d \n", 10));
 	test(_printf(" %+d \n", 11),printf(" %+d \n", 11));
 	test(_printf(" %+d \n", 15),printf(" %+d \n", 15));
 	test(_printf(" %+d \n", 16),printf(" %+d \n", 16));
 	test(_printf(" %+d \n", 17),printf(" %+d \n", 17));
 	test(_printf(" %+d \n", 99),printf(" %+d \n", 99));
 	test(_printf(" %+d \n", 100),printf(" %+d \n", 100));
 	test(_printf(" %+d \n", 101),printf(" %+d \n", 101));
 	test(_printf(" %+d \n", -9),printf(" %+d \n", -9));
 	printf("----space ( ) Flag Tests----\n");
 	test(_printf(" % d \n", 0),printf(" % d \n", 0));
 	test(_printf(" % d \n", -1),printf(" % d \n", -1));
 	test(_printf(" % d \n", 1),printf(" % d \n", 1));
 	test(_printf(" % d \n", 9),printf(" % d \n", 9));
 	test(_printf(" % d \n", 10),printf(" % d \n", 10));
 	test(_printf(" % d \n", 11),printf(" % d \n", 11));
 	test(_printf(" % d \n", 15),printf(" % d \n", 15));
 	test(_printf(" % d \n", 16),printf(" % d \n", 16));
 	test(_printf(" % d \n", 17),printf(" % d \n", 17));
 	test(_printf(" % d \n", 99),printf(" % d \n", 99));
 	test(_printf(" % d \n", 100),printf(" % d \n", 100));
 	test(_printf(" % d \n", 101),printf(" % d \n", 101));
 	test(_printf(" % d \n", -9),printf(" % d \n", -9));
 	test(_printf(" % d \n", -10),printf(" % d \n", -10));
 	test(_printf(" % d \n", -11),printf(" % d \n", -11));
 	test(_printf(" % d \n", -15),printf(" % d \n", -15));
 	test(_printf(" % d \n", -16),printf(" % d \n", -16));
 	test(_printf(" % d \n", -17),printf(" % d \n", -17));
 	test(_printf(" % d \n", -99),printf(" % d \n", -99));
 	test(_printf(" % d \n", -100),printf(" % d \n", -100));
 	test(_printf(" % d \n", -101),printf(" % d \n", -101));
 	test(_printf(" % d \n", 2147483647),printf(" % d \n", 2147483647));
 	test(_printf(" % d \n", -2147483647),printf(" % d \n", -2147483647));
 	printf("----Hash Flag Tests----\n");
 	test(_printf(" %#x \n", 0),printf(" %#x \n", 0));
 	test(_printf(" %#x \n", -1),printf(" %#x \n", -1));
 	test(_printf(" %#x \n", 1),printf(" %#x \n", 1));
 	test(_printf(" %#x \n", 9),printf(" %#x \n", 9));
 	test(_printf(" %#x \n", 10),printf(" %#x \n", 10));
 	test(_printf(" %#x \n", 11),printf(" %#x \n", 11));
 	test(_printf(" %#x \n", 15),printf(" %#x \n", 15));
 	test(_printf(" %#x \n", 16),printf(" %#x \n", 16));
 	test(_printf(" %#x \n", 17),printf(" %#x \n", 17));
 	test(_printf(" %#x \n", 99),printf(" %#x \n", 99));
 	test(_printf(" %#x \n", 100),printf(" %#x \n", 100));
 	test(_printf(" %#x \n", 101),printf(" %#x \n", 101));
 	test(_printf(" %#x \n", -9),printf(" %#x \n", -9));
 	test(_printf(" %#x \n", -10),printf(" %#x \n", -10));
 	test(_printf(" %#x \n", -11),printf(" %#x \n", -11));
 	test(_printf(" %#x \n", -14),printf(" %#x \n", -14));
 	test(_printf(" %#x \n", -15),printf(" %#x \n", -15));
 	test(_printf(" %#x \n", -16),printf(" %#x \n", -16));
 	test(_printf(" %#x \n", -17),printf(" %#x \n", -17));
 	test(_printf(" %#x \n", -99),printf(" %#x \n", -99));
 	test(_printf(" %#x \n", -100),printf(" %#x \n", -100));
 	test(_printf(" %#x \n", -101),printf(" %#x \n", -101));
 	test(_printf(" %#x \n", 2147483647),printf(" %#x \n", 2147483647));
 	test(_printf(" %#x \n", -2147483647),printf(" %#x \n", -2147483647));
 	test(_printf(" %#X \n", 0),printf(" %#X \n", 0));
 	test(_printf(" %#X \n", -1),printf(" %#X \n", -1));
 	test(_printf(" %#X \n", 1),printf(" %#X \n", 1));
 	test(_printf(" %#X \n", 9),printf(" %#X \n", 9));
 	test(_printf(" %#X \n", 10),printf(" %#X \n", 10));
 	test(_printf(" %#X \n", 11),printf(" %#X \n", 11));
 	test(_printf(" %#X \n", 15),printf(" %#X \n", 15));
 	test(_printf(" %#X \n", 16),printf(" %#X \n", 16));
 	test(_printf(" %#X \n", 17),printf(" %#X \n", 17));
 	test(_printf(" %#X \n", 99),printf(" %#X \n", 99));
 	test(_printf(" %#X \n", 100),printf(" %#X \n", 100));
 	test(_printf(" %#X \n", 101),printf(" %#X \n", 101));
 	test(_printf(" %#X \n", -9),printf(" %#X \n", -9));
 	test(_printf(" %#X \n", -10),printf(" %#X \n", -10));
 	test(_printf(" %#X \n", -11),printf(" %#X \n", -11));
 	test(_printf(" %#X \n", -14),printf(" %#X \n", -14));
 	test(_printf(" %#X \n", -15),printf(" %#X \n", -15));
 	test(_printf(" %#X \n", -16),printf(" %#X \n", -16));
 	test(_printf(" %#X \n", -17),printf(" %#X \n", -17));
 	test(_printf(" %#X \n", -99),printf(" %#X \n", -99));
 	test(_printf(" %#X \n", -100),printf(" %#X \n", -100));
 	test(_printf(" %#X \n", -101),printf(" %#X \n", -101));
 	test(_printf(" %#X \n", 2147483647),printf(" %#X \n", 2147483647));
 	test(_printf(" %#X \n", -2147483647),printf(" %#X \n", -2147483647));
 	printf("----Precision test cases----\n");
	test(_printf(" %.0d \n", 0),printf(" %.0d \n", 0));
	test(_printf("%.f\n",55,OneSeventh),printf("%.*f\n",55, OneSeventh));
 	printf("----test finished----\n");
 	return (0);
 }


 void test(int len1, int len2)
 {
 	if (len1 != len2)
 	{
 		printf("error here len1=%d, len2=%d", len1, len2);
 	}
 }
