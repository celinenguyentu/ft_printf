/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_formatspec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:40:16 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/18 14:40:31 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_formatspec(t_formatspec *specs)
{
	specs->flags = (t_flags){0, 0, 0, 0, 0};
	specs->width = 0;
	specs->precision = 0;
	specs->precision_n = 0;
	specs->specifier = 0;
	specs->n_chars = 0;
}
