/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_formatspecs_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 05:33:18 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/29 21:25:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	UPDATE_FORMATSPECS
	Parses the initial portion of the format string from the percent symbol '%'
	to either a specifier or an unknown character, including optional flags,
	width and precision. It stores the conversion specifications into a struct
	specs including any options like flag, width, precision, the conversion
	specifier or the next regular character if the specifier is missing, and
	the number of characters read by the parser. The invalid flags are switched
	off by the function clean_formatspec().
	PARAMETER(S)
		The format string to control the output starting at the '%' symbol
	RETURN
	The function returns the t_specs struct that holds the information of the
	conversion specification and the number of characters read from format.
*/

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
			specs->star_precis = 0;
			specs->n_chars += 1;
			format++;
		}
		else
		{
			if (*format == '-')
			{
				specs->precis = 0;
				format = read_flags(format, specs);
				specs->width = ft_atoi_digits(format);
			}
			else
				specs->precis = ft_atoi_digits(format);
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
			specs->star_precis = 0;
			specs->n_chars += 1;
			format++;
		}
		else
		{
			specs->precis = ft_atoi_digits(format);
			specs->n_chars += ft_nbrlen(format);
			format += ft_nbrlen(format);
		}
	}
	return (format);
}

#endif

void	update_formatspecs(t_specs *specs, const char **format, va_list *args)
{
	reset_formatspecs(specs);
	(*format)++;
	*format = read_flags(*format, specs);
	*format = read_width(*format, specs);
	*format = read_precision(*format, specs);
	if (**format)
	{
		specs->specif = **format;
		specs->n_chars += 1;
		(*format)++;
	}
	clean_formatspecs(specs);
	if (specs->star_width == 0)
	{
		specs->width = va_arg(*args, int);
		if (specs->width == INT_MIN)
			specs->width++;
		if (specs->width < 0)
		{
			specs->width = -specs->width;
			specs->dash = 1;
		}
	}
	if (specs->star_precis == 0)
		specs->precis = (long)va_arg(*args, int);
}
