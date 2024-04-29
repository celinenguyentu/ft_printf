/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:29:26 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/28 23:04:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_int(t_specs specs, va_list *args)
{
	int		n_chars;
	long	arg;
	int		uarg_len;
	int		negative;

	n_chars = 0;
	fetch_next_args(&specs, args);
	clean_formatspec(&specs);
	arg = (long)va_arg(*args, int);
	negative = (arg < 0);
	if (negative)
		arg *= -1;
	uarg_len = ft_uintlen(arg, 10);
	if (arg == 0 && specs.precision == 0)
		uarg_len = 0;
	n_chars += print_intprefix(specs, uarg_len, negative, (arg == 0));
	if (arg != 0 || specs.precision != 0)
		n_chars += ft_putuint(arg, specs.specifier);
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}
