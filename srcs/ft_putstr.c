/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:12:42 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/29 22:33:39 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_PUTSTR
	Writes the string str to the standard output stream.
	PARAMETER(S)
		The string str of type char * to be printed.
	RETURN
	The function returns the length of the string printed in stdout, as an int.
	EXAMPLES
		ft_putstr("Hello World!") outputs "Hello World!" and returns 12
		ft_putstr("") outputs "" and returns 0
*/

int	ft_putstr(char *str)
{
	int	length;

	length = 0;
	while (*str)
		length += ft_putchar(*str++);
	return (length);
}
