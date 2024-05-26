/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:46:18 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 18:32:27 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>


void	tests(const char *format, ...)
{
	int	count;
	va_list	ap;
	
	count = 0;
	va_start(ap, format);
	printf("printf:\t\t"); count = vprintf(format, ap);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf :\t"); count = ft_vprintf(format, ap);
	printf("\t(%d)\n", count);
	va_end(ap);
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
	void		*p = NULL;

	printf("Positional arguments with %%n$ and *n$ ...\n\n");

	printf("Edge cases");
	printf("Mixing positional and non positional arguments");
	printf("Gaps in the number of arguments");
	printf("Higher number of argument than actual arguments");
	printf("Invalid position for argument (negative or zero)")

	//count = printf("%3$-*1$c__%4$*3$c__%6$*5$c\n", 2, 'a', 3, 'b', 4, 'c');
	//count = printf("%3$-*2$c__%3$*2$c__%3$*2$c__%1$*4$c\n", 'b', 2, 'a', 4);

	return (0);
}