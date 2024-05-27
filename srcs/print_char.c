/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:32:27 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/27 16:52:47 by cnguyen-         ###   ########.fr       */
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
	The number of characters printed, or -1 if an error occured.
*/

#if defined(__APPLE__)

ssize_t	print_char(t_specs specs, va_list *args)
{
	ssize_t			n_chars;
	unsigned char	arg;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspecs(&specs);
	arg = (unsigned char)va_arg(*args, int);
	if (!specs.dash && !specs.zero && n_chars < specs.width - 1)
		if (!error(&n_chars, ft_putnchar(' ', specs.width - 1 - n_chars)))
			return (-1);
	if (specs.zero && n_chars < specs.width - 1)
		if (!error(&n_chars, ft_putnchar('0', specs.width - 1 - n_chars)))
			return (-1);
	if (!error(&n_chars, ft_putchar(arg)))
		return (-1);
	if (specs.dash && n_chars < specs.width)
		if (!error(&n_chars, ft_putnchar(' ', specs.width - n_chars)))
			return (-1);
	return (n_chars);
}

#else

long	print_char(t_specs specs, va_list *args)
{
	int				n_chars;
	unsigned char	arg;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspecs(&specs);
	arg = (unsigned char)va_arg(*args, int);
	while (!specs.dash && n_chars < specs.width - 1)
		n_chars += ft_putchar(' ');
	n_chars += ft_putchar(arg);
	while (specs.dash && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#endif