/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/10 19:29:31 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// c : single character - char
// s : string - char *
// p : address in hexadecimal- void *, char *, etc..
// d, i : integer converted to signed decimal notation -- int..
// u : unsigned integer converted to unsigned decimal notation - int..
// x, X : unsigned integer converted to unsigned hexadecimal notation - int..
// '-' : left adjusted on the fied boundary (default is right)

// '-0.’ + field minimum width
// ’# +’ 

t_formatspec get_formatspec(const char *start)
{
	t_formatspec formatspec;
	
	formatspec = (t_formatspec) {0, 0, 0, 0, 0, 0, 0, 0};
	while (start && ft_strchr("-0# +", *start))
	{
		switch (*ft_strchr("-0# +", *start))
		{
			case '-' :
				formatspec.dash = 1;
				break ;
			case '0' :
				formatspec.zero = 1;
				break ;
			case '#' :
				formatspec.hash = 1;
				break ;
			case ' ' :
				formatspec.blank = 1;
				break ;
			case '+' :
				formatspec.plus = 1;
				break ;
		}
		start++;
	}
	while (start && ft_isdigit(*start))
		formatspec.width = formatspec.width * 10 + (size_t)(*start++ - '0');
	if (start && *start == '.')
	{
		start++;
		while (start && ft_isdigit(*start))
			formatspec.precision = formatspec.precision * 10 + (size_t)(*start++ - '0');
	}
	if (start && ft_strchr("cspdiuxX", *start))
		formatspec.precision = *start;
	return (formatspec);
}

int	ft_printf(const char *format, ...)
{
	
}

/*
int	ft_printf(const char *format, ...)
{
	va_list args;
	int		count;
	
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				ft_putchar_fd(c, STDOUT_FILENO);
				count++;
			}
			if (*format == 's')
			{
				char *s = va_arg(args, char*);
				ft_putstr_fd(s, STDOUT_FILENO);
				count += ft_strlen(s);
			}
			if (*format == 'p')
			{
				void *p = va_arg(args, void *);
				ft_putadd_hex_fd(p, STDOUT_FILENO);
			}
			if (*format == 'd' || *format == 'i')
			{
				int i = va_arg(args, int);
				ft_putnbr_fd(i, STDOUT_FILENO);
			}
			if (*format == 'u')
			{
				unsigned int u = (unsigned int) - 1;
				//printf("\n%u\n", u);
				int retrieve = va_arg(args, int);
				printf("retrieve = %d\n", retrieve);
				if (retrieve < 0)
				{
					retrieve *= -1;
					printf("loop retrieve = %d\n", retrieve);
					u = u - (unsigned int)retrieve;
				}
				else
					u = retrieve;
				ft_putnbr_fd(u, STDOUT_FILENO);
			}
			if (*format == 'x')
			{
				unsigned long int x = va_arg(args, unsigned long int);
				printf("(%ld)", x);
				ft_putnbr_hexlow_fd(x, STDOUT_FILENO); 
			}
			if (*format == 'X')
			{
				unsigned long int X = va_arg(args, unsigned long int);
				ft_putnbr_hexup_fd(X, STDOUT_FILENO); 
			}
		}
		else
		{
			ft_putchar_fd(*format, STDOUT_FILENO);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}


#include <stdio.h>
#include <limits.h>
#include <float.h>

int	main(void)
{
	int			count;
	char		c1 = 'c'; // 99
	char		c2 = 42;
	char		s[] = "Hello world!";
	int			i1 = -424242;
	short		i2 = -42;
	//long		i3 = -424242;
	//long long	i4 = -424242;
	//float		r1 = -42.18;
	//double		r2 = -42.18;
	//long double	r3 = -42.18;
	void	*p = NULL;
	
	
	printf("Testing basic conversions ...\n");
	printf(">> String only, no conversion\n");
	printf("printf:\t\t"); count = printf("String with no conversion");
	printf("\t(%d)\n", count);
	ft_printf("ft_printf :\t"); count = ft_printf("String with no conversion");
	printf("\t(%d)\n", count);
	printf(">> Characters %%c\n");
	printf("printf:\t\t"); count = printf("%c\t%c\t%c\t%c", c1, c2, *s, i1);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf :\t"); count = ft_printf("%c\t%c\t%c\t%c", c1, c2, *s, i1);
	printf("\t(%d)\n", count);
	printf(">> Strings %%s\n");
	printf("printf:\t\t"); count = printf("%s\t%s", s, &c1);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf :\t"); count = ft_printf("%s\t%s", s, &c1);
	printf("\t(%d)\n", count);
	printf(">> Memory addresses %%p\n");
	printf("printf:\t\t"); count = printf("%p\t%p\t%p\t%p", &c1, s, &i1, p);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf:\t"); count = ft_printf("%p\t%p\t%p\t%p", &c1, s, &i1, p);
	printf("\t(%d)\n", count);
	printf(">> Signed integers %%d or %%i\n");
	printf("printf:\t\t"); count = printf("%d\t%d\t%d", c1, i1, i2);
	printf("\t(%d)\n", count);
	printf("printf:\t\t"); count = printf("%i\t%i\t%i", c1, i1, i2);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf:\t"); count = ft_printf("%d\t%d\t%d", c1, i1, i2);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf:\t"); count = ft_printf("%i\t%i\t%i", c1, i1, i2);
	printf("\t(%d)\n", count);
	printf(">> Unsigned integers %%u\n");
	printf("printf:\t\t"); count = printf("%u\t%u\t%u", c1, i1, i2);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf:\t"); count = ft_printf("%u\t%u\t%u", c1, i1, i2);
	printf("\t(%d)\n", count);
	printf(">> Unsigned hexadecimal integers %%x or %%X\n");
	printf("printf:\t\t"); count = printf("%x\t%x\t%x", c1, i1, i2);
	printf("\t(%d)\n", count);
	printf("printf:\t\t"); count = printf("%X\t%X\t%X", c1, i1, i2);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf:\t"); count = ft_printf("%x\t%x\t%x", c1, i1, i2);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf:\t"); count = ft_printf("%X\t%X\t%X", c1, i1, i2);
	printf("\t(%d)\n", count);

	printf("Testing single flags ...\n");
	printf(">> Flag #\n");
	printf("printf:\t\t"); count = printf("%#x\t%#x\t%#X", c1, i1, i2);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf:\t"); count = ft_printf("%#x\t%#x\t%#X", c1, i1, i2);
	printf("\t(%d)\n", count);
	printf(">> Flag ' '\n");
	printf("printf:\t\t"); count = printf("% d\t% i\t% d", c1, i1, c2);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf:\t"); count = ft_printf("% d\t% i\t% d", c1, i1, c2);
	printf("\t(%d)\n", count);
	printf(">> Flag +\n");
	printf("printf:\t\t"); count = printf("%+d\t%+i\t%+d", c1, i1, c2);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf:\t"); count = ft_printf("%+d\t%+i\t%+d", c1, i1, c2);
	printf("\t(%d)\n", count);
	// next
	printf("Testing flags combinations ...\n");
	printf(" %-10d \n", c2);
    printf(" %010d \n", c2);
    printf(" %-#10x \n", c2);  
    printf(" %#x \n", c2);
	//printf("Testing crashes ...\n");
	return (0);
}

*/