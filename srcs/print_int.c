/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:29:26 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 03:07:55 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(t_formatspec specs, va_list *args)
{
	int		n_chars;
	long	arg;
	int		uarg_len;
	int		negative;

	n_chars = 0;
	fetch_next_args(&specs, args);
	arg = (long)va_arg(*args, int);
	negative = (arg < 0);
	if (negative)
		arg *= -1;
	uarg_len = ft_uintlen(arg, 10);
	if (arg == 0 && specs.precision == 0)
		uarg_len = 0;
	n_chars += print_intprefix(specs, uarg_len, negative);
	if (arg != 0 || specs.precision != 0)
		n_chars += ft_putuint(arg, 10);
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}
