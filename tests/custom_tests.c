/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:39:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/27 17:10:50 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "ft_printf.h"

int	main(void)
{
	int		bytes_read;
	char 	*s = "hello";
	int		n = 42;

	bytes_read = ft_printf("%2147483647d", n);
	printf("\t(%d)\n", bytes_read);
	return (0);
}