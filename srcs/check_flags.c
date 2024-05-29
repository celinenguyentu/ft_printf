/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:33:54 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/29 18:36:01 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#if defined(__APPLE__)

int	check_flags(t_specs *specs, int n_chars)
{
	if (specs->width < 0 || specs->width + n_chars == INT_MAX)
		return (0);
	if (specs->width + n_chars < 0)
		return (0);
	if (specs->star_precis == -1 && specs->precis < -1)
		return (0);
	if (ft_strchr("pdiuxXo", specs->specif) && specs->precis > 0
		&& specs->precis <= INT_MAX && specs->precis + n_chars >= INT_MAX)
		return (0);
	if (ft_strchr("pdiuxXo", specs->specif) && specs->star_precis == 0
		&& specs->precis <= (long)INT_MIN - 1)
	{
		if (specs->precis + n_chars >= (long)INT_MIN - 1)
			return (0);
		specs->precis = (int)specs->precis + n_chars;
	}
	return (1);
}

#endif