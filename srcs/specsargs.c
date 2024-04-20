/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specsargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:54:06 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 03:10:28 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fetch_next_args(t_formatspec *specs, va_list *args)
{
	if (specs->star_width == 0)
		specs->width = va_arg(*args, int);
	if (specs->width < 0)
	{
		specs->width = -specs->width;
		specs->dash = 1;
		if (specs->zero == 1)
			specs->zero = 0;
	}
	if (specs->precision > -1 && specs->star_precision == 0)
	{
		specs->precision = va_arg(*args, int);
		if (specs->precision < 0)
			specs->precision = -1;
	}
}
