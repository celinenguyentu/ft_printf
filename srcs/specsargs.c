/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specsargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:54:06 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/16 04:54:20 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fetch_next_args(t_formatspec *specs, va_list *args)
{
	if (specs->width == -1)
		specs->width = va_arg(*args, int);
	if (specs->width < 0)
	{
		specs->width = -specs->width;
		specs->flags.dash = 1;
		if (specs->flags.zero == 1)
			specs->flags.zero = 0;
	}
	if (specs->precision && specs->precision_n == -1)
		specs->precision_n = va_arg(*args, int);
	if (specs->precision && specs->precision_n < 0)
		specs->precision = 0;
}
