/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/29 04:22:13 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#if defined(__APPLE__)

int	ft_vprintf(const char *format, va_list ap)
{
	int		n_chars;
	t_specs	specs;

	n_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			specs = get_formatspec(format);
			format += specs.n_chars;
			if (specs.specifier)
				n_chars += print_arg(specs, &ap);
		}
		else
			n_chars += ft_putchar(*format);
		format++;
	}
	return (n_chars);
}

#else

int	ft_vprintf(const char *format, va_list ap)
{
	int		n_chars;
	t_specs	specs;
	int		n_unknowns;

	n_chars = 0;
	n_unknowns = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			specs = get_formatspec(format);
			format += specs.n_chars;
			if (specs.specifier && !ft_strchr(SPECIFIERS, specs.specifier))
				n_unknowns++;
			if (!specs.specifier && n_unknowns == 0)
				return (-1);
			n_chars += print_arg(specs, &ap);
		}
		else
			n_chars += ft_putchar(*format);
		format++;
	}
	return (n_chars);
}

#endif

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n_chars;

	va_start(ap, format);
	n_chars = ft_vprintf(format, ap);
	va_end(ap);
	return (n_chars);
}

/* SAVE

int	ft_vprintf(const char *format, va_list ap)
{
	int		n_chars;
	t_specs	specs;

	n_chars = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			specs = get_formatspec(format);
			format += specs.n_chars;
			if (specs.specifier)
				n_chars += print_arg(specs, &ap);
			else
				return (-1);
		}
		else
			n_chars += ft_putchar(*format);
		format++;
	}
	return (n_chars);
}

*/