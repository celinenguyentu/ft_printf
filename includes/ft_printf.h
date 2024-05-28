/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:33 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/28 15:53:22 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/libft.h"

# define SPECIFIERS "cspdiuxX%o"
# define FLAGS "-0# +"
# define LOWHEXADECIMAL "0123456789abcdef"
# define UPHEXADECIMAL "0123456789ABCDEF"
# define DECIMAL "0123456789"
# define OCTAL "01234567"

typedef struct s_specs
{
	int		dash; // true 1 or false 0
	int		zero; // true 1 or false 0
	int		hash; // true 1 or false 0
	int		blank; // true 1 or false 0
	int		plus; // true 1 or false 0 
	int		star_width; // -1 none, 0 next arg
	int		width; // negative overflow, 0 none, 1, 2, 3, 4 ... value
	int		star_precis; // -1 none, 0 next arg
	long	precis; // - 1 none, 0, 1, 2, 3... value
	char	specif; // c, s, p, d, i, u, x, X, %, o, unknown
	int		n_chars;
	int		n_unknowns;
}	t_specs;

// ft_printf
int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		print_arg(t_specs specs, va_list *args, int n_chars);
ssize_t	print_char(t_specs specs, va_list *args);
ssize_t	print_str(t_specs specs, va_list *args);
ssize_t	print_ptr(t_specs specs, va_list *args);
ssize_t	print_int(t_specs specs, va_list *args);
ssize_t	print_uint(t_specs specs, va_list *args, int baselen);
ssize_t	print_percent(t_specs specs, va_list *args);
ssize_t	print_unknown(t_specs specs, va_list *args);
ssize_t	print_intprefix(t_specs specs, int uarg_len, int sign);
long	check_precis_overflow(long precis, int arg_len);
int		check(ssize_t *n_chars, ssize_t bytes_written);

// formatspec
void	init_formatspecs(t_specs *specs);
void	reset_formatspecs(t_specs *specs);
void	update_formatspecs(t_specs *specs, const char **format);
void	clean_formatspecs(t_specs *specs);
void	fetch_star_args(t_specs *specs, va_list *args);

// Utility functions
ssize_t	ft_putchar(unsigned char c);
ssize_t	ft_putnchar(unsigned char c, ssize_t n);
ssize_t	ft_putnstr(const char *str, size_t n);
long	ft_atoi_digits(const char *str);
int		ft_nbrlen(const char *str);
ssize_t	ft_putuint(unsigned long int n, int base);
size_t	ft_uintlen(unsigned long int n, int base);

#endif