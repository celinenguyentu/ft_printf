/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formatspec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:36:29 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/30 00:46:33 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	GET_FORMATSPEC
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
