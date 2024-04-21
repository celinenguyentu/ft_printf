/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formatspec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:36:29 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 20:02:49 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_specs	get_formatspec(const char *format)
{
	t_specs	specs;

	init_formatspec(&specs);
	format++;
	if (*format)
	{
		specs.specifier = *format;
		specs.n_chars += 1;
	}
	return (specs);
}
