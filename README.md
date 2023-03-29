# Printf

This project is an implementation of the [`printf`](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm) function in the __C__ standard libray.

## How To Use

The `main.h` header must be included before you can use the function. The `_printf` function returns the number of characters that were printed to stdout.

```c
#include "main.h"

int main(void)
{
  int n = _printf("Wind: %d%s and Precipitation: %d%%\\n", 28, "km/h", 0x1a);

  return (0);
}
```

### The Format Specifier Pattern

The format specifier uses the following pattern:

```bash
%[flag][width][.precision][length]specifier
```

The fields in brackets are optional, a spec must be provided, and the fields must appear in the same order as the pattern provided above. If a spec isn't provided (or the format specifier is invalid) and the format specifier is at the end of the format string an error occurs. On the contrary, if the spec isn't provided (or the format specifier is invalid) and the format specifier is not at the end of the string, the raw invalid format specifier is printed as is.

### Supported Flags

| Flag | Description |
|:---:|:---|
| # | The value should be converted to an alternate form. |
| 0 | The value should be padded with zeros rather than spaces. |
| - | The output should be left-aligned on the field boundary since the default is right-alignment on the field boundary. |
| ' ' | (a space) A blank space should be left before a positive number that is produced by a sign conversion. |
| + | A sign (+ or -) should always be placed before a number produced by a signed conversion. By default only the signs of negative numbers are shown. |

### Width And Precision

The width and precision fields can be provided as integers beginning with a non-zero digit. They can also be specified with the `*` sign. If they're specified with the `*` sign, the value is read from the argument list provided to `_printf`. The maximum value of the width and precision fields is `2147483647`.

### Supported Length Modifiers

| Length | Description |
|:---:|:---|
| h | Modifies the integer to be a short signed or unsigned integer |
| l | Modifies the integer to be a long signed or unsigned integer|

### Supported Conversion Specifiers

| Specifier | Description |
|:---:|:---|
| c | Prints the ASCII character representation of an integer. |
| s | Prints the characters of a `char *` that is terminated by a null character (`\0`). |
| d, i | Prints the signed decimal notation of an integer argument. |
| f | Prints the signed decimal notation of an IEEE 754 floating-point argument. |
| o, u, x, X | Prints the unsigned int argumen in unsigned octal notation (o), decimal notation (u) or hexadecimal notation (x and X). x uses lower-case hexadecimal characters and X uses the upper-case hexadecimal characters. |
| % | Prints the "%" sign only. |
| p | Prints a `void *` argument in hexadecimal form. |
| b | Prints the binary representation of an unsigned integer. |
| R | Prints the rot13 translation of a string. |
| r | Prints the reverse of a string. |
| S | Prints a string and the hexadecimal representation of unprintable characters (prefixed with `\x`) in a string that is null terminated. |

### Examples

1. `_printf("%.2f\n", -3.46);` produces `-3.46`.
2. `_printf("%#x\n", 478);` produces `0x1de`.
3. `_printf("%R\n", "foobar");` produces `sbbone`.
4. `_printf("%r\n", "foo")` produces `oof`.

## Tasks

### 0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life

Write a function that produces output according to a format.

Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
You don’t have to reproduce the buffer handling of the C library printf function
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers

### 1. Education is when you read the fine print. Experience is what you get if you don't

Handle the following conversion specifiers:

d
i
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers

### 2. With a face like mine, I do better in print

Handle the following custom conversion specifiers:

b: the unsigned int argument is converted to binary

```bash
alex@ubuntu:~/c/printf$ cat main.c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%b\n", 98);
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
alex@ubuntu:~/c/printf$ ./a.out
1100010
alex@ubuntu:~/c/printf$
```

### 3. What one has not experienced, one will never understand in print

Handle the following conversion specifiers:

u
o
x
X
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers

### 4. Nothing in fine print is ever good news

Use a local buffer of 1024 chars in order to call write as little as possible.

### 5. My weakness is wearing too much leopard print

Handle the following custom conversion specifier:

S : prints the string.
Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

```bash
alex@ubuntu:~/c/printf$ cat main.c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%S\n", "Best\nSchool");
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
alex@ubuntu:~/c/printf$ ./a.out
Best\x0ASchool
alex@ubuntu:~/c/printf$
```

### 6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print

Handle the following conversion specifier: p.

You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers

### 7. The big print gives and the small print takes away

Handle the following flag characters for non-custom conversion specifiers:

> `+`
> space
> `#`

### 8. Sarcasm is lost in print

Handle the following length modifiers for non-custom conversion specifiers:

l
h
Conversion specifiers to handle: d, i, u, o, x, X

### 9. Print some money and give it to us for the rain forests

Handle the field width for non-custom conversion specifiers.

Repo:

GitHub repository: printf

### 10. The negative is the equivalent of the composer's score, and the print the performance

Handle the precision for non-custom conversion specifiers.

Repo:

GitHub repository: printf

### 11. It's depressing when you're still around and your albums are out of print

Handle the 0 flag character for non-custom conversion specifiers.

Repo:

GitHub repository: printf

### 12. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection

Handle the - flag character for non-custom conversion specifiers.

Repo:

GitHub repository: printf

### 13. Print is the sharpest and the strongest weapon of our party

Handle the following custom conversion specifier:

r : prints the reversed string

### 14. The flood of print has turned reading into a process of gulping rather than savoring

Handle the following custom conversion specifier:

R: prints the rot13'ed string

### 15. *

All the above options work well together.
