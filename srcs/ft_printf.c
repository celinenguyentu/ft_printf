/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/25 01:21:20 by cnguyen-         ###   ########.fr       */
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
	In case of error, it returns -1.
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
			if (fs.width < 0 || fs.precis < -1 || fs.width + n_chars < 0)
				return (-1);
			format += fs.n_chars;
			n_chars += print_arg(fs, &ap_);
		}
		else
			n_chars += ft_putchar(*format);
		format++;
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
