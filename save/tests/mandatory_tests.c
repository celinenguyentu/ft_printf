/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:21:58 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/24 20:48:21 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

void	tests(const char *format, ...)
{
	int	count;
	va_list	ap_og;
	va_list	ap_ft;
	
	count = 0;
	va_start(ap_og, format);
	va_start(ap_ft, format);
	printf("printf:\t\t"); count = vprintf(format, ap_og);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf :\t"); count = ft_vprintf(format, ap_ft);
	printf("\t(%d)\n", count);
	va_end(ap_og);
	va_end(ap_ft);
}

int	main(void)
{
	int			n = 42;
	char		c1 = CHAR_MIN;
	char		c2 = CHAR_MAX;
	char		s[] = "";
	int			i1 = INT_MIN;
	int			i2 = INT_MAX;
	unsigned	i3 = UINT_MAX;
	short		i4 = SHRT_MAX;
	long		i5 = LONG_MIN;
	long		i6 = LONG_MAX;

	float		r1 = -42.18;
	double		r2 = -42.18;
	long double	r3 = -42.18;
	void		*p = NULL;
	
	int			count = 0;
	
	printf("\nMANDATORY PART : testing basic conversions with various inputs...\n\n");
	printf(">> String only, no conversion\n");
	tests("Hello World!");
	tests("");
	printf(">> Conversion %%c : characters\n");
	tests("|%c|%c|%c|%c|%c|%c|%c|%c|%c|", 'a', n, c1, c2, *s, i1, i2, i3, i4);
	tests("|%c|%c|%c|%c|%c|", i5, i6, r1, r2, r3);
	printf(">> Conversion %%s : strings\n");
	tests("|%s|%s|", "hello", s);
	printf(">> Conversion %%p : memory addresses\n");
	tests("|%p|%p|%p|", &n, s, p);
	tests("|%p|%p|%p|%p|%p|%p|%p|%p|%p|%p|%p|%p|", n, c1, c2, i1, i2, i3, i4, i5, i6, r1, r2, r3);
	printf(">> Conversion %%d %%i : signed integers\n");
	tests("|%d|%d|%d|%d|%d|%d|%d|%d|", n, *s, i1, i2, i3, i4, 0, 2147483647);
	tests("|%d|%d|%d|%d|%d|%d|%d|%d|", s, p, i5, i6, r1, r2, r3, -2147483648);
	printf(">> Conversion %%u : unsigned integers\n");
	tests("|%u|%u|%u|%u|%u|%u|%u|%u|%u|", n, *s, c1, c2, i1, i2, i3, i4, 0);
	tests("|%u|%u|%u|%u|%u|%u|%u|", s, p, i5, i6, r1, r2, r3);
	printf(">> Conversion %%x %%X : unsigned hexadecimal integers\n");
	tests("|%x|%x|%x|%x|%x|%x|%x|%x|%x|", n, *s, c1, c2, i1, i2, i3, i4, 0);
	tests("|%X|%X|%X|%X|%X|%X|%X|%X|%X|", n, *s, c1, c2, i1, i2, i3, i4, 0);
	tests("|%x|%x|%x|%x|%x|%x|%x|", s, p, i5, i6, r1, r2, r3);
	tests("|%X|%X|%X|%X|%X|%X|%X|", s, p, i5, i6, r1, r2, r3);
	printf(">> Conversion %%%% : percent symbol\n");
	tests("|%%|");
	
	printf("\nEdge cases ...\n\n");
#if defined(__linux__) || (__gnu_linux__)
	printf(">> Format string is NULL\n");
	tests(NULL);
	tests(NULL, 'a', 42, s);
#endif
	printf(">> Unknown format specifier\n");
	tests("Hello %!");
	printf(">> %% symbol at the end of format string\n");
	tests("Hello !%");
	printf(">> Less format specifiers than arguments\n");
	tests("Hello %s !", "Marvin", 42, '%');
	printf(">> %%c conversion : argument is a string or NULL\n");
	tests("|%c|%c|%c|", 'C', "Marvin", NULL);
	printf(">> %%s conversion : argument is NULL\n");
	tests("Hello %s !", NULL);
	printf(">> %%p conversion : argument is NULL\n");
	tests("|%p|", NULL);
	printf(">> %%p conversion : argument is an int\n");
	tests("|%p|%p|", n, 42);
	tests("|%p|", n);
	tests("|%p|", 42);
	
	printf("\nVerifying flags exclusions ...\n\n");
	ft_printf("%%-15p :\t"); count = ft_printf("|%-15p|", NULL);
	printf("\t(%d)\n", count);
	ft_printf("%%015u :\t"); count = ft_printf("|%015u|", 42);
	printf("\t(%d)\n", count);
	ft_printf("%%#x :\t"); count = ft_printf("|%#x|", 42);
	printf("\t(%d)\n", count);
	ft_printf("%% d :\t"); count = ft_printf("|% d|", 42);
	printf("\t(%d)\n", count);
	ft_printf("%%+i :\t"); count = ft_printf("|%+i|", 42);
	printf("\t(%d)\n", count);
	ft_printf("%%10c :\t"); count = ft_printf("|%10c|", 'a');
	printf("\t(%d)\n", count);
	ft_printf("%%.10s :\t"); count = ft_printf("|%.10s|", "abcdefghijklmnop");
	printf("\t(%d)\n", count);
	ft_printf("%%*.*d :\t"); count = ft_printf("|%*.*d|", 5, 3, 1);
	printf("\t(%d)\n", count);
	return (0);
}
