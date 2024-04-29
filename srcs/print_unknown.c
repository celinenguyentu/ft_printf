/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unknown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:14:49 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/29 04:25:39 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#if defined(__APPLE__)

int	print_unknown(t_specs specs, va_list *args)
{
	int	n_chars;

	n_chars = 0;
	while (!specs.dash && !specs.zero && n_chars < specs.width - 1)
		n_chars += ft_putchar(' ');
	while (specs.zero && n_chars < specs.width - 1)
		n_chars += ft_putchar('0');
	n_chars += ft_putchar(specs.specifier);
	while (specs.dash && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#else

int	print_unknown(t_specs specs, va_list *args)
{
	int	n_chars;

	fetch_next_args(&specs, args);
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
	if (specs.precision > -1)
		n_chars += ft_putchar('.') + ft_putuint(specs.precision, 'i');
	if (specs.specifier)
		n_chars += ft_putchar(specs.specifier);
	return (n_chars);
}

#endif
