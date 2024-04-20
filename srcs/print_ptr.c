/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:40:49 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 00:27:44 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#if defined(__APPLE__)

int	print_ptr(t_formatspec specs, va_list *args)
{
	int			n_chars;
	uintptr_t	address;
	int			output_len;

	n_chars = 0;
	fetch_next_args(&specs, args);
	address = (unsigned long int)va_arg(*args, void *);
	output_len = ft_uintlen(address, 16);
	while (specs.dash == 0 && specs.zero == 0 && n_chars < specs.width - output_len - 2)
		n_chars += ft_putchar(' ');
	n_chars += ft_putstr("0x");
	while (specs.zero && n_chars < specs.width - output_len)
		n_chars += ft_putchar('0');
	n_chars += ft_putuint(address, 'x');
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#else

int	print_ptr(t_formatspec specs, va_list *args)
{
	int			n_chars;
	uintptr_t	address;
	int			output_len;

	n_chars = 0;
	fetch_next_args(&specs, args);
	address = (unsigned long int)va_arg(*args, void *);
	if (address)
		output_len = ft_uintlen(address, 16) + 2;
	else
		output_len = ft_strlen(NULLPTR);
	while (specs.dash == 0 && n_chars < specs.width - output_len)
		n_chars += ft_putchar(' ');
	if (address)
		n_chars += ft_putstr("0x") + ft_putuint(address, 'x');
	else
		n_chars += ft_putstr(NULLPTR);
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#endif