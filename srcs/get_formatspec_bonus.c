/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formatspec_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 05:33:18 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 03:07:19 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*read_flags(const char *format, t_formatspec *specs)
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
	if (specs->dash == 1 && specs->zero == 1)
		specs->zero = 0;
	if (specs->plus == 1 && specs->blank == 1)
		specs->blank = 0;
	return (format);
}

static const char	*read_width(const char *format, t_formatspec *specs)
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

static const char	*read_precision(const char *format, t_formatspec *specs)
{
	if (*format == '.')
	{
		specs->precision = 0;
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
				specs->precision = -1;
				specs->n_chars += 1;
				format++;
			}
			else
				specs->precision = ft_atoi_digits(format);
			specs->n_chars += ft_nbrlen(format);
			format += ft_nbrlen(format);
		}
	}
	return (format);
}

#if defined(__APPLE__)

t_formatspec	get_formatspec(const char *format)
{
	t_formatspec	specs;

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
	if (specs.specifier && specs.precision > -1
		&& ft_strchr("diuxX", specs.specifier))
		specs.zero = 0;
	return (specs);
}

#else

t_formatspec	get_formatspec(const char *format)
{
	t_formatspec	specs;
	const char		*read;

	init_formatspec(&specs);
	read = ++format;
	read = read_flags(read, &specs);
	read = read_width(read, &specs);
	read = read_precision(read, &specs);
	if (*read && ft_strchr(SPECIFIERS, *read))
	{
		specs.specifier = *read;
		specs.n_chars += 1;
	}
	else if (*read)
	{
		specs.specifier = *format;
		specs.n_chars = 1;
	}
	if (specs.specifier && specs.precision > -1
		&& ft_strchr("diuxX", specs.specifier))
		specs.zero = 0;
	return (specs);
}

#endif
