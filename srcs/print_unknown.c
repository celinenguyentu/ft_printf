/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unknown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:14:49 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/27 16:55:10 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_UNKNOWN
	Retrieves the optional arguments specifying width and precision from the
	va_list args, and prints the formatted regular character stored as unknown
	specifier to standart output according to the conversion specification
	provided as input and potentially updated by fetch_star_args() and
	clean_formatspec().
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN
	The number of characters printed or -1 if an error occured.
*/

#if defined(__APPLE__)

ssize_t	print_unknown(t_specs specs, va_list *args)
{
	ssize_t	n_chars;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspecs(&specs);
	if (!specs.dash && !specs.zero && n_chars < specs.width - 1)
		if (!error(&n_chars, ft_putnchar(' ', specs.width - 1 - n_chars)))
			return (-1);
	if (specs.zero && n_chars < specs.width - 1)
		if (!error(&n_chars, ft_putnchar('0', specs.width - 1 - n_chars)))
			return (-1);
	if (!error(&n_chars, ft_putchar(specs.specif)))
		return (-1);
	if (specs.dash && n_chars < specs.width)
		if (!error(&n_chars, ft_putnchar(' ', specs.width - n_chars)))
			return (-1);
	return (n_chars);
}

#else

long	print_unknown(t_specs specs, va_list *args)
{
	int	n_chars;

	fetch_star_args(&specs, args);
	n_chars = 0;
	n_chars += ft_putchar('%');
	if (specs.hash)
		n_chars += ft_putchar('#');
	if (specs.plus)
		n_chars += ft_putchar('+');
	if (specs.blank)
		n_chars += ft_putchar(' ');
	if (specs.dash)
		n_chars += ft_putchar('-');
	if (specs.zero)
		n_chars += ft_putchar('0');
	if (specs.width)
		n_chars += ft_putuint(specs.width, 'i');
	if (specs.precis > -1)
		n_chars += ft_putchar('.') + ft_putuint(specs.precis, 'i');
	if (specs.specif)
		n_chars += ft_putchar(specs.specif);
	return (n_chars);
}

#endif
