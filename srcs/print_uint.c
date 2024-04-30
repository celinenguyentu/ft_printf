/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:18:10 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/30 08:21:52 by cnguyen-         ###   ########.fr       */
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
	The number of characters printed as an int.
*/

int	print_uint(t_specs specs, va_list *args, int baselen)
{
	int					n_chars;
	unsigned long int	arg;
	int					arg_len;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspec(&specs);
	arg = (unsigned long int)va_arg(*args, unsigned int);
	arg_len = ft_uintlen(arg, baselen);
	if (arg == 0 && specs.precision == 0)
		arg_len = 0;
	if (specs.specifier == 'o' && specs.hash && (arg != 0 || specs.precision == 0))
		arg_len++;
	n_chars += print_intprefix(specs, arg_len, (arg != 0));
	if (arg != 0 || specs.precision != 0)
		n_chars += ft_putuint(arg, specs.specifier);
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

/* SAVE
int	print_uint(t_specs specs, va_list *args, int baselen)
{
	int					n_chars;
	unsigned long int	arg;
	int					arg_len;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspec(&specs);
	arg = (unsigned long int)va_arg(*args, unsigned int);
	arg_len = ft_uintlen(arg, baselen);
	if (arg == 0 && specs.precision == 0)
		arg_len = 0;
	n_chars += print_intprefix(specs, arg_len, 0, (arg == 0));
	if (arg != 0 || specs.precision != 0)
		n_chars += ft_putuint(arg, specs.specifier);
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}
*/