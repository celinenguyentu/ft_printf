/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:29:26 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 17:28:56 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_INT
	Retrieves the int argument to convert for output from the va_list args as
	well as optional arguments specifying width and precision, and prints the
	formatted argument to standart output according to the conversion
	specification provided as input and potentially updated by
	fetch_star_args() and clean_formatspec().
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN
	The number of characters printed as a long.
*/

long	print_int(t_specs specs, va_list *args)
{
	long	n_chars;
	long	arg;
	int		uarg_len;
	int		sign;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspecs(&specs);
	arg = (long)va_arg(*args, int);
	sign = (arg < 0) * -1 + (arg == 0) * 0 + (arg > 0) * 1;
	if (sign == -1)
		arg *= -1;
	uarg_len = ft_uintlen(arg, 10);
	if (arg == 0 && specs.precis == 0)
		uarg_len = 0;
	specs.precis = check_precis_overflow(specs.precis, uarg_len);
	n_chars += print_intprefix(specs, uarg_len, sign);
	if (arg != 0 || specs.precis != 0)
		n_chars += ft_putuint(arg, specs.specif);
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}
