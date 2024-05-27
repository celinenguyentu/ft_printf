/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:33:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/27 16:54:45 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_STR
	Retrieves the string argument to convert for output from the va_list args
	as well as optional arguments specifying width and precision, and prints
	the formatted argument to standart output according to the conversion
	specification provided as input and potentially updated by
	fetch_star_args() and clean_formatspec().
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN
	The number of characters printed or -1 if an error occured.
*/

#if defined(__APPLE__)

ssize_t	print_str(t_specs specs, va_list *args)
{
	ssize_t	n_chars;
	char	*str;
	ssize_t	arglen;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspecs(&specs);
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	arglen = (ssize_t)ft_strlen(str);
	if (specs.precis > -1 && arglen > specs.precis)
		arglen = specs.precis;
	if (!specs.dash && !specs.zero && n_chars < specs.width - arglen)
		if (!error(&n_chars, ft_putnchar(' ', specs.width - arglen - n_chars)))
			return (-1);
	if (specs.zero && n_chars < specs.width - arglen)
		if (!error(&n_chars, ft_putnchar('0', specs.width - arglen - n_chars)))
			return (-1);
	if (!error(&n_chars, ft_putnstr(str, arglen)))
		return (-1);
	if (specs.dash && n_chars < specs.width)
		if (!error(&n_chars, ft_putnchar(' ', specs.width - n_chars)))
			return (-1);
	return (n_chars);
}

#else

long	print_str(t_specs specs, va_list *args)
{
	long		n_chars;
	char		*str;
	long		strlen;
	long		offset;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspecs(&specs);
	str = va_arg(*args, char *);
	if (!str && (specs.precis == -1 || specs.precis >= 6))
		str = "(null)";
	else if (!str)
		str = "";
	strlen = (long)ft_strlen(str);
	if (specs.precis > -1 && strlen > specs.precis)
		strlen = specs.precis;
	while (!specs.dash && n_chars < specs.width - strlen)
		n_chars += ft_putchar(' ');
	offset = n_chars;
	while (*str && n_chars - offset < strlen)
		n_chars += ft_putchar(*str++);
	while (specs.dash && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#endif
