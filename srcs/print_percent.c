/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:34:05 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/29 15:36:29 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#if defined(__APPLE__)

int	print_percent(t_specs specs, va_list *args)
{
	int	n_chars;

	n_chars = 0;
	fetch_next_args(&specs, args);
	clean_formatspec(&specs);
	while (!specs.dash && !specs.zero && n_chars < specs.width - 1)
		n_chars += ft_putchar(' ');
	while (specs.zero && n_chars < specs.width - 1)
		n_chars += ft_putchar('0');
	n_chars += ft_putchar('%');
	while (specs.dash && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#else

int	print_percent(t_specs specs, va_list *args)
{
	fetch_next_args(&specs, args);
	return (ft_putchar('%'));
}

#endif