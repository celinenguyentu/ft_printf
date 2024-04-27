/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:40:49 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/27 22:29:36 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(t_specs specs, va_list *args)
{
	int			n_chars;
	uintptr_t	address;
	int			output_len;

	fetch_next_args(&specs, args);
	n_chars = 0;
	address = (unsigned long int)va_arg(*args, void *);
	output_len = 2;
	if (address)
		output_len = ft_uintlen(address, 16) + 2;
	else if (specs.precision != 0)
		output_len = ft_strlen(NULLPTR);
	while (specs.dash == 0 && n_chars < specs.width - output_len)
		n_chars += ft_putchar(' ');
	if (address)
		n_chars += ft_putstr("0x") + ft_putuint(address, 'x');
	else if (specs.precision != 0)
		n_chars += ft_putstr(NULLPTR);
	else
		n_chars += ft_putstr("0x");
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}
