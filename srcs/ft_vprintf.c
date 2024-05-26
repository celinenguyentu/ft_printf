/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:15:44 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 17:35:19 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PUT_TEXT
	Outputs consecutive regular characters of format and increments the
	pointer pointing to it.
	PARAMETER(S)
	1/	A pointer to the string to print
	2/	The number of characters already printed
	RETURN
	The updated number of characters printed.
*/

static int	put_text(const char **format, int n_chars)
{
	long	len;

	len = 0;
	while ((*format)[len] && (*format)[len] != '%')
	{
		len++;
		if (n_chars + len < 0)
			return (-1);
	}
	write(1, *format, len);
	*format += len;
	return (n_chars + len);
}

/*
	FLAGS_OVERFLOW
	Detects an overflow due to width or precision.
	PARAMETER(S)
	1/	Format specifier containing width and precision infos.
	2/	Number of characters already printed.
	RETURN
	The function returns 1 if an overflow occured, otherwise it returns 0.

	FT_VPRINTF
	The function ft_vprintf() is equivalent to the function ft_printf() except
	that it is called with a va_list instead of a variable number of arguments.
	PARAMETER(S)
	1.	The format string to control the output
	2.	The va_list storing the variable-length list of arguments used and
		converted for output
	RETURN
	The function returns the number of characters printed in the standard
	output, excluding the null-terminating '\0' character of the format string.
	In case of error or overflow, it returns -1.
*/

#if defined(__APPLE__)

static int	flags_overflow(t_specs specs, int n_chars)
{
	if (specs.width < 0 || specs.width + n_chars >= INT_MAX)
		return (1);
	if (specs.precis < -1)
		return (1);
	if (ft_strchr("pdiuxXo", specs.specif) && specs.precis > 0
		&& specs.precis <= INT_MAX && specs.precis + n_chars >= INT_MAX)
		return (1);
	return (0);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int		n_chars;
	t_specs	fs;
	va_list	ap_;

	n_chars = 0;
	init_formatspecs(&fs);
	va_copy(ap_, ap);
	while (*format)
	{
		if (*format == '%')
		{
			update_formatspecs(&specs, &format);
			if (flags_overflow(fs, n_chars))
				return (-1);
			if (specs.specif == '\0')
				return (n_chars);
			n_chars += print_arg(fs, &ap_);
		}
		else
			n_chars = put_text(&format, n_chars);
		if (n_chars < 0)
			return (-1);
	}
	va_end(ap_);
	return (n_chars);
}

#else

static int	check_formatspecs_error(t_specs *specs)
{
	if (specs->width < 0 || specs->width > INT_MAX)
		return (1);
	if (specs->precis < -1)
		return (1);
	if (ft_strchr("spdiuxXo", specs->specif) && specs->precis > 0
		&& specs->precis > INT_MAX)
		return (1);
	if (specs->specif && !ft_strchr(SPECIFIERS, specs->specif))
		(specs->n_unknowns)++;
	if (!specs->specif && specs->n_unknowns == 0)
		return (1);
	return (0);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int		n_chars;
	t_specs	specs;
	va_list	ap_;

	n_chars = 0;
	init_formatspecs(&specs);
	va_copy(ap_, ap);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			update_formatspecs(&specs, &format);
			if (check_formatspecs_error(&specs))
				return (-1);
			n_chars += print_arg(specs, &ap_);
		}
		else
			n_chars = put_text(&format, n_chars);
		if (n_chars < 0)
			return (-1);
	}
	va_end(ap_);
	return (n_chars);
}

#endif
