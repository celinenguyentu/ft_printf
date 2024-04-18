/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:32:27 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/18 14:32:32 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_formatspec specs, va_list *args)
{
	int		n_chars;
	char	arg;

	n_chars = 0;
	fetch_next_args(&specs, args);
	arg = va_arg(*args, int);
	while (specs.flags.dash == 0 && n_chars < specs.width - 1)
		n_chars += ft_putchar(' ');
	n_chars += ft_putchar(arg);
	while (specs.flags.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}
