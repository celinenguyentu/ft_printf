/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/18 17:02:40 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_uint(unsigned long n, int base)
{
	static char	*low_hexadecimal = "0123456789abcdef";
	static char	*up_hexadecimal = "0123456789ABCDEF";

	if (base == 'x' && n < 16)
		return (ft_putchar(low_hexadecimal[n]));
	else if (base == 'X' && n < 16)
		return (ft_putchar(up_hexadecimal[n]));
	else if (base != 'x' && base != 'X' && n < (unsigned long)base)
		return (ft_putchar(up_hexadecimal[n]));
	else if (base == 'x')
		return (put_uint(n / 16, 'x') + put_uint(n % 16, 'x'));
	else if (base == 'X')
		return (put_uint(n / 16, 'X') + put_uint(n % 16, 'X'));
	else
		return (put_uint(n / base, base) + put_uint(n % base, base));
}

int	uint_len(unsigned long n, int base)
{
	if (n < (unsigned long)base)
		return (1);
	else
		return (uint_len(n / base, base) + uint_len(n % base, base));
}

int	print_ptr(t_formatspec specs, va_list *args)
{
	int			n_chars;
	uintptr_t	address;
	int			output_len;

	n_chars = 0;
	fetch_next_args(&specs, args);
	address = (unsigned long int)va_arg(*args, void *);
	if (address)
		output_len = uint_len(address, 16) + 2;
	else
		output_len = ft_strlen(NULLPTR);
	while (specs.flags.dash == 0 && n_chars < specs.width - output_len)
		n_chars += ft_putchar(' ');
	if (address)
	{
		n_chars += ft_putstr("0x");
		n_chars += put_uint(address, 'x');
	}
	else
		n_chars += ft_putstr(NULLPTR);
	while (specs.flags.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

int	print_intprefix(t_formatspec specs, int uarg_len, int negative)
{
	int	n_chars;
	int	n_zeros;
	int	offset;

	n_chars = 0;
	n_zeros = 0;
	if (specs.precision && uarg_len < specs.precision_n)
		n_zeros = specs.precision_n - uarg_len;
	offset = uarg_len + negative + n_zeros;
	if (!negative && (specs.flags.blank || specs.flags.plus))
		offset += 1;
	if (!specs.flags.dash && !specs.flags.zero)
	{
		while (specs.width - offset > n_chars)
			n_chars += ft_putchar(' ');
	}
	if (negative)
		n_chars += ft_putchar('-');
	if (!negative && specs.flags.blank)
		n_chars += ft_putchar(' ');
	if (!negative && specs.flags.plus)
		n_chars += ft_putchar('+');
	while ((specs.flags.zero && specs.width - uarg_len > n_chars) || n_zeros--)
		n_chars += ft_putchar('0');
	return (n_chars);
}

int	print_int(t_formatspec specs, va_list *args)
{
	int		n_chars;
	long	arg;
	int		uarg_len;
	int		negative;

	n_chars = 0;
	fetch_next_args(&specs, args);
	arg = (long)va_arg(*args, int);
	negative = (arg < 0);
	if (negative)
		arg *= -1;
	uarg_len = uint_len(arg, 10);
	n_chars += print_intprefix(specs, uarg_len, negative);
	if (arg != 0 || !specs.precision || specs.precision_n != 0)
		n_chars += put_uint(arg, 10);
	while (specs.flags.dash == 1 && specs.width - n_chars > 0)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

int	print_uint(t_formatspec specs, va_list *args)
{
	int					n_chars;
	unsigned long int	arg;
	int					arg_len;
	int					n_zeros;

	n_chars = 0;
	fetch_next_args(&specs, args);
	arg = (unsigned long int)va_arg(*args, unsigned int);
	arg_len = uint_len(arg, 10);
	n_zeros = 0;
	if (specs.precision && arg_len < specs.precision_n)
		n_zeros = specs.precision_n - arg_len;
	if (!specs.flags.dash && !specs.flags.zero)
	{
		while (specs.width - arg_len - n_zeros > n_chars)
			n_chars += ft_putchar(' ');
	}
	while ((specs.flags.zero && specs.width - arg_len > n_chars) || n_zeros--)
		n_chars += ft_putchar('0');
	if (arg != 0 || !specs.precision || specs.precision_n != 0)
		n_chars += put_uint(arg, 10);
	while (specs.flags.dash == 1 && specs.width - n_chars > 0)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

int	print_xint(t_formatspec specs, va_list *args)
{
	int					n_chars;
	unsigned long int	arg;
	int					arg_len;
	int					n_zeros;

	n_chars = 0;
	fetch_next_args(&specs, args);
	arg = (unsigned long int)va_arg(*args, unsigned int);
	arg_len = uint_len(arg, 16);
	n_zeros = 0;
	if (specs.precision && arg_len < specs.precision_n)
		n_zeros = specs.precision_n - arg_len;
	if (!specs.flags.dash && !specs.flags.zero)
	{
		while (specs.width - arg_len - n_zeros - 2 * specs.flags.hash * (arg > 0) > n_chars)
			n_chars += ft_putchar(' ');
	}
	if (specs.flags.hash && arg != 0)
		n_chars += ft_putchar('0') + ft_putchar(specs.specifier);
	while ((specs.flags.zero && specs.width - arg_len > n_chars) || n_zeros--)
		n_chars += ft_putchar('0');
	if (arg != 0 || !specs.precision || specs.precision_n != 0)
		n_chars += put_uint(arg, specs.specifier);
	while (specs.flags.dash == 1 && specs.width - n_chars > 0)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#if	defined(__APPLE__)

int	ft_vprintf(const char *format, va_list ap)
{
	int				n_chars;
	t_formatspec	specs;

	n_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			specs = get_formatspec(format);
			format += specs.n_chars;
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
	int				n_chars;
	t_formatspec	specs;

	n_chars = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			specs = get_formatspec(format);
			if (specs.specifier)
			{
				format += specs.n_chars;
				n_chars += print_arg(specs, &ap);
			}
			else
				n_chars += ft_putchar('%');
		}
		else if (*format == '%')
			return (-1);
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
