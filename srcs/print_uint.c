/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:18:10 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 20:01:22 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uint(t_specs specs, va_list *args, int baselen)
{
	int					n_chars;
	unsigned long int	arg;
	int					arg_len;

	n_chars = 0;
	fetch_next_args(&specs, args);
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
