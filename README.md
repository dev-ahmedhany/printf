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

```
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
