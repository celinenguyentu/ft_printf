<div align="center">
  <!-- Logo -->
  <a href="https://github.com/celinenguyentu/ft_printf">
  <img src="docs/ft_printfm.png" alt="Logo" width="150" height="150">
  </a>
</div>

# ft_printf

The goal of this project is to code a library that contains a simplified version (more details below) of the printf function from `<stdio.h>`.

💡 I took the liberty of extending the project by implementing additional features and functionalities that go beyond the subject requirements. These include various specifiers and flags options, implementation-defined non-standard behaviors, and ensuring portability across macOS and Linux by mimicking both the glibc and libbsd implementations.

Grade : 125/100 \
Subjects v.10 : [`EN`](docs/ft_printf_v10.en.pdf) \
42 Norm v.4 : [`FR`](docs/norm_v4.fr.pdf) [`EN`](docs/norm_v4.en.pdf)

## Content

```c
int	ft_printf(char *format, ...)
```
Formats and prints in the standard ouput its arguments, after the first, under control of the string format. The format string may contain format specifications, each of which causes printing of the next successive argument. Each format specification is introduced by the percent character `%` followed by, in the following order :
- Zero or more flags among the following : `#0- +`
- An optional digit string specifying a field width
- An optional period `.` followed by an optional digit string giving a precision.
- A format specifier of type char which indicates the type of format to use among the following : `cspdiuxX%o`

A field width or precision may be `*` instead of a digit string. In this case an argument supplies the field width or precision. \
**Parameter(s)** : \
`format` - the format string to control the output \
`...` - a variable number of arguments used and converted for output \
**Return value** : \
The function returns the number of characters printed in the standard output, excluding the null-terminating `\0` character of the format string. In case of error, it returns -1.

```c
int	ft_vprintf(const char *format, va_list ap)
```
The function ft_vprintf() is equivalent to the function ft_printf() except that it is called with a va_list instead of a variable number of arguments. \
**Parameter(s)** : \
`format` - the format string to control the output \
`ap` - the va_list storing the variable-length list of arguments used and converted for output \
**Return value** : \
The function returns the number of characters printed in the standard output, excluding the null-terminating `\0` character of the format string. In case of error or overflow, it returns -1.

Format specification supports several format specifiers as well as options including flags, width and precision. They can be used as followed :
```
% [ flags ][ witdh ][ .precision ] specifier
```
| Specifier | Description                                                                                        |
|-----------|----------------------------------------------------------------------------------------------------|
| c         | Print a single character.                                                                          |
| s         | Print a string of characters.                                                                      |
| p         | The void * pointer argument is printed in hexadecimal.                                             |
| d or i    | Print a decimal (base 10) representation of a signed integer.                                      |
| u         | Print a decimal (base 10) representation of an unsigned integer.                                   |
| x or X    | Print a hexadecimal (base 16) representation, with lowercase or uppercase, of an unsigned integer. |
| o         | Print an octal (base 8) representation of an unsigned integer.                                     |
| %         | Print a percent `%` sign.                                                                          |

| Flag  | Description                                                                                        |
|-------|----------------------------------------------------------------------------------------------------|
| -     | Left justify the result within the field. By default it is right justified.                        |
| 0     | Leading zeros are used to pad the numbers instead of space.                                        |
| +     | Forces to precede the result with a plus or minus sign (`+` or `-`) even for positive numbers. By default, only negative numbers are preceded with a sign.     |
|(space)| If there is no sign, a space is attached to the beginning of the result.                           |
| #     | Used with x or X specifiers the value is preceded with `0x` or `0X` respectively for values different than zero. For o conversions, the first character of the output string is made zero (by prefixing a `0` if it was not zero already).    |

| Width    | Description                                                                                        |
|----------|----------------------------------------------------------------------------------------------------|
| <number> | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.                        |
| *        | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                        |

| Precision | Description                                                                                        |
|-----------|----------------------------------------------------------------------------------------------------|
| .<number> | For integer specifiers (d, i, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed.                       |
| .*        | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                  |

For futher details on the formatting options of printf, please refer to the [man page](https://man7.org/linux/man-pages/man3/printf.3.html).

## Usage

### Requirements

This project is written in C language and need either gcc or clang compiler, with `<stdlib.h>`, `<stdarg.h>` and `<unistd.h>` standard libraries to run.

### Compilation

* `make`or `make all` - compile library libftprintf.a without bonus options
* `make bonus` - compile library libftprintf.a with bonus options
* `make clean` - remove all object files
* `make fclean` - remove all object files and library libftprintf.a
* `make re` - remove all object files and library libftprintf.a, and recompile library without bonus

### Import library

After compiling the library libftprintf.a, include the header in your code :
```c
#include "ft_printf.h"
```
Compile your `main.c` code using
```
[ gcc | clang | cc ] main.c -I path/to/ft_printf.h -L path/to/libftprintf.a -lftprintf
```
Alternatively, if your `main.c` file is located at the root of this repository :

```bash
[ gcc | clang | cc ] main.c -I includes libftprintf.a
```

### Example

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello%-7sof%+*d%03c\n", "World", 5, 42, '!');
	ft_printf("Weird%013s%#+02-!%+0p%03", "sequence", NULL);
	return (0);
}
```
Output on Linux
```
HelloWorld  of  +42  !
Weird     sequence%#+02-!(nil)%03
```
Output on macOS
```
HelloWorld  of  +4200!
Weird00000sequence! 0x0
```

## Testers

I recommend you to code your own tests. It is not only an important part of the learning process but also allows to run thorough tests that might not be included in other people's testers and making sure your ft_printf mimicks the behaviour of the printf implemented on your machine.

I have coded a basic program to test your ft_printf against the one in your libc. It contains test cases that will not be tested by the Moulinette or most third-party testers. Please find it in this repository : [ft_printfTest](https://github.com/celinenguyentu/ft_printfTest). 

Those are third-party tester to run complementary tests, use them at your own risk :

* @Tripouille [printfTester](https://github.com/Tripouille/printfTester)
* @cacharle [ft_printf_test](https://github.com/cacharle/ft_printf_test)
* @paulo-santana [ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)
* @xicodomingues [francinette](https://github.com/xicodomingues/francinette)
* @gavinfielder [pft](https://github.com/gavinfielder/pft.git)