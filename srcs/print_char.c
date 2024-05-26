/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:32:27 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 13:59:26 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_CHAR
	Retrieves the char argument to convert for output from the va_list args as
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

#if defined(__APPLE__)

long	print_char(t_specs specs, va_list *args)
{
	int				n_chars;
	unsigned char	arg;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspec(&specs);
	arg = (unsigned char)va_arg(*args, int);
	while (!specs.dash && !specs.zero && n_chars < specs.width - 1)
		n_chars += ft_putchar(' ');
	while (specs.zero && n_chars < specs.width - 1)
		n_chars += ft_putchar('0');
	n_chars += ft_putchar(arg);
	while (specs.dash && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#else

long	print_char(t_specs specs, va_list *args)
{
	int				n_chars;
	unsigned char	arg;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspec(&specs);
	arg = (unsigned char)va_arg(*args, int);
	while (!specs.dash && n_chars < specs.width - 1)
		n_chars += ft_putchar(' ');
	n_chars += ft_putchar(arg);
	while (specs.dash && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#endif