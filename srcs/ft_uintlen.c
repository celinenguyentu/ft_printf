/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:08:20 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/18 21:09:00 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uintlen(unsigned long n, int base)
{
	if (n < (unsigned long)base)
		return (1);
	else
		return (ft_uintlen(n / base, base) + ft_uintlen(n % base, base));
}
