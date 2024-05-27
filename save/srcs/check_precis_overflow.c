/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precis_overflow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:50:57 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 03:23:08 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	CHECK_PRECIS_OVERFLOW
	Changes precision when it is bigger than INT_MAX.
	PARAMETER(S)
	1/	The initial precision
	2/	The length of the argument that should be printed.
	RETURN VALUE
	The function returns the new precision after overflow check.
*/

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
