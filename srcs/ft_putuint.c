/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:00:12 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/18 21:17:52 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned long n, int base)
{
	if (base == 'x' && n < 16)
		return (ft_putchar(LOWHEXADECIMAL[n]));
	else if (base == 'X' && n < 16)
		return (ft_putchar(UPHEXADECIMAL[n]));
	else if (base != 'x' && base != 'X' && n < (unsigned long)base)
		return (ft_putchar(DECIMAL[n]));
	else if (base == 'x')
		return (ft_putuint(n / 16, 'x') + ft_putuint(n % 16, 'x'));
	else if (base == 'X')
		return (ft_putuint(n / 16, 'X') + ft_putuint(n % 16, 'X'));
	else
		return (ft_putuint(n / base, base) + ft_putuint(n % base, base));
}
