/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:48:42 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/15 07:48:36 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(const char *str)
{
	int	count;

	count = 0;
	while (ft_isdigit(*str))
	{
		count++;
		str++;
	}
	return (count);
}
