/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:33:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 03:26:07 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#if defined(__APPLE__)

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
	if (specs.precision > -1 && strlen > specs.precision)
		strlen = specs.precision;
	while (!specs.dash && !specs.zero && n_chars < specs.width - strlen)
		n_chars += ft_putchar(' ');
	while (specs.zero && n_chars < specs.width - strlen)
		n_chars += ft_putchar('0');
	offset = n_chars;
	while (*str && n_chars - offset < strlen)
		n_chars += ft_putchar(*str++);
	while (specs.dash && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#else

int	print_str(t_formatspec specs, va_list *args)
{
	int		n_chars;
	char	*str;
	int		strlen;
	int		offset;

	n_chars = 0;
	fetch_next_args(&specs, args);
	str = va_arg(*args, char *);
	if (!str && (specs.precision == -1 || specs.precision > 6))
		str = "(null)";
	else if (!str)
		str = "";
	strlen = (int)ft_strlen(str);
	if (specs.precision > -1 && strlen > specs.precision)
		strlen = specs.precision;
	while (!specs.dash && n_chars < specs.width - strlen)
		n_chars += ft_putchar(' ');
	offset = n_chars;
	while (*str && n_chars - offset < strlen)
		n_chars += ft_putchar(*str++);
	while (specs.dash && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#endif
