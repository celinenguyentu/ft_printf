/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_formatspec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:14:06 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/21 19:48:58 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_formatspec(t_specs *specs)
{
	if (specs->dash == 1 && specs->zero == 1)
		specs->zero = 0;
	if (specs->plus == 1 && specs->blank == 1)
		specs->blank = 0;
	if (specs->specifier && ft_strchr(SPECIFIERS, specs->specifier))
	{
		if (!ft_strchr("xX", specs->specifier))
			specs->hash = 0;
		if (!ft_strchr("di", specs->specifier))
		{
			specs->blank = 0;
			specs->plus = 0;
		}
		if (ft_strchr("diuxX", specs->specifier) && specs->precision > -1)
			specs->zero = 0;
	}
}
