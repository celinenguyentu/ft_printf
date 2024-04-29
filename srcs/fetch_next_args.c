/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_next_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:54:06 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/29 21:51:40 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FETCH_NEXT_ARGS
	If required by the conversion specification, fetches and retrieves the next
	first arguments from the va_list args, corresponding to width and/or
	precision, which must be of type int. It accordingly updates the conversion
	specification specs and handles the case where those values are negative.
	PARAMETER(S)
	1.	The address of the t_specs struct that holds information about
		a conversion specification.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN VALUE
	-
*/

void	fetch_next_args(t_specs *specs, va_list *args)
{
	if (specs->star_width == 0)
		specs->width = va_arg(*args, int);
	if (specs->width < 0)
	{
		specs->width = -specs->width;
		specs->dash = 1;
	}
	if (specs->star_precision == 0)
	{
		specs->precision = va_arg(*args, int);
		if (specs->precision < 0)
			specs->precision = -1;
	}
}
