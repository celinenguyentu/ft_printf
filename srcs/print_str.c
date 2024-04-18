/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:33:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/18 14:33:27 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(t_formatspec specs, va_list *args)
{
	int		n_chars;
	char	*str;
	int		strlen;
	int		offset;

	n_chars = 0;
	fetch_next_args(&specs, args);
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	strlen = (int)ft_strlen(str);
	if (specs.precision && strlen > specs.precision_n)
		strlen = specs.precision_n;
	while (specs.flags.dash == 0 && specs.width - strlen > n_chars)
		n_chars += ft_putchar(' ');
	offset = n_chars;
	while (*str && n_chars - offset < strlen)
		n_chars += ft_putchar(*str++);
	while (specs.flags.dash == 1 && specs.width - n_chars > 0)
		n_chars += ft_putchar(' ');
	return (n_chars);
}
