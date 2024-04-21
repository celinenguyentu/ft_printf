/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unknown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:14:49 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 20:02:13 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#if defined(__APPLE__)

int	print_unknown(t_specs specs)
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

int	print_unknown(t_specs specs)
{
	return (ft_putchar('%') + ft_putchar(specs.specifier));
}

#endif
