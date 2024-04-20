/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:21:41 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/19 20:17:47 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(t_formatspec specs, va_list *args)
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
		n_chars += print_uint(specs, args);
	else if (specs.specifier == 'x' || specs.specifier == 'X')
		n_chars += print_xint(specs, args);
	else if (specs.specifier == '%')
		n_chars += print_percent(specs, args);
	else
		n_chars += print_unknown(specs);
	return (n_chars);
}
