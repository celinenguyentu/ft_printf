/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:39:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/01 23:56:30 by cnguyen-         ###   ########.fr       */
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
	int		i = 0;

	// when to stop printing with overflows ?
	//bytes_written = ft_printf("o%.*d", 2147483647, 235); // 00000000000235  (-1) 2147483648 chars OK
	//bytes_written = ft_printf("aa%.*d", 2147483647, 235); // 00000000000235  (-1) 2147483649 chars OK
	//bytes_written = ft_printf("aaa%.*d", 2147483647, 235); // 00000000000235  (-1) 2147483650 chars OK
	//bytes_written = ft_printf("aaaa%.*d", 2147483647, 235); // 00000000000000  (-1) 2147483648 chars KO 00000000000235 2147483651 chars
	//bytes_written = ft_printf("aa%.*d", 2147483647, 2); // 00000000000000  (-1) 2147483648 chars KO 00000000000002 2147483649 chars
	//bytes_written = ft_printf("aa%.*d", 2147483646, 2); // 00000000000002  (-1) 2147483648 chars OK
	//bytes_written = ft_printf("aaa%.*d", 2147483646, 2); // 00000000000000  (-1) 2147483648 chars KO 00000000000002 2147483649 chars
	//bytes_written = ft_printf("aa%.*d", 2147483646, 235); // 00000000000235  (-1) 2147483648 chars OK
	//bytes_written = ft_printf("aaa%.*d", 2147483646, 235); // 00000000000235  (-1) 2147483649 chars OK 
	//bytes_written = ft_printf("aaaa%.*d", 2147483646, 235); // 00000000000235  (-1) 2147483650 chars OK
	
	//bytes_written = printf("aaa%.*o", 2147483646, 235); // 00000000000000000353 (-1) 2147483649 chars OK
	
	//bytes_written = ft_printf("aaa%*s", 2147483647, "Hello"); //   Hello (-1) 2147483650 chars OK
	//bytes_written = ft_printf("aaa%*s", 2147483647, "H"); // end empty (-1) 2147483649 chars KO    H 2147483650 chars
	//bytes_written = printf("aa%*s", 2147483647, "H"); //  end empty (-1) 2147483648 chars KO      H 2147483649 chars
	//bytes_written = ft_printf("a%*s", 2147483647, "H"); //   H (-1) 2147483648 chars OK
	
	//bytes_written = printf("aaa%*s", 2147483648, "Hello"); //OK
	//bytes_written = ft_printf("aaa%*p", 2147483648, NULL); // OK
	//bytes_written = ft_printf("aaa%*c", 2147483648, 'f'); // OK
	
	printf("\t(%d)\n", bytes_written);


	return (0);
}