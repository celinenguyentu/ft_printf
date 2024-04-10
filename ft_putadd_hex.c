/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:08:40 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/10 09:34:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_hexlow_fd(long unsigned int n, int fd)
{
	static char	*hexadecimal = "0123456789abcdef";
	
	if (n > 15)
		ft_putnbr_hexlow_fd(n / 16, fd);
	ft_putchar_fd(hexadecimal[n % 16], fd);
}

void	ft_putnbr_hexup_fd(long unsigned int n, int fd)
{
	static char	*hexadecimal = "0123456789ABCDEF";
	
	if (n > 15)
		ft_putnbr_hexup_fd(n / 16, fd);
	ft_putchar_fd(hexadecimal[n % 16], fd);
}

void	ft_putadd_hex_fd(void *ptr, int fd)
{
	uintptr_t	add;

	add = (unsigned long int)ptr;
	ft_putstr_fd("0x", fd);
	ft_putnbr_hexlow_fd(add, fd);
}