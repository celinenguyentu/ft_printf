/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:33:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/30 02:39:45 by cnguyen-         ###   ########.fr       */
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
	The number of characters printed as an int.
*/

#if defined(__APPLE__)

int	print_str(t_specs specs, va_list *args)
{
	int		n_chars;
	char	*str;
	int		strlen;
	int		offset;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspec(&specs);
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	strlen = (int)ft_strlen(str);
	if (specs.precision > -1 && strlen > specs.precision)
		strlen = specs.precision;
	while (!specs.dash && !specs.zero && n_chars < specs.width - strlen)
		n_chars += ft_putchar(' ');
	while (specs.zero && n_chars < specs.width - strlen)
		n_chars += ft_putchar('0');
	offset = n_chars;
	while (*str && n_chars - offset < strlen)
		n_chars += ft_putchar(*str++);
	while (specs.dash && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#else

int	print_str(t_specs specs, va_list *args)
{
	int		n_chars;
	char	*str;
	int		strlen;
	int		offset;

	n_chars = 0;
	fetch_star_args(&specs, args);
	clean_formatspec(&specs);
	str = va_arg(*args, char *);
	if (!str && (specs.precision == -1 || specs.precision >= 6))
		str = "(null)";
	else if (!str)
		str = "";
	strlen = (int)ft_strlen(str);
	if (specs.precision > -1 && strlen > specs.precision)
		strlen = specs.precision;
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
