/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 03:28:07 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_PRINTF
	Formats and prints in the standard ouput its arguments, after the first,
	under control of the string format. The format string may contain format
	specifications, each of which causes printing of the next successive
	argument. Each format specification is introduced by the percent character
	'%' followed by, in the following order :
	- Zero or more flags among the following : "#0- +"
	- An optional digit string specifying a field width
	- An optional period '.' followed by an optional digit string giving a 
	precision.
	- A format specifier of type char which indicates the type of format to use
	among the following : "cspdiuxX%o"
	A field width or precision may be ‘*’ instead of a digit string. In this
	case an argument supplies the field width or precision.
	PARAMETER(S)
	1.	The format string to control the output
	2.	A variable number of arguments used and converted for output
	RETURN
	The function returns the number of characters printed in the standard
	output, excluding the null-terminating '\0' character of the format string.
	In case of error, it returns -1.
*/

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n_chars;

	va_start(ap, format);
	n_chars = ft_vprintf(format, ap);
	va_end(ap);
	return (n_chars);
}

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

static size_t	put_text(const char **format, int n_chars)
{
	size_t	len;

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
*/

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

/*
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

int	ft_vprintf(const char *format, va_list ap)
{
	int		n_chars;
	t_specs	fs;
	va_list	ap_;

	n_chars = 0;
	init_formatspec(&fs);
	va_copy(ap_, ap);
	while (*format)
	{
		if (*format == '%')
		{
			fs = get_formatspec(format);
			if (flags_overflow(fs, n_chars))
				return (-1);
			format += fs.n_chars + 1;
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

int	ft_vprintf(const char *format, va_list ap)
{
	int		n_chars;
	t_specs	specs;
	int		n_unknowns;
	va_list	ap_;

	n_chars = 0;
	n_unknowns = 0;
	va_copy(ap_, ap);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			specs = get_formatspec(format);
			format += specs.n_chars;
			if (specs.specif && !ft_strchr(SPECIFIERS, specs.specif))
				n_unknowns++;
			if (!specs.specif && n_unknowns == 0)
				return (-1);
			n_chars += print_arg(specs, &ap_);
		}
		else
			n_chars += ft_putchar(*format);
		format++;
	}
	va_end(ap_);
	return (n_chars);
}

#endif
