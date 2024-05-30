/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:39:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/30 14:48:41 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "ft_printf.h"

void	tests(const char *format, ...)
{
	int	count;
	va_list	ap_og;
	va_list ap_ft;
	
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
	int		bytes_written;
	char 	*s = "hello";
	int		n = 42;
	int		i = 2147483649;

	//bytes_written = ft_printf("%*p", 2147483648, 0xabababF);
	//doesn't work on Linux mine returns error and the real prints 2147483648 characters (maybe store width in a long ?)
	//bytes_written = ft_printf("%.2147483647p", 0xabababF);
	//doesn't work on Linux (pb only with %p) mine prints the right amount of characters, the real printf prints double 
	
	//printf("\t(%d)\n", bytes_written);

	return (0);
}