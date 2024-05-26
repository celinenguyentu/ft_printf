/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:40:49 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 14:41:34 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	switch_to_x(t_specs *specs)
{
	specs->hash = 1;
	specs->specif = 'x';
	if (specs->precis > -1)
		specs->zero = 0;
}
/*
	PRINT_PTR
	Retrieves the pointer argument to convert for output from the va_list args
	as well as optional arguments specifying width and precision, and prints
	the formatted argument to standart output according to the conversion
	specification provided as input and potentially updated by
	fetch_star_args() and clean_formatspec().
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN
	The number of characters printed as a long.
*/

#if defined(__APPLE__)

long	print_ptr(t_specs specs, va_list *args)
{
	long		n_chars;
	uintptr_t	arg;
	int			arg_len;

	fetch_star_args(&specs, args);
	clean_formatspec(&specs);
	n_chars = 0;
	arg = (unsigned long int)va_arg(*args, void *);
	arg_len = ft_uintlen(arg, 16);
	if (arg == 0 && specs.precis == 0)
		arg_len = 0;
	specs.precis = check_precis_overflow(specs.precis, arg_len);
	switch_to_x(&specs);
	specs.blank = 0;
	specs.plus = 0;
	n_chars += print_intprefix(specs, arg_len, 1);
	if (arg || specs.precis != 0)
		n_chars += ft_putuint(arg, 'x');
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#else

long	print_ptr(t_specs specs, va_list *args)
{
	long		n_chars;
	uintptr_t	arg;
	int			arg_len;

	fetch_star_args(&specs, args);
	clean_formatspec(&specs);
	n_chars = 0;
	arg = (unsigned long int)va_arg(*args, void *);
	if (arg)
	{
		arg_len = ft_uintlen(arg, 16);
		switch_to_x(&specs);
		n_chars += print_intprefix(specs, arg_len, 1);
		n_chars += ft_putuint(arg, 'x');
	}
	else
	{
		arg_len = ft_strlen("(nil)");
		while (specs.dash == 0 && n_chars < specs.width - arg_len)
			n_chars += ft_putchar(' ');
		n_chars += ft_putstr("(nil)");
	}
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}

#endif
