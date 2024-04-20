/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_formatspec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:40:16 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 02:47:22 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_formatspec(t_formatspec *specs)
{
	specs->dash = 0;
	specs->zero = 0;
	specs->hash = 0;
	specs->blank = 0;
	specs->plus = 0;
	specs->star_width = -1;
	specs->width = 0;
	specs->star_precision = -1;
	specs->precision = -1;
	specs->specifier = 0;
	specs->n_chars = 0;
}
