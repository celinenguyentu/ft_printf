/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 05:33:18 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/15 07:59:51 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_formatspec(t_formatspec *specs)
{
	specs->flags = (t_flags){0, 0, 0, 0, 0};
	specs->width = 0;
	specs->precision = 0;
	specs->precision_n = 0;
	specs->specifier = 0;
	specs->n_chars = 0;
}

const char	*read_flags(const char *format, t_formatspec *specs)
{
	char	flag;

	while (*format && ft_strchr("-0# +", *format))
	{
		flag = *ft_strchr("-0# +", *format);
		if (flag == '-')
			specs->flags.dash = 1;
		else if (flag == '0')
			specs->flags.zero = 1;
		else if (flag == '#')
			specs->flags.hash = 1;
		else if (flag == ' ')
			specs->flags.blank = 1;
		else
			specs->flags.plus = 1;
		format++;
		specs->n_chars += 1;
	}
	if (specs->flags.dash == 1 && specs->flags.zero == 1)
		specs->flags.zero = 0;
	if (specs->flags.plus == 1 && specs->flags.blank == 1)
		specs->flags.blank = 0;
	return (format);
}

const char	*read_width(const char *format, t_formatspec *specs)
{
	if (*format == '*')
	{
		specs->width = -1;
		specs->n_chars += 1;
		format++;
	}
	else
	{
		specs->width = ft_atoi(format);
		specs->n_chars += ft_nbrlen(format);
		format += ft_nbrlen(format);
	}
	return (format);
}

const char	*read_precision(const char *format, t_formatspec *specs)
{
	if (*format == '.')
	{
		specs->precision = 1;
		specs->n_chars += 1;
		if (*++format == '*')
		{
			specs->precision_n = -1;
			specs->n_chars += 1;
			format++;
		}
		else
		{
			if (*format == '-')
			{
				specs->precision = 0;
				specs->n_chars += 1;
				format++;
			}
			specs->precision_n = ft_atoi(format);
			specs->n_chars += ft_nbrlen(format);
			format += ft_nbrlen(format);
		}
	}
	return (format);
}

t_formatspec	get_formatspec(const char *format)
{
	t_formatspec	specs;

	init_formatspec(&specs);
	format++;
	format = read_flags(format, &specs);
	format = read_width(format, &specs);
	format = read_precision(format, &specs);
	if (*format && ft_strchr("cspdiuxX%", *format))
	{
		specs.specifier = *format;
		specs.n_chars += 1;
	}
	if (specs.specifier && specs.precision
		&& ft_strchr("diuxX", specs.specifier))
		specs.flags.zero = 0;
	return (specs);
}
