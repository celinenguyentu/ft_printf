/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_formatspec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:14:06 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/29 20:52:11 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	CLEAN_FORMATSPEC
	Switch off the flags that are not applicable to the conversion specification
	represented by specs according to overriding rules and conversion specifiers.
	PARAMETER(S)
		The address of the t_specs struct that holds information about
		a conversion specification.
	RETURN VALUE
	-
*/

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
