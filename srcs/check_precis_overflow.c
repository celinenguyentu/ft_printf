/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precis_overflow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:50:57 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 01:55:42 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	check_precis_overflow(long precis, int arg_len)
{
	if (precis > INT_MAX)
	{
		if (precis - arg_len > INT_MAX)
			return (-1);
		else
			return (precis - arg_len);
	}
	return (precis);
}
