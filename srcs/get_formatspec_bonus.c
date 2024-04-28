/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formatspec_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 05:33:18 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/28 06:16:12 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*read_flags(const char *format, t_specs *specs)
{
	char	flag;

	while (*format && ft_strchr(FLAGS, *format))
	{
		flag = *ft_strchr(FLAGS, *format);
		if (flag == '-')
			specs->dash = 1;
		else if (flag == '0')
			specs->zero = 1;
		else if (flag == '#')
			specs->hash = 1;
		else if (flag == ' ')
			specs->blank = 1;
		else
			specs->plus = 1;
		format++;
		specs->n_chars += 1;
	}
	return (format);
}

static const char	*read_width(const char *format, t_specs *specs)
{
	if (*format == '*')
	{
		specs->star_width = 0;
		specs->n_chars += 1;
		format++;
	}
	else
	{
		specs->width = ft_atoi_digits(format);
		specs->n_chars += ft_nbrlen(format);
		format += ft_nbrlen(format);
	}
	return (format);
}

#if defined(__APPLE__)

static const char	*read_precision(const char *format, t_specs *specs)
{
	if (*format == '.')
	{
		specs->n_chars += 1;
		if (*++format == '*')
		{
			specs->star_precision = 0;
			specs->n_chars += 1;
			format++;
		}
		else
		{
			if (*format == '-')
			{
				specs->precision = 0;
				format = read_flags(format, specs);
				specs->width = ft_atoi_digits(format);
			}
			else
				specs->precision = ft_atoi_digits(format);
			specs->n_chars += ft_nbrlen(format);
			format += ft_nbrlen(format);
		}
	}
	return (format);
}

#else

static const char	*read_precision(const char *format, t_specs *specs)
{
	if (*format == '.')
	{
		specs->n_chars += 1;
		if (*++format == '*')
		{
			specs->star_precision = 0;
			specs->n_chars += 1;
			format++;
		}
		else
		{
			specs->precision = ft_atoi_digits(format);
			specs->n_chars += ft_nbrlen(format);
			format += ft_nbrlen(format);
		}
	}
	return (format);
}

#endif

t_specs	get_formatspec(const char *format)
{
	t_specs	specs;

	init_formatspec(&specs);
	format++;
	format = read_flags(format, &specs);
	format = read_width(format, &specs);
	format = read_precision(format, &specs);
	if (*format)
	{
		specs.specifier = *format;
		specs.n_chars += 1;
	}
	clean_formatspec(&specs);
	return (specs);
}
