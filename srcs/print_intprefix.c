/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intprefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:18:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 03:08:04 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_intprefix(t_formatspec specs, int uarg_len, int negative)
{
	int	n_chars;
	int	n_zeros;
	int	offset;

	n_chars = 0;
	n_zeros = 0;
	if (specs.precision > -1 && uarg_len < specs.precision)
		n_zeros = specs.precision - uarg_len;
	offset = uarg_len + negative + n_zeros;
	if (!negative && (specs.blank || specs.plus))
		offset += 1;
	while (!specs.dash && !specs.zero && n_chars < specs.width - offset)
		n_chars += ft_putchar(' ');
	if (negative)
		n_chars += ft_putchar('-');
	if (!negative && specs.blank)
		n_chars += ft_putchar(' ');
	if (!negative && specs.plus)
		n_chars += ft_putchar('+');
	while ((specs.zero && specs.width - uarg_len > n_chars) || n_zeros--)
		n_chars += ft_putchar('0');
	return (n_chars);
}
