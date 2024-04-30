/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:21:41 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/30 01:17:55 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_ARG
	For each conversion specification, this function calls the appropriate
	conversion function to print the next argument from the va_list args, and
	captures the number of characters printed that it returns.
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN
	The number of characters printed as an int.
*/

int	print_arg(t_specs specs, va_list *args)
{
	int	n_chars;

	n_chars = 0;
	if (specs.specifier == 'c')
		n_chars += print_char(specs, args);
	else if (specs.specifier == 's')
		n_chars += print_str(specs, args);
	else if (specs.specifier == 'p')
		n_chars += print_ptr(specs, args);
	else if (specs.specifier == 'd' || specs.specifier == 'i')
		n_chars += print_int(specs, args);
	else if (specs.specifier == 'u')
		n_chars += print_uint(specs, args, 10);
	else if (specs.specifier == 'x' || specs.specifier == 'X')
		n_chars += print_uint(specs, args, 16);
	else if (specs.specifier == '%')
		n_chars += print_percent(specs, args);
	else if (specs.specifier == 'o')
		n_chars += print_uint(specs, args, 8);
	else
		n_chars += print_unknown(specs, args);
	return (n_chars);
}
