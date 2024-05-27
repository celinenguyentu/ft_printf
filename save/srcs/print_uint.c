/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:18:10 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 17:29:41 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_UINT
	Retrieves the unsigned int argument to convert for output from the va_list
	args as well as optional arguments specifying width and precision, and
	prints the formatted argument to standart output according to the conversion
	specification provided as input and potentially updated by
	fetch_star_args() and clean_formatspec().
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	3.	The base length used for integer conversion
	RETURN
	The number of characters printed as a long.
*/

long	print_uint(t_specs specs, va_list *args, int baselen)
{
	long			n_chars;
	unsigned int	arg;
	int				arg_len;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspecs(&specs);
	arg = va_arg(*args, unsigned int);
	arg_len = ft_uintlen(arg, baselen);
	if (arg == 0 && specs.precis == 0)
		arg_len = 0;
	specs.precis = check_precis_overflow(specs.precis, arg_len);
	if (specs.specif == 'o' && specs.hash && (arg != 0 || specs.precis == 0))
		arg_len++;
	n_chars += print_intprefix(specs, arg_len, (arg != 0));
	if (arg != 0 || specs.precis != 0)
		n_chars += ft_putuint(arg, specs.specif);
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}
