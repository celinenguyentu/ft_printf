/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:39:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/29 22:08:53 by cnguyen-         ###   ########.fr       */
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
	long	precis = -2147483657;
	
//LONG_MAX
	//tests("  %.-2147483651d", 2);
	//tests("|%*s|%*s|%-*s|%0*s|%6.*s|%*.*s|%*.*s|%*s|%*s|%-*s|%0*s|%6.*s|%*.*s|%*.*s|", 6, "hello", -6, "hello", 6, "hello", -6, "hello", 4, "hello", 6, 4, "hello", 6, -4, "hello", 6, NULL, -6, NULL, 6, NULL, -6, NULL, 4, NULL, 6, 4, NULL, 6, -4, NULL);
	//bytes_written = ft_printf("%.*d", 4, 42);
	//printf("\t(%d)\n", bytes_written);
	//printf("%d", max);
	//ft_printf("|%s-2.10d-sd|", 11);
	return (0);
}