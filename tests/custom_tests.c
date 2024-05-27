/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:39:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/27 15:47:58 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "ft_printf.h"

int	main(void)
{
	int read;
	char *s = "hello";
	long	n = (long)INT_MAX + 200;
	int		bytes = n;
	

	read = ft_putuint(1234567890, 'x', 8);
	printf("\t(%d)\n", read);

	return (0);
}
// ft_printf("dlsjfsdfd(%2147483647d)\n", n);