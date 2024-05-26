/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intprefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:18:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 03:26:37 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_INTPREFIX
	Prints the formatted prefix to an integer argument to the standart output
	according to the conversion specification provided as input. It handles
	left-padding, either by blanks or zeros, '-' and '+' signs and specific
	prefix given by the flag '#'.
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options
	2.	The length of the integer argument to be printed excluding the 
		negative sign '-' in case of negative integer
	3.	The sign of the integer argument : -1 for negative, 0 for nul, 
		1 for positive
	RETURN
	The number of characters printed as a long.
*/

long	print_intprefix(t_specs specs, int uarg_len, int sign)
{
	long	n_chars;
	int		n_zeros;
	long	offset;

	n_chars = 0;
	n_zeros = 0;
	if (specs.precis > -1 && uarg_len < specs.precis)
		n_zeros = specs.precis - uarg_len;
	offset = (sign == -1 || specs.blank || specs.plus) + uarg_len + n_zeros;
	offset += (ft_strchr("xX", specs.specif) && specs.hash && sign != 0) * 2;
	while (!specs.dash && !specs.zero && n_chars < specs.width - offset)
		n_chars += ft_putchar(' ');
	if (sign == -1)
		n_chars += ft_putchar('-');
	if (sign > -1 && specs.blank)
		n_chars += ft_putchar(' ');
	if (sign > -1 && specs.plus)
		n_chars += ft_putchar('+');
	if (ft_strchr("xX", specs.specif) && specs.hash && sign != 0)
		n_chars += ft_putchar('0') + ft_putchar(specs.specif);
	if (specs.specif == 'o' && specs.hash && (sign != 0 || specs.precis == 0))
		n_chars += ft_putchar('0');
	while ((specs.zero && n_chars < (specs.width - uarg_len)) || n_zeros--)
		n_chars += ft_putchar('0');
	return (n_chars);
}
