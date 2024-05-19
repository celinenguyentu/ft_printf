/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:00:12 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/19 16:28:39 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_PUTUINT
	Writes the unsigned decimal integer n to the standard output stream. The
	integer is converted to the base specified before printing.
	PARAMETER(S)
	1.	The unsigned decimal integer of type unsigned long to be printed.
	2.	The base of type int representing a char in which to print the integer.
		- 'd', 'i', 'u' : decimal base
		- 'x', 'X' : hexadecimal base with resp. lower and upper case letters
		- 'o' : octal base
	RETURN
	The function returns the number of characters printed representing the
	number in the specified base. If the base is not valid, no character
	is printed and thus 0 is returned.
	EXAMPLES
		ft_putuint(42, 'i') outputs "42" and returns 2
		ft_putuint(0, 'o') outputs "0" and returns 1
		ft_putuint(2024, 'x') outputs "7e8" and returns 3
*/

int	ft_putuint(unsigned long int n, int base)
{
	if (base == 'x' && n < 16)
		return (ft_putchar(LOWHEXADECIMAL[n]));
	else if (base == 'X' && n < 16)
		return (ft_putchar(UPHEXADECIMAL[n]));
	else if (base == 'o' && n < 8)
		return (ft_putchar(OCTAL[n]));
	else if (base && ft_strchr("diu", base) && n < 10)
		return (ft_putchar(DECIMAL[n]));
	else if (base == 'x')
		return (ft_putuint(n / 16, 'x') + ft_putuint(n % 16, 'x'));
	else if (base == 'X')
		return (ft_putuint(n / 16, 'X') + ft_putuint(n % 16, 'X'));
	else if (base == 'o')
		return (ft_putuint(n / 8, 'o') + ft_putuint(n % 8, 'o'));
	else if (base && ft_strchr("diu", base))
		return (ft_putuint(n / 10, 'd') + ft_putuint(n % 10, 'd'));
	else
		return (0);
}
