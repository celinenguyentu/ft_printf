/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/16 04:54:58 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_formatspec specs, va_list *args)
{
	int		n_chars;
	char	arg;

	n_chars = 0;
	fetch_next_args(&specs, args);
	arg = va_arg(*args, int);
	if (specs.flags.dash == 1)
		n_chars += ft_putchar(arg);
	while (specs.width - 1 > 0)
	{
		n_chars += ft_putchar(' ');
		specs.width--;
	}
	if (specs.flags.dash == 0)
		n_chars += ft_putchar(arg);
	return (n_chars);
}

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
	if (specs.precision && strlen > specs.precision_n)
		strlen = specs.precision_n;
	while (specs.flags.dash == 0 && specs.width - strlen > n_chars)
		n_chars += ft_putchar(' ');
	offset = n_chars;
	while (*str && n_chars - offset < strlen)
		n_chars += ft_putchar(*str++);
	while (specs.flags.dash == 1 && specs.width - n_chars > 0)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

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
	output_len = uint_len(address, 16) + 2;
	if (specs.flags.dash == 1)
	{
		n_chars += ft_putstr("0x");
		n_chars += put_uint(address, 'x');
	}
	while (specs.width - output_len > 0)
	{
		n_chars += ft_putchar(' ');
		specs.width--;
	}
	if (specs.flags.dash == 0)
	{
		n_chars += ft_putstr("0x");
		n_chars += put_uint(address, 'x');
	}
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

int	print_arg(t_formatspec specs, va_list *args)
{
	int	n_chars;

	n_chars = 0;
	if (specs.specifier == 'c')
		n_chars += print_char(specs, args);
	else if (specs.specifier == 's')
		n_chars += print_str(specs, args);
	else if (specs.specifier == 'p')
		n_chars += print_ptr(specs, args);
	else if (specs.specifier == 'd' || specs.specifier == 'i')
		n_chars += print_int(specs, args);
	else if (specs.specifier == 'u')
		n_chars += print_uint(specs, args);
	else if (specs.specifier == 'x' || specs.specifier == 'X')
		n_chars += print_xint(specs, args);
	else if (specs.specifier == '%')
		n_chars += ft_putchar('%');
	return (n_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				n_chars;
	t_formatspec	specs;

	va_start(args, format);
	n_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			specs = get_formatspec(format);
			format += specs.n_chars;
			n_chars += print_arg(specs, &args);
		}
		else
			n_chars += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (n_chars);
}
