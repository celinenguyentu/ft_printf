/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:00:12 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/27 16:47:23 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_PUTUINT
	Writes the unsigned decimal integer n to the standard output stream. The
	integer is converted to the base specified before printing.
	PARAMETER(S)
	1.	The unsigned decimal integer of type unsigned long to be printed.
	2.	The base of type int representing a char in which to print the integer.
		- 'd', 'i', 'u' : decimal base
		- 'x', 'X' : hexadecimal base with resp. lower and upper case letters
		- 'o' : octal base
		Any other base is undefined behaviour.
	RETURN
	The function returns the number of characters printed representing the
	number in the specified base. If an error occured, it returns -1.
	EXAMPLES
		ft_putuint(42, 'i') outputs "42" and returns 2
		ft_putuint(0, 'o') outputs "0" and returns 1
		ft_putuint(2024, 'x') outputs "7e8" and returns 3
*/

static void	fill_uint(char *buffer, unsigned long n, int base, int uint_len);

static void	fill_uint_digit(char *buffer, unsigned long n, int base, int uint_len)
{
	int	operand;

	if (base == 'x' || base == 'X')
		operand = 16;
	else if (base == 'o')
		operand = 8;
	else
		operand = 10;
	fill_uint(buffer, n / operand, base, uint_len);
	fill_uint(buffer, n % operand, base, uint_len);
}

static void	fill_uint(char *buffer, unsigned long n, int base, int uint_len)
{
	static int	idx = 0;

	if (base == 'x' && n < 16)
		buffer[idx++] = LOWHEXADECIMAL[n];
	else if (base == 'X' && n < 16)
		buffer[idx++] = UPHEXADECIMAL[n];
	else if (base == 'o' && n < 8)
		buffer[idx++] = OCTAL[n];
	else if (base && ft_strchr("diu", base) && n < 10)
		buffer[idx++] = DECIMAL[n];
	else if (base == 'x')
		fill_uint_digit(buffer, n, base, uint_len);
	else if (base == 'X')
		fill_uint_digit(buffer, n, base, uint_len);
	else if (base == 'o')
		fill_uint_digit(buffer, n, base, uint_len);
	else if (base && ft_strchr("diu", base))
		fill_uint_digit(buffer, n, base, uint_len);
	if (idx == uint_len)
		idx = 0;
}

ssize_t	ft_putuint(unsigned long int n, int base)
{
	char	*buffer;
	ssize_t	bytes_written;
	int		uint_len;

	if (base == 'x' || base == 'X')
		uint_len = ft_uintlen(n, 16);
	else if (base == 'o')
		uint_len = ft_uintlen(n, 8);
	else
		uint_len = ft_uintlen(n, 10);
	buffer = (char *)malloc(uint_len * sizeof(char));
	if (!buffer)
		return (-1);
	bytes_written = 0;
	fill_uint(buffer, n, base, uint_len);
	bytes_written = write(STDOUT_FILENO, buffer, uint_len);
	free(buffer);
	return (bytes_written);
}

/* SAVE
ssize_t	ft_putuint(unsigned long int n, int base)
{
	if (base == 'x' && n < 16)
		return (ft_putchar(LOWHEXADECIMAL[n]));
	else if (base == 'X' && n < 16)
		return (ft_putchar(UPHEXADECIMAL[n]));
	else if (base == 'o' && n < 8)
		return (ft_putchar(OCTAL[n]));
	else if (base && ft_strchr("diu", base) && n < 10)
		return (ft_putchar(DECIMAL[n]));
	else if (base == 'x')
		return (ft_putuint(n / 16, 'x') + ft_putuint(n % 16, 'x'));
	else if (base == 'X')
		return (ft_putuint(n / 16, 'X') + ft_putuint(n % 16, 'X'));
	else if (base == 'o')
		return (ft_putuint(n / 8, 'o') + ft_putuint(n % 8, 'o'));
	else if (base && ft_strchr("diu", base))
		return (ft_putuint(n / 10, 'd') + ft_putuint(n % 10, 'd'));
	else
		return (0);
}
*/