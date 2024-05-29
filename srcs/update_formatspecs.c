/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_formatspecs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:36:29 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/29 03:51:54 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	UPDATE_FORMATSPECS
	Parses the initial portion of the format string from the percent symbol '%'
	to either a specifier or an unknown character, excluding optional flags,
	width and precision. It stores the conversion specifications into a struct
	specs including the conversion specifier or the next regular character if
	the specifier is missing, and the number of characters read by the parser.
	PARAMETER(S)
		The format string to control the output starting at the '%' symbol
	RETURN
	The function returns the t_specs struct that holds the information of the
	conversion specification and the number of characters read from format.
*/

void	update_formatspecs(t_specs *specs, const char **format, va_list *args)
{
	(void)args;
	reset_formatspecs(specs);
	(*format)++;
	if (**format)
	{
		specs->specif = **format;
		specs->n_chars += 1;
		(*format)++;
	}
}
